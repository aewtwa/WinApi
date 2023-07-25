#include "ssWaterBomb.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssPlayer.h"
#include "ssObject.h"

namespace ss
{
	WaterBomb::WaterBomb()
		:mPos(Vector2(0.0f, 0.0f))
		, mTransform{}
		, mAnimator{}
	{
	}
	WaterBomb::~WaterBomb()
	{
	}
	void WaterBomb::Initialize()
	{

		mPos = mTransform->GetPosition();
		mTransform = GetComponent<Transform>();
		mAnimator = GetComponent<Animator>();
	}
	void WaterBomb::Update()
	{
		GameObject::Update();
	}
	void WaterBomb::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}