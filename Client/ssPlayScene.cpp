#include "ssPlayScene.h"
#include "ssPlayer.h"
#include "ssSpriteRenderer.h"
#include "ssObject.h"
#include "ssInput.h"
#include "ssTexture.h"
#include "ssTransform.h"
#include "ssResources.h"
#include "ssPlayBackGround.h"

namespace ss
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		// ¹è°æ »ðÀÔ
		Texture* image = Resources::Load<Texture>(L"PlayBackGround", L"..\\Resources\\Image\\Bg\\play.bmp");
		PlayBackGround* bg = Object::Instantiate<PlayBackGround>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetScale(Vector2(1.3f, 1.3f));
		bgsr->SetAffectCamera(false);
		bg->GetComponent<Transform>()->SetPosition(Vector2(520.0f, 390.0f));

		// Ä³¸¯ÅÍ »ðÀÔ
		Texture* Playerimage = Resources::Load<Texture>(L"Player", L"..\\Resources\\Image\\Bazzi\\Idle.bmp");
		Player* player = Object::Instantiate<Player>(eLayerType::Player);
		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
		sr->SetImage(Playerimage);
		sr->SetScale(Vector2(1.0f, 1.0f));
		sr->SetAffectCamera(false);
		player->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		
	}
	void PlayScene::Update()
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
	void PlayScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
	}
}