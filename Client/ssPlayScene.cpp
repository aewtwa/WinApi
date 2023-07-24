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
		Texture* Playerimage = Resources::Load<Texture>(L"Bazzi", L"..\\Resources\\Image\\Bazzi\\Bazzi.bmp");
		Texture* Trapimage = Resources::Load<Texture>(L"Bazzi_Trap", L"..\\Resources\\Image\\Bazzi\\trap.bmp");
		Texture* Deathimage = Resources::Load<Texture>(L"Bazzi_Die", L"..\\Resources\\Image\\Bazzi\\die.bmp");
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
		AT->CreateAnimation(L"Bazzi_Trap", Trapimage, Vector2(0.0f, 0.0f), Vector2(88.0f, 144.0f), 13, Vector2(0.0f, 0.0f), 0.1f);
		AT->CreateAnimation(L"Bazzi_Die", Deathimage, Vector2(0.0f, 0.0f), Vector2(88.0f, 144.0f), 13, Vector2(0.0f, 0.0f), 0.1f);
		AT->PlayAnimation(L"Bazzi_Idle", true);
		Collider* COL = player->AddComponent<Collider>();
		COL->SetSize(Vector2(50.0f, 60.0f));
		// ¹°ÆøÅº »ðÀÔ
		Texture* Bombimage = Resources::Load<Texture>(L"Bomb", L"..\\Resources\\Image\\Bomb\\Idle\\BombIdle.bmp");
		AT->CreateAnimation(L"Bomb", Bombimage, Vector2(0.0f, 0.0f), Vector2(44.0f, 41.0f), 3, Vector2(0.0f, 0.0f), 0.3f);
		// ¸ó½ºÅÍ »ðÀÔ
		Texture* Monsterimage = Resources::Load<Texture>(L"Monster", L"..\\Resources\\Image\\Monster\\Forest\\Down\\ForestMob.bmp");
		Monster* monster = Object::Instantiate<Monster>(eLayerType::Monster);
		TR = monster->GetComponent<Transform>();
		TR->SetPosition(Vector2(250.0f, 250.0f));
		AT = monster->AddComponent<Animator>();
		AT->CreateAnimation(L"ForestMobDown", Monsterimage, Vector2(0.0f, 0.0f), Vector2(35.0f, 41.0f), 2, Vector2(0.0f, 0.0f), 0.3f);
		AT->PlayAnimation(L"ForestMobDown", true);
		COL = monster->AddComponent<Collider>();
		COL->SetSize(Vector2(35.0f, 40.0f));

		// º¸½º¸ó½ºÅÍ »ðÀÔ
		Monster* SealBoss = Object::Instantiate<Monster>(eLayerType::Monster);
		TR = SealBoss->GetComponent<Transform>();
		TR->SetPosition(Vector2(500.0f, 500.0f));
		AT = SealBoss->AddComponent<Animator>();
		AT->CreateAnimationFolder(L"SealBoss", L"..\\Resources\\Image\\Monster\\SealBoss\\Attack", Vector2(0.0f, 0.0f), 0.3f);
		AT->PlayAnimation(L"SealBoss", true);
		AT->SetScale(Vector2(2.0f, 2.0f));
		COL = SealBoss->AddComponent<Collider>();
		COL->SetSize(Vector2(200.0f, 180.0f));

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);
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