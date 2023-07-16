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
#include "ssAnimator.h"
#include "ssMonster.h"

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
		bgsr->SetAffectCamera(false);
		bg->GetComponent<Transform>()->SetPosition(Vector2(520.0f, 390.0f));

		// Ä³¸¯ÅÍ »ðÀÔ
		Texture* Playerimage = Resources::Load<Texture>(L"Player", L"..\\Resources\\Image\\Bazzi\\Bazzi.bmp");
		Player* player = Object::Instantiate<Player>(eLayerType::Player);
		Transform* TR = player->GetComponent<Transform>();
		TR->SetPosition(Vector2(100.0f, 100.0f));
		Animator* AT = player->AddComponent<Animator>();
		AT->CreateAnimation(L"Bazzi_Idle", Playerimage, Vector2(0.0f, 0.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.3f);
		AT->CreateAnimation(L"Bazzi_Up", Playerimage, Vector2(0.0f, 60.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		AT->CreateAnimation(L"Bazzi_Down", Playerimage, Vector2(0.0f, 120.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		AT->CreateAnimation(L"Bazzi_Left", Playerimage, Vector2(0.0f, 180.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		AT->CreateAnimation(L"Bazzi_Right", Playerimage, Vector2(0.0f, 240.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		AT->CreateAnimation(L"Bazzi_Death", Playerimage, Vector2(0.0f, 300.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		AT->CreateAnimation(L"Bazzi_Up_Idle", Playerimage, Vector2(0.0f, 360.0f), Vector2(50.0f, 60.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		AT->CreateAnimation(L"Bazzi_Down_Idle", Playerimage, Vector2(50.0f, 360.0f), Vector2(50.0f, 60.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		AT->CreateAnimation(L"Bazzi_Left_Idle", Playerimage, Vector2(100.0f, 360.0f), Vector2(50.0f, 60.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		AT->CreateAnimation(L"Bazzi_Right_Idle", Playerimage, Vector2(150.0f, 360.0f), Vector2(50.0f, 60.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		AT->PlayAnimation(L"Bazzi_Idle", true);

		// ¹°ÆøÅº »ðÀÔ
		Texture* WBimage = Resources::Load<Texture>(L"Player", L"..\\Resources\\Image\\Bomb\\Idle\\BombIdle.bmp");
		WaterBomb* waterBomb = Object::Instantiate<WaterBomb>(eLayerType::WaterBomb);
		Vector2 WBpos = TR->GetPosition();
		Transform* WBtr = waterBomb->GetComponent<Transform>();
		WBtr->SetPosition(WBpos);
		Animator* WBat = waterBomb->AddComponent<Animator>();
		WBat->CreateAnimation(L"WaterBomb_Idle", WBimage, Vector2(0.0f, 0.0f), Vector2(44.0f, 41.0f), 3, Vector2(0.0f, 0.0f), 0.3f);

		// ¸ó½ºÅÍ »ðÀÔ
		Monster* monster = Object::Instantiate<Monster>(eLayerType::Monster);
		Transform* Monstertr = monster->GetComponent<Transform>();
		Monstertr->SetPosition(Vector2(250.0f, 250.0f));
		Animator* MonsterAT = monster->AddComponent<Animator>();
		MonsterAT->CreateAnimationFolder(L"Monster", L"..\\Resources\\Image\\Monster\\Forest\\Down");
		MonsterAT->PlayAnimation(L"Monster", true);
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