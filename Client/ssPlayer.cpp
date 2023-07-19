#include "ssPlayer.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssInput.h"
#include "ssWaterBomb.h"

namespace ss
{
	Player::Player()
		:mDirection{}
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
			mDirection = Vector2(0.f, -1.f);
		}
		if (Input::GetKeyDown(eKeyCode::S) && Pos.y < 750.0f)
		{
			mDirection = Vector2(0.f, 1.f);
		}
		if (Input::GetKeyDown(eKeyCode::A) && Pos.x > 0.0f)
		{
			mDirection = Vector2(-1.f, 0.f);
		}
		if (Input::GetKeyDown(eKeyCode::D) && Pos.x < 1500.0f)
		{
			mDirection = Vector2(1.f, 0.f);
		}

		if (Input::GetKey(eKeyCode::LShift))
		{
			WaterBomb* WB = new WaterBomb;
			at->PlayAnimation(L"Bazzi_Idle", true);
		}

		if (Input::AllkeyNone())
		{
			mDirection = Vector2::Zero;
		}

		Pos.x += mDirection.x * 200.0f * Time::DeltaTime();
		Pos.y += mDirection.y * 200.0f * Time::DeltaTime();

		if (mDirection.y == -1.f)
		{
			at->PlayAnimation(L"Bazzi_Up", true);
		}
		else if (mDirection.y == 1.f)
		{
			at->PlayAnimation(L"Bazzi_Down", true);
		}
		else if (mDirection.x == -1.f)
		{
			at->PlayAnimation(L"Bazzi_Left", true);
		}
		else if (mDirection.x == 1.f)
		{
			at->PlayAnimation(L"Bazzi_Right", true);
		}

		tr->SetPosition(Pos);
	}
	void Player::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}