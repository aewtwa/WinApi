#include "ssPlayGround.h"

namespace ss
{
	PlayGround::PlayGround()
	{
	}

	PlayGround::~PlayGround()
	{
	}

	void PlayGround::Initialize()
	{
	}

	void PlayGround::Update()
	{
		GameObject::Update();
	}
	void PlayGround::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}