#include "ssPlayer.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssInput.h"
#include "ssWaterBomb.h"

namespace ss
{
	Player::Player()
		:mDirection(0)
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

		Transform* tr = GetComponent<Transform>();
		Animator* at = GetComponent<Animator>();
		Vector2 Pos = tr->GetPosition();

		if (Input::GetKeyDown(eKeyCode::W) && Pos.y > 0.0f)
		{
			Pos.y -= 300.0f * Time::DeltaTime();
			mDirection = 1;
		}
		else if (Input::GetKeyDown(eKeyCode::S) && Pos.y < 750.0f)
		{
			Pos.y += 300.0f * Time::DeltaTime();
			mDirection = 2;
		}
		else if (Input::GetKeyDown(eKeyCode::A) && Pos.x > 0.0f)
		{
			Pos.x -= 300.0f * Time::DeltaTime();
			mDirection = 3;
		}
		else if (Input::GetKeyDown(eKeyCode::D) && Pos.x < 1500.0f)
		{
			Pos.x += 300.0f * Time::DeltaTime();
			mDirection = 4;
		}

		if (mDirection == 1)
		{
			at->PlayAnimation(L"Bazzi_Up", true);
		}
		else if (mDirection == 2)
		{
			at->PlayAnimation(L"Bazzi_Left", true);
		}
		else if (mDirection == 3)
		{
			at->PlayAnimation(L"Bazzi_Down", true);
		}
		else if (mDirection == 4)
		{
			at->PlayAnimation(L"Bazzi_Right", true);
		}

		if (Input::GetKeyUp(eKeyCode::W))
		{
			at->PlayAnimation(L"Bazzi_Up_Idle", false);
		}
		else if (Input::GetKeyUp(eKeyCode::A))
		{
			at->PlayAnimation(L"Bazzi_Left_Idle", false);
		}
		else if (Input::GetKeyUp(eKeyCode::S))
		{
			at->PlayAnimation(L"Bazzi_Down_Idle", false);
		}
		else if (Input::GetKeyUp(eKeyCode::D))
		{
			at->PlayAnimation(L"Bazzi_Right_Idle", false);
		}

		if (Input::GetKey(eKeyCode::LShift))
		{
			WaterBomb* WB = new WaterBomb;
			at->PlayAnimation(L"Bazzi_Idle", true);
		}

		tr->SetPosition(Pos);
	}
	void Player::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}