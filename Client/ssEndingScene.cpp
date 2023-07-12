#include "ssEndingScene.h"
#include "ssSpriteRenderer.h"
#include "ssObject.h"
#include "ssTexture.h"
#include "ssResources.h"
#include "ssInput.h"
#include "ssEnding.h"


namespace ss
{
	EndingScene::EndingScene()
	{
	}
	EndingScene::~EndingScene()
	{
	}
	void EndingScene::Initialize()
	{
		Texture* image = Resources::Load<Texture>(L"EndingImage", L"..\\Resources\\Image\\Bg\\Logo.bmp");

		Ending* bg = Object::Instantiate<Ending>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetScale(Vector2(1.23f, 1.23f));
	}
	void EndingScene::Update()
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
	void EndingScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
	}
}
