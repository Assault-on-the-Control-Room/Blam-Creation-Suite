#include "mantlelib-private-pch.h"


template<typename TagType>
inline const ReflectionType& GetTagReflectionData()
{
	return GetTagReflectionData(TagType::kTagGroupName);
}

template<typename T>
inline const ReflectionType& GetReflectionType(const T& member)
{
	return GetReflectionType<T>();
}

ImGuiDataType PrimitiveTypeToImGuiDataType(PrimitiveType primitiveType)
{
	switch (primitiveType)
	{
	case PrimitiveType::Int8:		return ImGuiDataType_S8;
	case PrimitiveType::Int16:		return ImGuiDataType_S16;
	case PrimitiveType::Int32:		return ImGuiDataType_S32;
	case PrimitiveType::Int64:		return ImGuiDataType_S64;
	case PrimitiveType::UInt8:		return ImGuiDataType_U8;
	case PrimitiveType::UInt16:		return ImGuiDataType_U16;
	case PrimitiveType::UInt32:		return ImGuiDataType_U32;
	case PrimitiveType::UInt64:		return ImGuiDataType_U64;
	case PrimitiveType::Float:		return ImGuiDataType_Float;
	case PrimitiveType::Double:		return ImGuiDataType_Double;
	case PrimitiveType::Boolean8:	return ImGuiDataType_S8;
	case PrimitiveType::Boolean16:	return ImGuiDataType_S16;
	case PrimitiveType::Boolean32:	return ImGuiDataType_S32;
	case PrimitiveType::Boolean64:	return ImGuiDataType_S64;
	case PrimitiveType::Enum8:		return ImGuiDataType_S8;
	case PrimitiveType::Enum16:		return ImGuiDataType_S16;
	case PrimitiveType::Enum32:		return ImGuiDataType_S32;
	case PrimitiveType::Enum64:		return ImGuiDataType_S64;
	}
	FATAL_ERROR("Unsupported primitive type");
}

ImVec2 DrawStructureSeparator(int recursionDepth, ImVec2* pTopScreenPos = nullptr)
{
	int recursionPadding = 25 * recursionDepth;

	ImVec2 screenPos = {};
	if (recursionDepth > 0)
	{
		constexpr float kHeight = 5.0f;

		ImGui::Columns(2, NULL, false);
		ImGui::SetColumnOffset(1, recursionPadding);
		ImGui::SetColumnWidth(1, 1230);
		ImGui::NextColumn(); // padding
		//ImGui::Separator();
		ImGui::Dummy(ImVec2(0.0f, kHeight));
		ImDrawList* draw_list = ImGui::GetWindowDrawList();
		screenPos = ImGui::GetCursorScreenPos();

		if (pTopScreenPos)
		{
			float heightBias = 6.0f;

			float left = screenPos.x - 6.0f;
			float right = left + 1230;
			float bottom = screenPos.y - heightBias;
			float top = pTopScreenPos->y - heightBias;

			ImVec2 upper_left = { left, top };
			ImVec2 lower_right = { right, bottom };

			draw_list->AddRect(upper_left, lower_right, IM_COL32(80, 80, 80, 40), 0.0f, 0, 2.0f);
		}
		ImGui::Columns(1);
	}
	return screenPos;
}

void PrintReflectionInfoGUI3(char* pData, const ReflectionType& reflectionData, int recursionDepth)
{
	int recursionPadding = 25 * recursionDepth;

	ImVec2 screenPosTop = DrawStructureSeparator(recursionDepth);

	for (size_t i = 0; i < reflectionData.m_count; i++)
	{
		const ReflectionField& reflectionField = reflectionData.m_members[i];

		bool unknownItemsVisible = MantleGUI::IsUnknownItemsVisible();
		if (!unknownItemsVisible && reflectionField.m_isHiddenByDefault)
		{
			// skip hidden fields
			continue;
		}

		const ReflectionTypeInfo& rTypeInfo = reflectionField.m_typeInfo;
		const char* pFieldDisplayName = reflectionField.m_pMemberNiceName;

		void* pFieldDataPointer = reinterpret_cast<int32_t*>(pData + reflectionField.m_offset);

		ImGui::PushID(pFieldDataPointer);

		if (!reflectionField.m_arraySize)
		{
			if (rTypeInfo.m_primitiveTypeIndex != PrimitiveType::Undefined)
			{
				const char* pFieldTypeName = PrimitiveTypeToString(rTypeInfo.m_primitiveTypeIndex);

				ImGui::Columns(3, NULL, false);
				ImGui::SetColumnOffset(1, recursionPadding);
				ImGui::SetColumnWidth(1, 400);
				ImGui::NextColumn(); // padding

				ImGui::Text(pFieldDisplayName);
				ImGui::NextColumn();
				ImGui::SetColumnWidth(2, 500);

				switch (rTypeInfo.m_primitiveTypeIndex)
				{
				case PrimitiveType::Int8:
				case PrimitiveType::Int16:
				case PrimitiveType::Int32:
				case PrimitiveType::Int64:
				case PrimitiveType::UInt8:
				case PrimitiveType::UInt16:
				case PrimitiveType::UInt32:
				case PrimitiveType::UInt64:
				case PrimitiveType::Float:
				case PrimitiveType::Double:
				case PrimitiveType::Boolean8:
				case PrimitiveType::Boolean16:
				case PrimitiveType::Boolean32:
				case PrimitiveType::Boolean64:
				case PrimitiveType::Enum8:
				case PrimitiveType::Enum16:
				case PrimitiveType::Enum32:
				case PrimitiveType::Enum64:
				{

					ImGuiDataType imguiDataType = PrimitiveTypeToImGuiDataType(rTypeInfo.m_primitiveTypeIndex);
					ImGui::InputScalar(pFieldTypeName, imguiDataType, pFieldDataPointer);
				}
				break;
				case PrimitiveType::BitField8:
				case PrimitiveType::BitField16:
				case PrimitiveType::BitField32:
				case PrimitiveType::BitField64:
				{
					// #TODO: This is absolutely horrible way to edit this data and we should write
					// an imgui scalar command that works with bitfields

					uint32_t* pFieldBitFieldDataPointer = static_cast<uint32_t*>(pFieldDataPointer);
					ImGui::Text("#BitField START");
					int bitfieldStart = 0;
					int bitfieldEnd = 1;
					for (int i = bitfieldStart; i < bitfieldEnd; i++)
					{
						int bitmask = 1 << i;
						ImGui::CheckboxFlags(pFieldTypeName, pFieldBitFieldDataPointer, bitmask);
					}
					ImGui::Text("#BitField END");
				}
				break;
				case PrimitiveType::BitFlag8:
				case PrimitiveType::BitFlag16:
				case PrimitiveType::BitFlag32:
				case PrimitiveType::BitFlag64:
				{
					uint32_t* pFieldBitFlagDataPointer = static_cast<uint32_t*>(pFieldDataPointer);
					int bitmask = 1; // #TODO: Get a correct bitmask
					ImGui::CheckboxFlags(pFieldTypeName, pFieldBitFlagDataPointer, bitmask);
				}
				break;
				}

				ImGui::Columns(1);
			}
			else if (rTypeInfo.m_reflectionTypeCategory == ReflectionTypeCategory::Structure)
			{
				const ReflectionStructureInfo& rReflectionStructureInfo = reflectionField.m_structureInfo;
				const ReflectionType& rStructureReflectionType = *rReflectionStructureInfo.m_pReflectionTypeInfo; //#TODO: Try to make this a reference in the type
				assert(&rStructureReflectionType);

				char* pStructureData = static_cast<char*>(pFieldDataPointer);
				PrintReflectionInfoGUI3(pStructureData, rStructureReflectionType, recursionDepth + 1);
			}
			else if (rTypeInfo.m_reflectionTypeCategory == ReflectionTypeCategory::TagReference)
			{
				ImGui::Columns(6, NULL, false);
				ImGui::SetColumnOffset(1, recursionPadding);
				ImGui::SetColumnWidth(1, 400);
				ImGui::SetColumnWidth(2, 150);
				ImGui::SetColumnWidth(3, 550);
				ImGui::SetColumnWidth(4, 65);
				ImGui::SetColumnWidth(5, 65);
				ImGui::NextColumn(); // padding

				ImGui::Text(pFieldDisplayName);
				ImGui::NextColumn();
				ImGui::PushItemWidth(-1);
				if (ImGui::BeginCombo("##tag_group_magic", "(null)"))
				{
					ImGui::EndCombo();
				}
				else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Select an entry from the dropdown");
				ImGui::NextColumn();
				ImGui::PushItemWidth(-1);
				if (ImGui::BeginCombo("##tag_path", "..."))
				{
					ImGui::EndCombo();
				}
				ImGui::NextColumn();
				if (ImGui::Button("NULL"))
				{

				}
				else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Nulls this tag reference");
				ImGui::NextColumn();
				if (ImGui::Button("VIEW"))
				{

				}
				else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Opens this tag in a new tab");
				ImGui::Columns(1);
			}
			else if (rTypeInfo.m_reflectionTypeCategory == ReflectionTypeCategory::DataReference)
			{

				ImGui::Columns(3, NULL, false);
				ImGui::SetColumnOffset(1, recursionPadding);
				ImGui::SetColumnWidth(1, 400);
				ImGui::SetColumnWidth(2, 640);
				ImGui::NextColumn(); // padding

				ImGui::Text(pFieldDisplayName);
				ImGui::NextColumn();

				static char pBuffer[256] = {};
				ImGui::InputTextMultiline("##datareference", pBuffer, 256, ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 8.5f), ImGuiInputTextFlags_CharsHexadecimal | ImGuiInputTextFlags_CharsUppercase);

				ImGui::Columns(4, NULL, false);
				ImGui::SetColumnOffset(1, 400);
				ImGui::SetColumnWidth(1, 200);
				ImGui::SetColumnWidth(2, 220);
				ImGui::SetColumnWidth(3, 220);
				ImGui::NextColumn();
				ImGui::Text("dataref bytes");
				ImGui::NextColumn();
				static unsigned int dataRefLengthInt = 0; // #TODO: Hook this up
				ImGui::PushItemWidth(-1);
				ImGui::Text("Length:");
				ImGui::SameLine();
				ImGui::InputScalar("", ImGuiDataType_U32, &dataRefLengthInt);
				ImGui::NextColumn();
				static unsigned int dataRefOffsetInt = 0; // #TODO: Hook this up
				ImGui::PushItemWidth(-1);
				ImGui::Text("Offset:");
				ImGui::SameLine();
				ImGui::InputScalar("", ImGuiDataType_U32, &dataRefOffsetInt);
				ImGui::Columns(1);

			}
			else if (rTypeInfo.m_reflectionTypeCategory == ReflectionTypeCategory::TagBlock)
			{
			ImGui::Columns(1);
			//ImGui::Columns(2, NULL, false);
			//ImGui::SetColumnOffset(1, recursionPadding);
			//ImGui::SetColumnWidth(1, 1230);
			//ImGui::NextColumn(); // padding
				ImGui::Dummy(ImVec2());
				ImGui::SameLine(recursionPadding + 5);

				if (ImGui::CollapsingHeader(pFieldDisplayName, ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_AllowItemOverlap))
				{
					s_tag_block_definition<>* pTagBlock = reinterpret_cast<s_tag_block_definition<>*>(pData + reflectionField.m_offset);

					const ReflectionTagBlockInfo& rReflectionTagBlockInfo = reflectionField.m_tagBlockInfo;
					const ReflectionType* pTagBlockReflectionType = rReflectionTagBlockInfo.m_pReflectionTypeInfo;
					// #TODO: We support null here because TagBlocks can be defined without their data.
					// we should migrate slowly over to not having TagBlocks with no type specified
					if (pTagBlockReflectionType)
					{
						char* pTagBlockData = static_cast<char*>(pFieldDataPointer); // #TODO: Index
						PrintReflectionInfoGUI3(pTagBlockData, *pTagBlockReflectionType, recursionDepth + 2);
					}
				}

				ImGui::Columns(1);
			}
		}
		ImGui::PopID();
	}

	DrawStructureSeparator(recursionDepth, &screenPosTop);

}

inline const ReflectionType& GetTagReflectionData(TagGroupName tagGroupName)
{
	switch (tagGroupName)
	{
	case TagGroupName::Scenario: return GetReflectionType<s_scenario_definition>();
	}
	assert(!"Failed to find tag reflection data");
	throw;
}

template<typename T>
void DisplayTag(T* pTagData)
{
	char* pData = reinterpret_cast<char*>(pTagData);
	const ReflectionType& reflectionData = GetTagReflectionData<T>();

	PrintReflectionInfoGUI3(pData, reflectionData, 0);
}

void FileSystemReadToBufferImpl(FILE* pFileHandle, char* pBuffer, size_t readLength)
{
	uint32_t iterations = 0;
	for (size_t currentPosition = 0; currentPosition < readLength; iterations++)
	{
		// prevent this from running into a madness number of iterations
		assert(iterations != UINT32_MAX);

		size_t remainingDataLength = readLength - currentPosition;
		currentPosition += fread(&pBuffer[currentPosition], 1, remainingDataLength, pFileHandle);
	}
}

char* FileSystemReadToMemory(const wchar_t* pFilePath, size_t* pAllocatedSize)
{
	FILE* pFileHandle = _wfopen(pFilePath, L"rb");
	if (pFileHandle == nullptr)
	{
		return nullptr;
	}

	fseek(pFileHandle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(pFileHandle));
	fseek(pFileHandle, 0, SEEK_SET);

	char* pBuffer = new char[fileSize] {};
	if (pAllocatedSize)
	{
		*pAllocatedSize = fileSize;
	}

	FileSystemReadToBufferImpl(pFileHandle, pBuffer, fileSize);

	int fcloseResult = fclose(pFileHandle);
	assert(fcloseResult == 0);

	return pBuffer;
}

MantleMapTab::MantleMapTab(const char* pTitle, const char* pDescription, const wchar_t* szMapFilePath)
	:MantleTab(pTitle, pDescription)
	, m_pMapData(nullptr)
	, m_mapDataLength(0)
	, m_isMapLoading(false)
{
	LoadMap(szMapFilePath);
}

MantleMapTab::~MantleMapTab()
{
	while (m_isMapLoading) {};
	if (m_pMapData) delete[] m_pMapData;
}

void MantleMapTab::LoadMap(const std::wstring& mapFilePath)
{
	m_isMapLoading = true;

	tbb::task::enqueue(*lambda_task([=]() {

		m_pMapData = FileSystemReadToMemory(mapFilePath.c_str(), &m_mapDataLength);

		if (m_pMapData)
		{
			s_cache_file_header* pHeader = reinterpret_cast<s_cache_file_header*>(m_pMapData);

			WriteLineVerbose("");
		}

		m_isMapLoading = false;

		}));
}

void DisplayMapTabUI()
{
	ImGui::BeginChild("##left_pane", ImVec2(450, 0), true, ImGuiWindowFlags_NoScrollbar);
	{
		static char pSearchBuffer[1024] = {};
		ImGui::Text("Search:");
		ImGui::SetNextItemWidth(-1);
		ImGui::InputText("", pSearchBuffer, 1024);
		ImGui::Dummy(ImVec2(0, 10));
	}
	ImGui::BeginChild("##tags", ImVec2(0, 0), true);
	static int selected = 0;
	for (int i = 0; i < 100; i++)
	{
		char label[1280];
		sprintf(label, "MyObject %d", i);
		if (ImGui::Selectable(label, selected == i))
			selected = i;
	}
	ImGui::EndChild();
	ImGui::EndChild();
	
	ImGui::SameLine();



	//// left
	//static int selected = 0;
	//ImGui::BeginChild("left pane", ImVec2(450, 0), true);
	//static char pSearchBuffer[1024] = {};
	//ImGui::Text("Search:");
	//ImGui::SetNextItemWidth(-1);
	//ImGui::InputText("", pSearchBuffer, 1024);
	//ImGui::Dummy(ImVec2(0, 10));
	//ImGui::BeginGroup();
	//for (int i = 0; i < 100; i++)
	//{
	//	char label[128];
	//	sprintf(label, "MyObject %d", i);
	//	if (ImGui::Selectable(label, selected == i))
	//		selected = i;
	//}
	//ImGui::EndGroup();
	//ImGui::EndChild();
	//ImGui::SameLine();

	// right
	ImGui::BeginGroup();
	ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));
	if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None)) // each tag
	{
		if (ImGui::BeginTabItem("Scenario")) // the tag name
		{
			{
				static s_scenario_definition scenario;

				const ReflectionType& scenarioReflectionData = GetTagReflectionData<s_scenario_definition>();
				const ReflectionType& biped_palette_blockReflectionData = GetReflectionType(scenario.biped_palette_block);
				DisplayTag(&scenario);
			}

			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}
	ImGui::EndChild();
	if (ImGui::Button("Revert")) {}
	ImGui::SameLine();
	if (ImGui::Button("Save")) {}
	ImGui::EndGroup();
}

void MantleMapTab::RenderContents(bool setSelected)
{
	ImGui::PushID(this);
	ImGuiTabItemFlags tabFlags = 0;
	if (setSelected) tabFlags |= ImGuiTabItemFlags_SetSelected;
	if (ImGui::BeginTabItem(GetTitle(), &m_isOpen, tabFlags))
	{
		if (m_isMapLoading)
		{
			ImGui::Text("Loading...");
		}
		else
		{
			DisplayMapTabUI();
		}

		ImGui::EndTabItem();
	}
	ImGui::PopID();
}
