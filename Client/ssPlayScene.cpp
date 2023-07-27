#include "ssPlayScene.h"
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
		BackGround* bg = Object::Instantiate<BackGround>(eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetImage(image);
		bgsr->SetScale(Vector2(1.3f, 1.3f));
		bg->GetComponent<Transform>()->SetPosition(Vector2(520.0f, 390.0f));

		Texture* playimage = Resources::Load<Texture>(L"PlayGround", L"..\\Resources\\Image\\Bg\\ForestTile.bmp");
		PlayGround* playbg = Object::Instantiate<PlayGround>(eLayerType::Background);
		SpriteRenderer* playbgsr = playbg->AddComponent<SpriteRenderer>();
		playbgsr->SetImage(playimage);
		playbgsr->SetScale(Vector2(0.87f, 0.87f));
		playbg->GetComponent<Transform>()->SetPosition(Vector2(416.0f, 391.0f));


		// Ä³¸¯ÅÍ »ðÀÔ
		Object::Instantiate<Player>(eLayerType::Player, Vector2(100.0f, 100.0f));
		// ¸ó½ºÅÍ »ðÀÔ
		Object::Instantiate<Monster>(eLayerType::Monster, Vector2(250.0f, 250.0f));

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::WaterBomb, true);
	}
	void PlayScene::Update()
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
	void PlayScene::Render(HDC _hdc)
	{
		Scene::Render(_hdc);
	}
}