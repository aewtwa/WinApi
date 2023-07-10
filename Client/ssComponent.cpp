#include "ssComponent.h"

namespace ss
{
	Component::Component(eComponentType _type)
		: mType(_type)
		, mOwner(nullptr)
	{
	}
	Component::~Component()
	{
	}
	void Component::Initialize()
	{
	}
	void Component::Update()
	{
	}
	void Component::Render(HDC _hdc)
	{
	}
}
