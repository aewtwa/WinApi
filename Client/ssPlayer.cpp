#include "ssPlayer.h"
#include "ssTransform.h"
#include "ssInput.h"
#include "ssTime.h"

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
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::W) && pos.y > 0.0f)
		{
			pos.y -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A) && pos.x > 0.0f)
		{
			pos.x -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S) && pos.y < 750.0f)
		{
			pos.y += 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D) && pos.x < 1500.0f)
		{
			pos.x += 300.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);
	}
	void Player::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}