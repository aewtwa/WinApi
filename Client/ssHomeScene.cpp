#include "ssHomeScene.h"
#include "ssSpriteRenderer.h"
#include "ssObject.h"
#include "ssTexture.h"
#include "ssTransform.h"
#include "ssResources.h"
#include "ssInput.h"
#include "ssBackGround.h"

namespace ss
{
	HomeScene::HomeScene()
	{
	}
	HomeScene::~HomeScene()
	{
	}
	void HomeScene::Initialize()
	{
		Texture* image = Resources::Load<Texture>(L"HomeBackGroundImage", L"..\\Resources\\Image\\Bg\\Lobby.bmp");

		BackGround* bg = Object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetScale(Vector2(1.3f, 1.3f));
		bg->GetComponent<Transform>()->SetPosition(Vector2(520.0f, 390.0f));
	}
	void HomeScene::Update()
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
	void HomeScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
	}
}
