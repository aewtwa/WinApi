#include "ssPlayScene.h"
#include "ssPlayer.h"
#include "ssWaterBomb.h"
#include "ssSpriteRenderer.h"
#include "ssObject.h"
#include "ssInput.h"
#include "ssTexture.h"
#include "ssTransform.h"
#include "ssResources.h"
#include "ssBackGround.h"
#include "ssPlayGround.h"
#include "ssAnimator.h"
#include "ssMonster.h"
#include "ssCollisionManager.h"
#include "ssCollider.h"
#include "ssIceFloor.h"
#include "ssballon.h"
#include "ssskate.h"
#include "sspotion.h"

namespace ss
{
	PlayScene::PlayScene()
		: mMapidxX(0)
		, mMapidxY(0)
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		// 배경 삽입
		Object::Instantiate<BackGround>(eLayerType::Background);
		// 캐릭터 삽입
		Object::Instantiate<Player>(eLayerType::Player);
		// 몬스터 삽입
		Object::Instantiate<Monster>(eLayerType::Monster);
		// 바닥 삽입
		//Object::Instantiate<IceFloor>(eLayerType::Floor);
		// 물폭탄 아이템 삽입
		Vector2 bp = {};
		bp.x = 400.f;
		bp.y = 400.f;
		Object::Instantiate<ballon>(eLayerType::Item, bp);
		bp.x = 300.f;
		bp.y = 300.f;
		Object::Instantiate<potion>(eLayerType::Item, bp);
		bp.x = 200.f;
		bp.y = 200.f;
		Object::Instantiate<skate>(eLayerType::Item, bp);

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::WaterBomb, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Tile, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Item, true);
	}
	void PlayScene::Update()
	{
		if (Input::GetKey(eKeyCode::H))
		{
			SceneManager::LoadScene(L"HomeScene");
		}
		if (Input::GetKey(eKeyCode::T))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
		if (Input::GetKey(eKeyCode::E))
		{
			SceneManager::LoadScene(L"EndingScene");
		}
		if (Input::GetKey(eKeyCode::L))
		{
			SceneManager::LoadScene(L"LoadingScene");
		}
		if (Input::GetKey(eKeyCode::P))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
		if (Input::GetKey(eKeyCode::I))
		{
			SceneManager::LoadScene(L"IceMap1");
		}
		if (Input::GetKey(eKeyCode::Space))
		{
			SceneManager::LoadScene(L"ToolScene");
		}

		Scene::Update();
	}
	void PlayScene::Render(HDC _hdc)
	{

		int maxRow = 520 * 1.3f / (TILE_HEIGHT) + 1;
		for (size_t y = 0; y < maxRow; y++)
		{
			MoveToEx(_hdc, 2.0f, TILE_HEIGHT * y + BLANK_HEIGHT, NULL);      //      라인(선) 시작
			LineTo(_hdc, 600 * 1.3f + BLANK_WIDTH, TILE_HEIGHT * y + BLANK_HEIGHT);        //          라인(선) 끝
		}

		int maxColumn = 600 * 1.3f / (TILE_WIDTH) + 1;
		for (size_t x = 0; x < maxColumn; x++)
		{
			MoveToEx(_hdc, TILE_WIDTH * x + BLANK_WIDTH, 0 + BLANK_HEIGHT, NULL);      //      라인(선) 시작
			LineTo(_hdc, TILE_WIDTH * x + BLANK_WIDTH, 520 * 1.3f + BLANK_HEIGHT);        //          라인(선) 끝
		}


		Scene::Render(_hdc);

	}
}