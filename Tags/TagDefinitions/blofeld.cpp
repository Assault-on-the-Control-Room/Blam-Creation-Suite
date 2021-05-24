#include "tagdefinitions-private-pch.h"

namespace blofeld
{
	c_versioned_string_list empty_string_list;

	const s_tag_group* get_group_tag_by_group_tag(e_engine_type engine_type, uint32_t group_tag)
	{
		for (const s_tag_group** group = tag_groups[engine_type]; *group; group++)
		{
			if ((**group).group_tag == group_tag)
			{
				return *group;
			}
		}
		return nullptr;
	}
}


