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
	}

	void ToolScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::MouseLeft) && GetFocus())
		{
			Vector2 mousePos = Input::GetMousePosition();

			int idxX = mousePos.x / (TILE_WIDTH);
			int idxY = mousePos.y / (TILE_HEIGHT);

			Vector2 offset = Vector2((TILE_WIDTH) / 2.0f, (TILE_HEIGHT) / 2.0f);
			Tile* tile = Object::Instantiate<Tile>(eLayerType::Tile, Vector2(idxX * (TILE_WIDTH)+offset.x, idxY * (TILE_HEIGHT)+offset.y));

			tile->SetTile(Tile::mSelectedX, Tile::mSelectedY);
			tile->SetSourceTileIdx(Tile::mSelectedX, Tile::mSelectedY);
			tile->SetTileIdx(idxX, idxY);

			mTiles.push_back(tile);
		}

		if (Input::GetKeyDown(eKeyCode::S))
		{
			Save();
		}
		if (Input::GetKeyDown(eKeyCode::M))
		{
			Load();
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

		int maxRow = 520 * 1.3f / (TILE_HEIGHT) + 1;
		for (size_t y = 0; y < maxRow; y++)
		{
			MoveToEx(hdc, 0, TILE_HEIGHT * y, NULL);      //      ����(��) ����
			LineTo(hdc, 600 * 1.3f, TILE_HEIGHT * y);        //          ����(��) ��
		}

		int maxColumn = 600 * 1.3f / (TILE_WIDTH) + 1;
		for (size_t x = 0; x < maxColumn; x++)
		{
			MoveToEx(hdc, TILE_WIDTH * x, 0, NULL);      //      ����(��) ����
			LineTo(hdc, TILE_WIDTH * x, 520 * 1.3f);        //          ����(��) ��
		}
	}

	void ToolScene::Save()
	{
		// open a file name
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0*.tile\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetSaveFileName(&ofn))
			return;

		FILE* pFile = nullptr;

		_wfopen_s(&pFile, szFilePath, L"wb");
		if (pFile == nullptr)
			return;

		for (Tile* tile : mTiles)
		{
			Vector2 sourIdx = tile->GetSourceTileIdx();
			Vector2 idx = tile->GetTileIdx();

			int sourceX = sourIdx.x;
			int sourceY = sourIdx.y;

			int	myX = idx.x;
			int myY = idx.y;

			fwrite(&sourceX, sizeof(int), 1, pFile);
			fwrite(&sourceY, sizeof(int), 1, pFile);
			fwrite(&myX, sizeof(int), 1, pFile);
			fwrite(&myY, sizeof(int), 1, pFile);
		}

		fclose(pFile);
	}

	void ToolScene::Load()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetOpenFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"rb");

		if (pFile == nullptr)
			return;

		//for (Tile* tile : mTiles)
		//{
		//	Destroy(tile);
		//}
		//mTiles.clear();

		while (true)
		{
			int sourceX = -1;
			int sourceY = -1;

			int	myX = -1;
			int myY = -1;

			if (fread(&sourceX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&sourceY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&myX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&myY, sizeof(int), 1, pFile) == NULL)
				break;

			Vector2 offset = Vector2((TILE_WIDTH) / 2.0f, (TILE_HEIGHT) / 2.0f);
			Tile* tile = Object::Instantiate<Tile>(eLayerType::Tile
				, Vector2(myX * (TILE_WIDTH) + offset.x
					, myY * (TILE_HEIGHT) + offset.y));

			tile->SetTile(sourceX, sourceY);
			tile->SetSourceTileIdx(sourceX, sourceY);
			tile->SetTileIdx(myX, myY);

			mTiles.push_back(tile);
		}
	}
}