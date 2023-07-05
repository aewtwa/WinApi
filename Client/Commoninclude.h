#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <string>

#include "framework.h"
#include "ssMath.h"

namespace ss::enums
{
	enum class eLayerType
	{
		Background,
		Player,
		Monster,
		Effect,
		UI,
		End
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		End
	};
}