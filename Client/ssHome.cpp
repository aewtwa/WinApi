#include "ssHome.h"
#include "ssTransform.h"

namespace ss
{
	Home::Home()
	{
	}
	Home::~Home()
	{
	}
	void Home::Initialize()
	{
	}
	void Home::Update()
	{
		GameObject::Update();
	}
	void Home::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}