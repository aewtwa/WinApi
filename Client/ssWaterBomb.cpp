#include "ssWaterBomb.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssPlayer.h"

namespace ss
{
	WaterBomb::WaterBomb()
	{
	}
	WaterBomb::~WaterBomb()
	{
	}
	void WaterBomb::Initialize()
	{
	}
	void WaterBomb::Update()
	{
		GameObject::Update();
		Transform* tr = GetComponent<Transform>();
		Animator* at = GetComponent<Animator>();
		Vector2 pos = tr->GetPosition();
	}
	void WaterBomb::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}