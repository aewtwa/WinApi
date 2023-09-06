#include "sspotion.h"
#include "ssAnimator.h"
#include "ssResources.h"
#include "ssCollider.h"
#include "ssTexture.h"
#include "ssTransform.h"

namespace ss
{
	potion::potion()
		: mAnimator{}
		, mCollider{}
		, mTransform{ GetComponent<Transform>() }
		, mbCreated(true)
	{
		SetName(L"potion");
	}

	potion::~potion()
	{
	}

	void potion::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"potion", Resources::Find<Texture>(L"potion"), Vector2(0.0f, 0.0f), Vector2(56.0f, 70.0f), 2, Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->SetScale(Vector2(0.8f, 0.8f));
		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(40.0f, 50.0f));
	}

	void potion::Update()
	{
		if (mbCreated)
		{
			Idle();
		}

		Item::Update();
	}

	void potion::Render(HDC _hdc)
	{
		Item::Render(_hdc);
	}

	void potion::OnCollisionEnter(Collider* _other)
	{
		if (L"Player" == _other->GetOwner()->GetName())
		{
			Destroy(this);
		}
		if (L"WaterFlow" == _other->GetOwner()->GetName())
		{
			Destroy(this);
		}
	}

	void potion::OnCollisionStay(Collider* _other)
	{
	}

	void potion::OnCollisionExit(Collider* _other)
	{
	}
	void potion::Idle()
	{
		mAnimator->PlayAnimation(L"potion", true);
		mbCreated = false;
	}
}