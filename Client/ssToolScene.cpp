#include "ssToolScene.h"
#include "ssTitleScene.h"
#include "ssPlayer.h"
#include "ssSpriteRenderer.h"
#include "ssObject.h"
#include "ssInput.h"
#include "ssTexture.h"
#include "ssTransform.h"
#include "ssResources.h"
#include "ssBackGround.h"
#include "ssCamera.h"
#include "ssTile.h"
#include "ssInput.h"

namespace ss
{
	ToolScene::ToolScene()
	{
	}
	ToolScene::~ToolScene()
	{
	}
	void ToolScene::Initialize()
	{
		Texture* springFloor = Resources::Load<Texture>(L"CampmapTile", L"..\\Resources\\Image\\Map\\campmap.bmp");
	}

	void ToolScene::Update()
	{
		Scene::Update();

		if (Input::GetKey(eKeyCode::MouseLeft) && GetFocus())
		{
			Vector2 mousePos = Input::GetMousePosition();

			int idxX = mousePos.x / (TILE_WIDTH);
			int idxY = mousePos.y / (TILE_HEIGHT);

			Vector2 offset = Vector2((TILE_WIDTH) / 2.0f, (TILE_HEIGHT) / 2.0f);
			Tile* tile = Object::Instantiate<Tile>(eLayerType::Tile, Vector2(idxX * (TILE_WIDTH) + offset.x, idxY * (TILE_HEIGHT) + offset.y));

			int a = Tile::mSelectedX;
			int b = Tile::mSelectedY;

			tile->SetTile(Tile::mSelectedX, Tile::mSelectedY);
		}

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
		if (Input::GetKey(eKeyCode::Space))
		{
			SceneManager::LoadScene(L"ToolScene");
		}
	}
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		int maxRow = 780 / (TILE_HEIGHT) + 1;
		for (size_t y = 0; y < maxRow; y++)
		{
			MoveToEx(hdc, 0, TILE_HEIGHT * y, NULL);      //      라인(선) 시작
			LineTo(hdc, 1040, TILE_HEIGHT * y);        //          라인(선) 끝
		}

		int maxColumn = 1040 / (TILE_WIDTH) + 1;
		for (size_t x = 0; x < maxColumn; x++)
		{
			MoveToEx(hdc, TILE_WIDTH * x, 0, NULL);      //      라인(선) 시작
			LineTo(hdc, TILE_WIDTH * x, 780);        //          라인(선) 끝
		}
	}
}