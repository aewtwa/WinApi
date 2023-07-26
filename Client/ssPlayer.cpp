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
#include "ssObject.h"

namespace ss
{
	Player::Player()
		: mState(eState::Idle)
		, mTransform{ GetComponent<Transform>() }
		, mPos()
		, mAnimator{}
		, mCollider{}
	{
	}

	Player::~Player()
	{
	}

	void Player::Initialize()
	{
		mPos = mTransform->GetPosition();
		mPos = Vector2(100.0f, 100.0f);
		mTransform->SetPosition(mPos);

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

		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(50.0f, 60.0f));

		GameObject::Initialize();
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
		// waterbomb을 넣을때 monster로 다이나믹캐스트하려해서 null반환
		//Monster* monster = dynamic_cast<Monster*>(_other->GetOwner());


		//Transform* monstertr = monster->GetComponent<Transform>();

		//Vector2 MonsterPos = monstertr->GetPosition();
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
		if (Input::GetKeyDown(eKeyCode::W))
		{
			mPos.y -= 200.0f * Time::DeltaTime();
		}
		mTransform->SetPosition(mPos);
		if (Input::GetKeyUp(eKeyCode::W))
		{
			mAnimator->PlayAnimation(L"Bazzi_Up_Idle", true);
			mState = eState::Idle;
		}
		if (Input::GetKey(eKeyCode::LShift))
		{
			mState = eState::DropWaterBomb;
		}
	}

	void Player::Left()
	{
		if (Input::GetKeyDown(eKeyCode::A))
		{
			mPos.x -= 200.0f * Time::DeltaTime();
		}
		mTransform->SetPosition(mPos);
		if (Input::GetKeyUp(eKeyCode::A))
		{
			mAnimator->PlayAnimation(L"Bazzi_Left_Idle", true);
			mState = eState::Idle;
		}
		if (Input::GetKey(eKeyCode::LShift))
		{
			mState = eState::DropWaterBomb;
		}
	}

	void Player::Down()
	{
		if (Input::GetKeyDown(eKeyCode::S))
		{
			mPos.y += 200.0f * Time::DeltaTime();
		}
		mTransform->SetPosition(mPos);
		if (Input::GetKeyUp(eKeyCode::S))
		{
			mAnimator->PlayAnimation(L"Bazzi_Down_Idle", true);
			mState = eState::Idle;
		}
		if (Input::GetKey(eKeyCode::LShift))
		{
			mState = eState::DropWaterBomb;
		}
	}

	void Player::Right()
	{
		if (Input::GetKeyDown(eKeyCode::D))
		{
			mPos.x += 200.0f * Time::DeltaTime();
		}
		mTransform->SetPosition(mPos);
		if (Input::GetKeyUp(eKeyCode::D))
		{
			mAnimator->PlayAnimation(L"Bazzi_Right_Idle", true);
			mState = eState::Idle;
		}
		if (Input::GetKey(eKeyCode::LShift))
		{
			mState = eState::DropWaterBomb;
		}
	}

	void Player::DropWaterBomb()
	{
		//WaterBomb* WB = new WaterBomb;
		WaterBomb* WB = Object::Instantiate<WaterBomb>(eLayerType::WaterBomb);
		Transform* WBTF = WB->GetComponent<Transform>();
		WBTF->SetPosition(mPos);

		mState = eState::Idle;
	}

	void Player::Death()
	{

	}
}