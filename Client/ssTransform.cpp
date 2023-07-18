#include "ssTransform.h"
#include "ssInput.h"
#include "ssTime.h"

namespace ss
{
	Transform::Transform()
		: Component(eComponentType::Transform)
		, mRotation(0.0f)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
	}
	void Transform::Render(HDC _hdc)
	{
	}
}