#include "ssPlayer.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssInput.h"
#include "ssWaterBomb.h"
#include "ssMonster.h"
#include "ssCollider.h"
#include "ssResources.h"
#include "ssTexture.h"

namespace ss
{
	Player::Player()
		: mState(eState::Idle)
		, mPos(Vector2(0.0f,0.0f))
		, mTransform{}
		, mAnimator{}
	{
	}

	Player::~Player()
	{
	}

	void Player::Initialize()
	{
		GameObject::Initialize();

		mTransform = AddComponent<Transform>();
		mPos = mTransform->GetPosition();

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"Bazzi_Idle", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 0.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.3f);
		mAnimator->CreateAnimation(L"Bazzi_Up", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 60.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Left", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 180.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Down", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 120.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Right", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 240.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Death", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 300.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Up_Idle", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 360.0f), Vector2(50.0f, 60.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Left_Idle", Resources::Find<Texture>(L"Bazzi"), Vector2(100.0f, 360.0f), Vector2(50.0f, 60.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Down_Idle", Resources::Find<Texture>(L"Bazzi"), Vector2(50.0f, 360.0f), Vector2(50.0f, 60.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Right_Idle", Resources::Find<Texture>(L"Bazzi"), Vector2(150.0f, 360.0f), Vector2(50.0f, 60.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Trap", Resources::Find<Texture>(L"Bazzi_Trap"), Vector2(0.0f, 0.0f), Vector2(88.0f, 144.0f), 13, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Die", Resources::Find<Texture>(L"Bazzi_Die"), Vector2(0.0f, 0.0f), Vector2(88.0f, 144.0f), 13, Vector2(0.0f, 0.0f), 0.1f);

		mAnimator->PlayAnimation(L"Bazzi_Idle", true);
	}

	void Player::Update()
	{
		switch (mState)
		{
		case Player::eState::Idle:
			Idle();
			break;
		case Player::eState::Up:
			Up();
			break;
		case Player::eState::Left:
			Left();
			break;
		case Player::eState::Down:
			Down();
			break;
		case Player::eState::Right:
			Right();
			break;
		case Player::eState::DropWaterBomb:
			DropWaterBomb();
			break;
		case Player::eState::Death:
			Death();
			break;
		case Player::eState::End:
			break;
		default:
			break;
		}

		GameObject::Update();
	}

	void Player::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}

	void Player::OnCollisionEnter(Collider* _other)
	{
		Monster* monster = dynamic_cast<Monster*>(_other->GetOwner());
		Transform* monstertr = monster->GetComponent<Transform>();

		Vector2 MonsterPos = monstertr->GetPosition();
	}
	void Player::OnCollisionStay(Collider* _other)
	{
	}
	void Player::OnCollisionExit(Collider* _other)
	{
	}

	void Player::Idle()
	{
		if (Input::GetKeyDown(eKeyCode::W))
		{
			mAnimator->PlayAnimation(L"Bazzi_Up", true);
			mState = eState::Up;
		}
		else if (Input::GetKeyDown(eKeyCode::A))
		{
			mAnimator->PlayAnimation(L"Bazzi_Left", true);
			mState = eState::Left;
		}
		else if (Input::GetKeyDown(eKeyCode::S))
		{
			mAnimator->PlayAnimation(L"Bazzi_Down", true);
			mState = eState::Down;
		}
		else if (Input::GetKeyDown(eKeyCode::D))
		{
			mAnimator->PlayAnimation(L"Bazzi_Right", true);
			mState = eState::Right;
		}

		if (Input::GetKey(eKeyCode::LShift))
		{
			mState = eState::DropWaterBomb;
		}
	}

	void Player::Up()
	{
		Transform* TR = GetComponent<Transform>();
		Vector2 pos = TR->GetPosition();

		if (Input::GetKeyDown(eKeyCode::W))
		{
			pos.y -= 200.0f * Time::DeltaTime();
		}
		TR->SetPosition(pos);
		if (Input::GetKeyUp(eKeyCode::W))
		{
			mAnimator->PlayAnimation(L"Bazzi_Up_Idle", true);
			mState = eState::Idle;
		}
	}

	void Player::Left()
	{
		Transform* TR = GetComponent<Transform>();
		Vector2 pos = TR->GetPosition();

		if (Input::GetKeyDown(eKeyCode::A))
		{
			pos.x -= 200.0f * Time::DeltaTime();
		}
		TR->SetPosition(pos);
		if (Input::GetKeyUp(eKeyCode::A))
		{
			mAnimator->PlayAnimation(L"Bazzi_Left_Idle", true);
			mState = eState::Idle;
		}
	}

	void Player::Down()
	{
		Transform* TR = GetComponent<Transform>();
		Vector2 pos = TR->GetPosition();

		if (Input::GetKeyDown(eKeyCode::S))
		{
			pos.y += 200.0f * Time::DeltaTime();
		}
		TR->SetPosition(pos);
		if (Input::GetKeyUp(eKeyCode::S))
		{
			mAnimator->PlayAnimation(L"Bazzi_Down_Idle", true);
			mState = eState::Idle;
		}
	}

	void Player::Right()
	{
		Transform* TR = GetComponent<Transform>();
		Vector2 pos = TR->GetPosition();

		if (Input::GetKeyDown(eKeyCode::D))
		{
			pos.x += 200.0f * Time::DeltaTime();
		}
		TR->SetPosition(pos);
		if (Input::GetKeyUp(eKeyCode::D))
		{
			mAnimator->PlayAnimation(L"Bazzi_Right_Idle", true);
			mState = eState::Idle;
		}
	}

	void Player::DropWaterBomb()
	{
		Transform* transform = GetComponent<Transform>();
		Vector2 pos = transform->GetPosition();

		WaterBomb* WB = new WaterBomb;
		Transform* WBTR = WB->GetComponent<Transform>();
		WBTR->SetPosition(pos);
	}

	void Player::Death()
	{
	}
}