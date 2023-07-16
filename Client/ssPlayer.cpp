#include "ssPlayer.h"
#include "ssTransform.h"
#include "ssInput.h"
#include "ssTime.h"
#include "ssAnimator.h"

namespace ss
{
	Player::Player()
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
		Vector2 pos = tr->GetPosition();

		if (Input::GetKeyDown(eKeyCode::W) && pos.y > 0.0f)
		{
			pos.y -= 300.0f * Time::DeltaTime();
		}
		else if (Input::GetKeyDown(eKeyCode::A) && pos.x > 0.0f)
		{
			pos.x -= 300.0f * Time::DeltaTime();
		}
		else if (Input::GetKeyDown(eKeyCode::S) && pos.y < 750.0f)
		{
			pos.y += 300.0f * Time::DeltaTime();
		}
		else if (Input::GetKeyDown(eKeyCode::D) && pos.x < 1500.0f)
		{
			pos.x += 300.0f * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W))
		{
			at->PlayAnimation(L"Bazzi_Up", true);
		}
		else if (Input::GetKey(eKeyCode::A))
		{
			at->PlayAnimation(L"Bazzi_Left", true);
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			at->PlayAnimation(L"Bazzi_Down", true);
		}
		else if (Input::GetKey(eKeyCode::D))
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

		if (Input::GetKeyUp(eKeyCode::B))
		{
			at->PlayAnimation(L"WaterBomb_Idle", true);
		}

		tr->SetPosition(pos);
	}
	void Player::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}