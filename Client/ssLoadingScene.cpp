#include "ssLoadingScene.h"
#include "ssSpriteRenderer.h"
#include "ssObject.h"
#include "ssTexture.h"
#include "ssTransform.h"
#include "ssResources.h"
#include "ssBackGround.h"
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
		Resources::Load<Texture>(L"PlayBackGround", L"..\\Resources\\Image\\Bg\\play.bmp");
		Resources::Load<Texture>(L"Tile", L"..\\Resources\\Image\\Map\\campmap.bmp");
		Resources::Load<Texture>(L"LoadingImage", L"..\\Resources\\Image\\Bg\\Logo.bmp");
		Resources::Load<Texture>(L"Bazzi", L"..\\Resources\\Image\\Bazzi\\Bazzi.bmp");
		Resources::Load<Texture>(L"Bazzi_Trap", L"..\\Resources\\Image\\Bazzi\\trap.bmp");
		Resources::Load<Texture>(L"Bazzi_Die", L"..\\Resources\\Image\\Bazzi\\die.bmp");
		Resources::Load<Texture>(L"WaterBomb", L"..\\Resources\\Image\\Bomb\\Idle\\BombIdle.bmp");
		Resources::Load<Texture>(L"BombLeftflow", L"..\\Resources\\Image\\Bomb\\Leftflow");
		Resources::Load<Texture>(L"Monster", L"..\\Resources\\Image\\Monster\\Forest\\Down\\ForestMob.bmp");

		BackGround* bg = Object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(Resources::Find<Texture>(L"LoadingImage"));
		bgsr->SetScale(Vector2(1.23f, 1.23f));
		bg->GetComponent<Transform>()->SetPosition(Vector2(520.0f, 390.0f));
	}
	void LoadingScene::Update()
	{
		Scene::Update();

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
}