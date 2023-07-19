#include "ssPlayer.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssInput.h"
#include "ssWaterBomb.h"

namespace ss
{
	Player::Player()
		: mState(eState::Idle)
	{
	}

	Player::~Player()
	{
	}

	void Player::Initialize()
	{
	}

	void Player::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case ss::Player::eState::Idle:
			Idle();
			break;
		case ss::Player::eState::Move:
			Move();
			break;
		case ss::Player::eState::DropWaterBomb:
			DropWaterBomb();
			break;
		case ss::Player::eState::Death:
			Death();
			break;
		case ss::Player::eState::End:
			break;
		default:
			break;
		}
	}

	void Player::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}

	void Player::Idle()
	{
		Animator* animator = GetComponent<Animator>();

		if (Input::GetKeyDown(eKeyCode::W))
		{
			animator->PlayAnimation(L"Bazzi_Up", true);
			mState = eState::Move;
		}
		else if (Input::GetKeyDown(eKeyCode::A))
		{
			animator->PlayAnimation(L"Bazzi_Left", true);
			mState = eState::Move;
		}
		else if (Input::GetKeyDown(eKeyCode::S))
		{
			animator->PlayAnimation(L"Bazzi_Down", true);
			mState = eState::Move;
		}
		else if (Input::GetKeyDown(eKeyCode::D))
		{
			animator->PlayAnimation(L"Bazzi_Right", true);
			mState = eState::Move;
		}
	}

	void Player::Move()
	{
		Transform* transform = GetComponent<Transform>();
		Vector2 pos = transform->GetPosition();

		if (Input::GetKeyDown(eKeyCode::W))
		{
			pos.y -= 200.0f * Time::DeltaTime();
		}
		else if (Input::GetKeyDown(eKeyCode::A))
		{
			pos.x -= 200.0f * Time::DeltaTime();
		}
		else if (Input::GetKeyDown(eKeyCode::S))
		{
			pos.y += 200.0f * Time::DeltaTime();
		}
		else if (Input::GetKeyDown(eKeyCode::D))
		{
			pos.x += 200.0f * Time::DeltaTime();
		}
		transform->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::W)
			|| Input::GetKeyUp(eKeyCode::A)
			|| Input::GetKeyUp(eKeyCode::S)
			|| Input::GetKeyUp(eKeyCode::D))
		{
			Animator* animator = GetComponent<Animator>();
			animator->PlayAnimation(L"Bazzi_Idle", true);
			mState = eState::Idle;
		}
	}

	void Player::DropWaterBomb()
	{
	}

	void Player::Death()
	{
	}
}