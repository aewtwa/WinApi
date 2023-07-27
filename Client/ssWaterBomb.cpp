#include "ssWaterBomb.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssCollider.h"
#include "ssResources.h"
#include "ssTexture.h"

namespace ss
{
	WaterBomb::WaterBomb()
		: mAnimator{}
		, mCollider{}
	{
		SetName(L"WaterBomb");
	}
	WaterBomb::~WaterBomb()
	{
	}
	void WaterBomb::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"WaterBomb", Resources::Find<Texture>(L"WaterBomb"), Vector2(0.0f, 0.0f), Vector2(44.0f, 41.0f), 3, Vector2(0.0f, 11.0f), 0.3f);

		mAnimator->PlayAnimation(L"WaterBomb");
		if (mAnimator->IsActiveAnimationComplete())
		{

		}
		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(44.0f, 41.0f));
		mCollider->SetOffset(Vector2(0.0f, 11.0f));

		GameObject::Initialize();
	}
	void WaterBomb::Update()
	{
		GameObject::Update();
	}
	void WaterBomb::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
	void WaterBomb::OnCollisionEnter(Collider* _other)
	{
	}
	void WaterBomb::OnCollisionStay(Collider* other)
	{
	}
	void WaterBomb::OnCollisionExit(Collider* other)
	{
	}
}