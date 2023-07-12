#include "ssEnding.h"
#include "ssTransform.h"

namespace ss
{
	Ending::Ending()
	{
	}
	Ending::~Ending()
	{
	}
	void Ending::Initialize()
	{
	}
	void Ending::Update()
	{
		GameObject::Update();
	}
	void Ending::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}