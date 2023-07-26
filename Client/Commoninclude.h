#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <string>
#include <filesystem>
#include <bitset>

#include "framework.h"
#include "ssMath.h"

#pragma comment(lib, "Msimg32.lib")

#define TILE_WIDTH 40
#define TILE_HEIGHT 40

namespace ss::enums
{
	enum class eLayerType
	{
		Background,
		Tile,
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
		Collider,
		End
	};
}