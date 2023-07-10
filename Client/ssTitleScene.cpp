#include "ssTitleScene.h"
#include "ssPlayer.h"
#include "ssSpriteRenderer.h"
#include "ssObject.h"
#include "ssInput.h"
#include "ssImage.h"
#include "ssResources.h"


namespace ss
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		Image* image = Resources::Load<Image>(L"TitleBackGroundImgae"
			, L"..\\Resources\\Image\\Bazzi\\Idle.bmp");

		Player* player = Object::Instantiate<Player>(eLayerType::Player);
		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		sr->SetImage(image);

		std::wstring name = player->GetName();

		//mLayers[(int)eLayerType::Player].AddGameObject(player);
	}
	void TitleScene::Update()
	{
		Scene::Update();


		if (Input::GetKeyDown(eKeyCode::H))
		{
			SceneManager::LoadScene(L"HomeScene");
		}
		if (Input::GetKeyDown(eKeyCode::T))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
		if (Input::GetKeyDown(eKeyCode::E))
		{
			SceneManager::LoadScene(L"EndingScene");
		}
	}
	void TitleScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
	}
}