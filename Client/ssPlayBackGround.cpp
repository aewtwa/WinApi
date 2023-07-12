#include "ssPlayBackGround.h"
#include "ssTransform.h"

namespace ss
{
	PlayBackGround::PlayBackGround()
	{
	}
	PlayBackGround::~PlayBackGround()
	{
	}
	void PlayBackGround::Initialize()
	{
	}
	void PlayBackGround::Update()
	{
		GameObject::Update();
	}
	void PlayBackGround::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}