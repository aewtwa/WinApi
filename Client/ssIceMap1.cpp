#include "ssIceMap1.h"
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

namespace ss
{
	IceMap1::IceMap1()
	{
	}
	IceMap1::~IceMap1()
	{
	}
	void IceMap1::Initialize()
	{
		Object::Instantiate<BackGround>(eLayerType::Background);
		Object::Instantiate<Player>(eLayerType::Player);
	}
	void IceMap1::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::M))
		{
			Load();
		}
	}
	void IceMap1::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
	}

	void IceMap1::Load()
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

		for (Tile* tile : mTiles)
		{
			Destroy(tile);
		}
		mTiles.clear();

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

			Vector2 offset = Vector2((TILE_WIDTH * 1.3f) / 2.0f, (TILE_HEIGHT * 1.3f) / 2.0f);
			Tile* tile = Object::Instantiate<Tile>(eLayerType::Tile
				, Vector2(myX * (TILE_WIDTH * 1.3f)+offset.x
					, myY * (TILE_HEIGHT * 1.3f)+offset.y));

			tile->SetTile(sourceX, sourceY);
			tile->SetSourceTileIdx(sourceX, sourceY);
			tile->SetTileIdx(myX, myY);

			mTiles.push_back(tile);
		}
	}
}