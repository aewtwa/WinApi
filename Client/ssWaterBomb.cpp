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
		: mTransform{ GetComponent<Transform>() }
		, mPos()
		, mAnimator{}
		, mCollider{}
	{
	}
	WaterBomb::~WaterBomb()
	{
	}
	void WaterBomb::Initialize()
	{
		mPos = mTransform->GetPosition();
		mPos = Vector2(250.0f, 250.0f);
		mTransform->SetPosition(mPos);

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"WaterBomb", Resources::Find<Texture>(L"WaterBomb"), Vector2(0.0f, 0.0f), Vector2(44.0f, 41.0f), 3, Vector2(0.0f, 0.0f), 0.3f);
		mAnimator->PlayAnimation(L"WaterBomb", true);
		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(44.0f, 41.0f));

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