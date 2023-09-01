#include "ssLoadingScene.h"
#include "ssSpriteRenderer.h"
#include "ssObject.h"
#include "ssTexture.h"
#include "ssTransform.h"
#include "ssResources.h"
#include "ssBackGround.h"
#include "ssInput.h"
#include "ssSound.h"

namespace ss
{
	LoadingScene::LoadingScene()
		: mLoadingSound(nullptr)
	{
	}
	LoadingScene::~LoadingScene()
	{
	}
	void LoadingScene::Initialize()
	{
		Resources::Load<Texture>(L"PlayBackGround", L"..\\Resources\\Image\\Bg\\play.bmp");
		Resources::Load<Texture>(L"Tile", L"..\\Resources\\Image\\Map\\campmap.bmp");
		Resources::Load<Texture>(L"LoadingImage", L"..\\Resources\\Image\\Bg\\Logo.bmp");
		Resources::Load<Texture>(L"Bazzi", L"..\\Resources\\Image\\Bazzi\\Bazzi.bmp");
		Resources::Load<Texture>(L"Bazzi_Trap", L"..\\Resources\\Image\\Bazzi\\trap.bmp");
		Resources::Load<Texture>(L"Bazzi_Die", L"..\\Resources\\Image\\Bazzi\\die.bmp");
		Resources::Load<Texture>(L"ballon", L"..\\Resources\\Image\\Items\\ballon.bmp");
		Resources::Load<Texture>(L"potion", L"..\\Resources\\Image\\Items\\potion.bmp");
		Resources::Load<Texture>(L"skate", L"..\\Resources\\Image\\Items\\skate.bmp");

		BackGround* bg = Object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(Resources::Find<Texture>(L"LoadingImage"));
		bgsr->SetScale(Vector2(1.23f, 1.23f));
		bg->GetComponent<Transform>()->SetPosition(Vector2(520.f, 390.f));
	}
	void LoadingScene::Update()
	{
		Scene::Update();

		if (mLoadingSound)
		{
			if (!mLoadingSound->IsPlaying())
			{
				SceneManager::LoadScene(L"TitleScene");
			}
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
	void LoadingScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
	}
	void LoadingScene::SceneEnter()
	{
		mLoadingSound = Resources::Load<Sound>(L"LoadingSound", L"..\\Resources\\Sound\\logo.wav");
		mLoadingSound->Play(false);
	}
	void LoadingScene::SceneExit()
	{
	}
}