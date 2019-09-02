#pragma once

class DataReferenceBase
{
public:
	DataReferenceBase(
		HaloGameID gameID,
		size_t dataSize,
		size_t offset,
		intptr_t(find_offset_func)(HaloGameID gameID)
	)
		: m_gameID(gameID),
		m_dataSize(dataSize),
		m_offset(offset),
		m_pPtr(nullptr),
		m_pNextDataReference(nullptr),
		m_find_offset_func(find_offset_func)
	{
		if (g_pDataReferenceBaseBaseFirst == nullptr)
		{
			g_pDataReferenceBaseBaseFirst = this;
			g_pDataReferenceBaseBaseLast = this;
		}
		else
		{
			g_pDataReferenceBaseBaseLast->m_pNextDataReference = this;
			g_pDataReferenceBaseBaseLast = this;
		}

		if (gameID != HaloGameID::NotSet && IsHaloExecutableLoaded(gameID))
		{
			initNode(gameID);
		}
	}

protected:
	void* m_pPtr;
private:
	intptr_t(*m_find_offset_func)(HaloGameID gameID);
	HaloGameID m_gameID;
	size_t m_dataSize;
	size_t m_offset;
	static DataReferenceBase* g_pDataReferenceBaseBaseFirst;
	static DataReferenceBase* g_pDataReferenceBaseBaseLast;
	DataReferenceBase* m_pNextDataReference;

public:
	static void InitTree(HaloGameID gameID)
	{
		// this iteration avoids having to do this recursively

		DataReferenceBase* pCurrentDataReferenceBase = g_pDataReferenceBaseBaseFirst;
		while (pCurrentDataReferenceBase)
		{
			pCurrentDataReferenceBase = pCurrentDataReferenceBase->initNode(gameID);
		}
	}

	static void DeinitTree(HaloGameID gameID)
	{
		// this iteration avoids having to do this recursively

		DataReferenceBase* pCurrentDataReferenceBase = g_pDataReferenceBaseBaseFirst;
		while (pCurrentDataReferenceBase)
		{
			pCurrentDataReferenceBase = pCurrentDataReferenceBase->deinitNode(gameID);
		}
	}

private:

	DataReferenceBase* initNode(HaloGameID gameID)
	{
		if (m_pPtr == nullptr)
		{
			if (m_gameID == HaloGameID::NotSet)
			{
				assert(m_find_offset_func);
				m_pPtr = getPointer(gameID);
			}
			if (m_gameID == gameID)
			{
				m_pPtr = getPointer(gameID);
				assert(m_pPtr);
			}
		}
		return m_pNextDataReference;
	}
	DataReferenceBase* deinitNode(HaloGameID gameID)
	{
		if (m_pPtr == nullptr)
		{
			
		}
		return m_pNextDataReference;
	}

	void* getPointer(HaloGameID gameID)
	{
		size_t offset = m_offset;
		if (offset == 0 && m_find_offset_func)
		{
			offset = m_find_offset_func(gameID);

			assert(m_gameID == HaloGameID::NotSet && offset >= GetHaloBaseAddress(gameID)/*, "Offset is out of bounds"*/);
			assert(m_gameID == HaloGameID::NotSet && offset < GetHaloTopAddress(gameID)/*, "Offset is out of bounds"*/);
			assert(m_gameID == HaloGameID::NotSet && (offset + m_dataSize) < GetHaloTopAddress(gameID)/*, "Offset is out of bounds"*/);
		}

		HMODULE hModule = GetModuleHandleA(GetHaloExecutableString(gameID));
		char* pBaseAddress = reinterpret_cast<char*>(hModule);
		char* ptr = reinterpret_cast<char*>(pBaseAddress + (offset - GetHaloBaseAddress(gameID)));
		return ptr;
	}


};

template<HaloGameID gameid, typename T, size_t offset>
class BasicData : public DataReferenceBase
{
public:
	BasicData(const BasicData&) = delete;
	BasicData()
		: DataReferenceBase(gameid, sizeof(T), offset, nullptr)
	{

	}

	T* ptr() const
	{
		T* ptr = reinterpret_cast<T*>(m_pPtr);
		return ptr;
	}

	volatile T* volatile_ptr() const
	{
		return static_cast<volatile T*>(ptr());
	}

	T& PointerReference() const
	{
		return *ptr();
	}

	T* operator->()
	{
		return ptr();
	}

	T const* operator->() const
	{
		return ptr();
	}

	operator T& () const
	{
		return PointerReference();
	}

	operator bool() const
	{
		T& r = PointerReference();
		return (bool)r;
	}
};

template<HaloGameID gameid, typename T, size_t offset>
class Data : public DataReferenceBase
{
public:
	Data(const Data&) = delete;
	Data()
		: DataReferenceBase(gameid, sizeof(T), offset, nullptr)
	{

	}

	T* ptr() const
	{
		T* ptr = reinterpret_cast<T*>(m_pPtr);
		return ptr;
	}

	volatile T* volatile_ptr() const
	{
		return static_cast<volatile T*>(ptr());
	}

	T& PointerReference() const
	{
		return *ptr();
	}

	T& operator=(T value)
	{
		T& reference = PointerReference();
		reference = value;
		return reference;
	}

	T* operator->()
	{
		return ptr();
	}

	T const* operator->() const
	{
		return ptr();
	}

	operator T& () const
	{
		return PointerReference();
	}

	operator bool() const
	{
		T& r = PointerReference();
		return (bool)r;
	}
};

template<HaloGameID gameid, typename T, size_t offset>
class Pointer : public DataReferenceBase
{
public:
	Pointer(const Pointer&) = delete;
	Pointer()
		: DataReferenceBase(gameid, sizeof(T), offset, nullptr)
	{

	}

	volatile T volatile_ptr() const
	{
		return static_cast<volatile T>(impl_ref());
	}

	T operator->()
	{
		return impl_ref();
	}

	T ptr()
	{
		assert(m_pPtr != nullptr);
		return impl_ref();
	}

	T& ref()
	{
		assert(m_pPtr != nullptr);
		return impl_ref();
	}

	operator bool()
	{
		return !!this->operator->();
	}

protected:
	T& impl_ref() const
	{
		return *PointerToPointer();
	}

	T* PointerToPointer() const
	{
		T* ptr = reinterpret_cast<T*>(m_pPtr);
		return ptr;
	}
};

template<typename T, intptr_t(find_offset_func)(HaloGameID gameID)>
class BasicDataEx : public DataReferenceBase
{
public:
	BasicDataEx(const BasicDataEx&) = delete;
	BasicDataEx()
		: DataReferenceBase(HaloGameID::NotSet, sizeof(T), 0, find_offset_func)
	{

	}

	T* ptr() const
	{
		T* ptr = reinterpret_cast<T*>(m_pPtr);
		return ptr;
	}

	volatile T* volatile_ptr() const
	{
		return static_cast<volatile T*>(ptr());
	}

	T& PointerReference() const
	{
		return *ptr();
	}

	T* operator->()
	{
		return ptr();
	}

	T const* operator->() const
	{
		return ptr();
	}

	operator T& () const
	{
		return PointerReference();
	}

	operator bool() const
	{
		T& r = PointerReference();
		return (bool)r;
	}
};

template<typename T, intptr_t(find_offset_func)(HaloGameID gameID)>
class DataEx : public DataReferenceBase
{
public:
	DataEx(const DataEx&) = delete;
	DataEx()
		: DataReferenceBase(HaloGameID::NotSet, sizeof(T), 0, find_offset_func)
	{

	}

	T* ptr() const
	{
		T* ptr = reinterpret_cast<T*>(m_pPtr);
		return ptr;
	}

	volatile T* volatile_ptr() const
	{
		return static_cast<volatile T*>(ptr());
	}

	T& PointerReference() const
	{
		return *ptr();
	}

	T& operator=(T value)
	{
		T& reference = PointerReference();
		reference = value;
		return reference;
	}

	T* operator->()
	{
		return ptr();
	}

	T const* operator->() const
	{
		return ptr();
	}

	operator T& () const
	{
		return PointerReference();
	}

	operator bool() const
	{
		T& r = PointerReference();
		return (bool)r;
	}
};

template<typename T, intptr_t(find_offset_func)(HaloGameID gameID)>
class PointerEx : public DataReferenceBase
{
public:
	PointerEx(const PointerEx&) = delete;
	PointerEx()
		: DataReferenceBase(HaloGameID::NotSet, sizeof(T), 0, find_offset_func)
	{

	}

	T& Reference() const
	{
		return *PointerToPointer();
	}

	volatile T volatile_ptr() const
	{
		return static_cast<volatile T>(Reference());
	}

	T operator->()
	{
		return Reference();
	}

	operator bool() const
	{
		return !!this->operator->();
	}

	operator T& () const
	{
		return Reference();
	}

protected:
	T* PointerToPointer() const
	{
		T* ptr = reinterpret_cast<T*>(m_pPtr);
		return ptr;
	}
};

template<typename T, size_t offset>
using HaloReach_2019_Jun_24_Pointer = Pointer<HaloGameID::HaloReach_2019_Jun_24, T, offset>;

template<typename T, size_t offset>
using HaloReach_2019_Jun_24_BasicData = BasicData<HaloGameID::HaloReach_2019_Jun_24, T, offset>;

template<typename T, size_t offset>
using HaloReach_2019_Jun_24_Data = Data<HaloGameID::HaloReach_2019_Jun_24, T, offset>;