#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <string>
#include <bitset>
#include <filesystem>

#include "framework.h"
#include "ssMath.h"

#pragma comment(lib, "Msimg32.lib")

namespace ss::enums
{
	enum class eLayerType
	{
		Background,
		WaterBomb,
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
		Animation,
		Animator,
		End
	};

	enum class eDirectionType
	{
		Up,
		Down,
		Left,
		Right,
		End
	};
}