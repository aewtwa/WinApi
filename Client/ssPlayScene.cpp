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
#include "ssTile.h"
#include "ssTileBox.h"
#include "ssTileObject.h"
#include "ssTileObjectBack.h"
#include "ssPirate1.h"
#include "ssPirate2.h"
#include "ssGameObject.h"
#include "ssStatObject.h"

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
		// 바닥 삽입
		//Object::Instantiate<IceFloor>(eLayerType::Floor);
		// 배경 삽입
		Object::Instantiate<BackGround>(eLayerType::Background);
		// 캐릭터 삽입
		Object::Instantiate<Player>(eLayerType::Player);
		// 몬스터 삽입
		Pirate1* pirate1 = Object::Instantiate<Pirate1>(eLayerType::Monster);
		Vector2 pos = pirate1->GetPos();
		pos = Vector2(Tile::ConvertNumberToTile(2, 6));
		Transform* ptr1 = pirate1->GetComponent<Transform>();
		ptr1->SetPosition(pos);
		pirate1->SetTransform(ptr1);
		pirate1->SetPos(pos);

		Pirate2* pirate2 = Object::Instantiate<Pirate2>(eLayerType::Monster);
		Vector2 pos2 = pirate2->GetPos();
		pos2 = Vector2(Tile::ConvertNumberToTile(12, 10));
		Transform* ptr2 = pirate2->GetComponent<Transform>();
		ptr2->SetPosition(pos2);
		pirate2->SetTransform(ptr2);
		pirate2->SetPos(pos2);
		// 타일 삽입
		Texture* IceTileImage = Resources::Load<Texture>(L"IceTile", L"..\\Resources\\Image\\Map\\iceobject.bmp");
		Texture* SnowTileImage = Resources::Load<Texture>(L"SnowTile", L"..\\Resources\\Image\\Map\\icetile.bmp");
		Texture* TreeImage = Resources::Load<Texture>(L"TreeTile", L"..\\Resources\\Image\\Map\\tree.bmp");
		TreeImage->SetOffset(Vector2(0.f, 7.f));
		Texture* TreeBackImage = Resources::Load<Texture>(L"TreeBackTile", L"..\\Resources\\Image\\Map\\treeback.bmp");
		TreeBackImage->SetOffset(Vector2(0.f, 21.f));
		Texture* DummyImage = Resources::Load<Texture>(L"DummyTile", L"..\\Resources\\Image\\Map\\dummy.bmp");
		DummyImage->SetOffset(Vector2(0.f, 7.f));
		Texture* DummyBackImage = Resources::Load<Texture>(L"DummyBackTile", L"..\\Resources\\Image\\Map\\dummyback.bmp");
		DummyBackImage->SetOffset(Vector2(0.f, 21.f));

		TileBox* IceTile1 = Object::Instantiate<TileBox>(eLayerType::TileBox, Tile::ConvertNumberToTile(0, 6));
		IceTile1->AddComponent<SpriteRenderer>()->SetImage(IceTileImage);
		TileBox* IceTile2 = Object::Instantiate<TileBox>(eLayerType::TileBox, Tile::ConvertNumberToTile(3, 4));
		IceTile2->AddComponent<SpriteRenderer>()->SetImage(IceTileImage);
		TileBox* IceTile3 = Object::Instantiate<TileBox>(eLayerType::TileBox, Tile::ConvertNumberToTile(3, 8));
		IceTile3->AddComponent<SpriteRenderer>()->SetImage(IceTileImage);
		TileBox* IceTile4 = Object::Instantiate<TileBox>(eLayerType::TileBox, Tile::ConvertNumberToTile(11, 4));
		IceTile4->AddComponent<SpriteRenderer>()->SetImage(IceTileImage);
		TileBox* IceTile5 = Object::Instantiate<TileBox>(eLayerType::TileBox, Tile::ConvertNumberToTile(14, 6));
		IceTile5->AddComponent<SpriteRenderer>()->SetImage(IceTileImage);
		TileBox* IceTile6 = Object::Instantiate<TileBox>(eLayerType::TileBox, Tile::ConvertNumberToTile(11, 8));
		IceTile6->AddComponent<SpriteRenderer>()->SetImage(IceTileImage);

		for (size_t h = 0; h < 4; h++)
		{
			for (size_t i = 0; i < 4; i++)
			{
				for (size_t j = 0; j < 2; j++)
				{
					TileBox* SnowTile1 = Object::Instantiate<TileBox>(eLayerType::TileBox, Tile::ConvertNumberToTile(4 + i * 2, j + 1 + h * 3));
					SnowTile1->AddComponent<SpriteRenderer>()->SetImage(SnowTileImage);
				}
			}
		}

		for (size_t i = 0; i < 3; i++)
		{
			TileBox* SnowTile1 = Object::Instantiate<TileBox>(eLayerType::TileBox, Tile::ConvertNumberToTile(1, 4 + i * 2));
			SnowTile1->AddComponent<SpriteRenderer>()->SetImage(SnowTileImage);
			TileBox* SnowTile = Object::Instantiate<TileBox>(eLayerType::TileBox, Tile::ConvertNumberToTile(13, 4 + i * 2));
			SnowTile->AddComponent<SpriteRenderer>()->SetImage(SnowTileImage);
		}

		for (size_t i = 0; i < 3; i++)
		{
			TileObject* TreeTile = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(1, i + 1));
			TreeTile->AddComponent<SpriteRenderer>()->SetImage(TreeImage);
			TileObjectBack* TreeBackTile = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(1, i));
			TreeBackTile->AddComponent<SpriteRenderer>()->SetImage(TreeBackImage);
			TileObject* TreeTile1 = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(i + 1, 1));
			TreeTile1->AddComponent<SpriteRenderer>()->SetImage(TreeImage);
			TileObjectBack* TreeBackTile1 = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(i + 1, 0));
			TreeBackTile1->AddComponent<SpriteRenderer>()->SetImage(TreeBackImage);
		}

		for (size_t i = 0; i < 3; i++)
		{
			TileObject* TreeTile1 = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(13 - i, 1));
			TreeTile1->AddComponent<SpriteRenderer>()->SetImage(TreeImage);
			TileObjectBack* TreeBackTile = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(13 - i, 0));
			TreeBackTile->AddComponent<SpriteRenderer>()->SetImage(TreeBackImage);
			TileObject* TreeTile = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(13, i + 1));
			TreeTile->AddComponent<SpriteRenderer>()->SetImage(TreeImage);
			TileObjectBack* TreeBackTile1 = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(13, i));
			TreeBackTile1->AddComponent<SpriteRenderer>()->SetImage(TreeBackImage);
		}

		for (size_t i = 0; i < 3; i++)
		{
			TileObject* TreeTile1 = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(1, 9 + i));
			TreeTile1->AddComponent<SpriteRenderer>()->SetImage(TreeImage);
			TileObjectBack* TreeBackTile1 = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(1, 8 + i));
			TreeBackTile1->AddComponent<SpriteRenderer>()->SetImage(TreeBackImage);
			TileObject* TreeTile = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(1 + i, 11));
			TreeTile->AddComponent<SpriteRenderer>()->SetImage(TreeImage);
			TileObjectBack* TreeBackTile = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(1 + i, 10));
			TreeBackTile->AddComponent<SpriteRenderer>()->SetImage(TreeBackImage);
		}

		for (size_t i = 0; i < 3; i++)
		{
			TileObject* TreeTile1 = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(13, 9 + i));
			TreeTile1->AddComponent<SpriteRenderer>()->SetImage(TreeImage);
			TileObjectBack* TreeBackTile = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(13, 8 + i));
			TreeBackTile->AddComponent<SpriteRenderer>()->SetImage(TreeBackImage);
			TileObject* TreeTile = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(11 + i, 11));
			TreeTile->AddComponent<SpriteRenderer>()->SetImage(TreeImage);
			TileObjectBack* TreeBackTile1 = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(11 + i, 10));
			TreeBackTile1->AddComponent<SpriteRenderer>()->SetImage(TreeBackImage);
		}

		for (size_t i = 0; i < 3; i++)
		{
			TileObject* TreeTile = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(5 + i * 2, 1));
			TreeTile->AddComponent<SpriteRenderer>()->SetImage(TreeImage);
			TileObjectBack* TreeBackTile1 = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(5 + i * 2, 0));
			TreeBackTile1->AddComponent<SpriteRenderer>()->SetImage(TreeBackImage);
			TileObject* TreeTile1 = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(5 + i * 2, 11));
			TreeTile1->AddComponent<SpriteRenderer>()->SetImage(TreeImage);
			TileObjectBack* TreeBackTile = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(5 + i * 2, 10));
			TreeBackTile->AddComponent<SpriteRenderer>()->SetImage(TreeBackImage);
		}

		for (size_t i = 0; i < 2; i++)
		{
			TileObject* TreeTile = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(1, 5 + i * 2));
			TreeTile->AddComponent<SpriteRenderer>()->SetImage(TreeImage);
			TileObjectBack* TreeBackTile = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(1, 4 + i * 2));
			TreeBackTile->AddComponent<SpriteRenderer>()->SetImage(TreeBackImage);
			TileObject* TreeTile1 = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(13, 5 + i * 2));
			TreeTile1->AddComponent<SpriteRenderer>()->SetImage(TreeImage);
			TileObjectBack* TreeBackTile1 = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(13, 4 + i * 2));
			TreeBackTile1->AddComponent<SpriteRenderer>()->SetImage(TreeBackImage);
		}

		for (size_t i = 0; i < 2; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				TileObject* DummyTile = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(3 + j * 4, 3 + i * 6));
				DummyTile->AddComponent<SpriteRenderer>()->SetImage(DummyImage);
				TileObjectBack* DummyBackTile = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(3 + j * 4, 2 + i * 6));
				DummyBackTile->AddComponent<SpriteRenderer>()->SetImage(DummyBackImage);
			}
		}

		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 2; j++)
			{
				TileObject* DummyTile = Object::Instantiate<TileObject>(eLayerType::TileObject, Tile::ConvertNumberToTile(3 + i * 2, 5 + j * 2));
				DummyTile->AddComponent<SpriteRenderer>()->SetImage(DummyImage);
				TileObjectBack* DummyBackTile = Object::Instantiate<TileObjectBack>(eLayerType::TileObjectBack, Tile::ConvertNumberToTile(3 + i * 2, 4 + j * 2));
				DummyBackTile->AddComponent<SpriteRenderer>()->SetImage(DummyBackImage);
			}
		}

		Object::Instantiate<ballon>(eLayerType::Item, Tile::ConvertNumberToTile(4, 9));
		Object::Instantiate<potion>(eLayerType::Item, Tile::ConvertNumberToTile(5, 9));
		Object::Instantiate<skate>(eLayerType::Item, Tile::ConvertNumberToTile(6, 9));

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::WaterBomb, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::TileBox, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::TileObject, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Item, true);

		CollisionManager::CollisionLayerCheck(eLayerType::Monster, eLayerType::TileBox, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Monster, eLayerType::TileObject, true);

		CollisionManager::CollisionLayerCheck(eLayerType::WaterFlow, eLayerType::Player, true);
		CollisionManager::CollisionLayerCheck(eLayerType::WaterFlow, eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(eLayerType::WaterFlow, eLayerType::Item, true);
		CollisionManager::CollisionLayerCheck(eLayerType::WaterFlow, eLayerType::TileBox, true);
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
		if (Input::GetKey(eKeyCode::Z))
		{
			SceneManager::LoadScene(L"ToolScene");
		}

		if (this->GetLayer(eLayerType::Monster).GetGameObjects().size() == 0)
		{
			SceneManager::LoadScene(L"IceMap1");
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