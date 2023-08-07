#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <string>
#include <filesystem>
#include <bitset>
#include <assert.h>

#include "framework.h"
#include "ssMath.h"

#pragma comment(lib, "Msimg32.lib")

#include <mmsystem.h>
#include <dsound.h>
#include <dinput.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")

#define TILE_WIDTH 52.0f
#define TILE_HEIGHT 52.0f

#define MAP_WIDTH 15
#define MAP_HEIGHT 13

#define BLANK_WIDTH 26.0f
#define BLANK_HEIGHT 53.0f

namespace ss::enums
{
	enum class eLayerType
	{
		Background,
		Floor,
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

	enum class eDirection
	{
		Up,
		Down,
		Left,
		Right,
		End
	};
}