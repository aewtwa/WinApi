#include "ssLoadingScene.h"
#include "ssSpriteRenderer.h"
#include "ssObject.h"
#include "ssTexture.h"
#include "ssResources.h"
#include "ssLoading.h"
#include "ssInput.h"

namespace ss
{
	LoadingScene::LoadingScene()
	{
	}
	LoadingScene::~LoadingScene()
	{
	}
	void LoadingScene::Initialize()
	{
		Texture* image = Resources::Load<Texture>(L"LoadingImage", L"..\\Resources\\Image\\Bg\\Logo.bmp");

		Loading* bg = Object::Instantiate<Loading>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetScale(Vector2(1.23f, 1.23f));
	}
	void LoadingScene::Update()
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
		if (Input::GetKeyDown(eKeyCode::L))
		{
			SceneManager::LoadScene(L"LoadingScene");
		}
		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	void LoadingScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
	}
}