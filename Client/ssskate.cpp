#include "ssskate.h"
#include "ssAnimator.h"
#include "ssResources.h"
#include "ssCollider.h"
#include "ssTexture.h"
#include "ssTransform.h"

namespace ss
{
	skate::skate()
		: mAnimator{}
		, mCollider{}
		, mTransform{ GetComponent<Transform>() }
		, mbCreated(true)
	{
		SetName(L"skate");
	}

	skate::~skate()
	{
	}

	void skate::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"skate", Resources::Find<Texture>(L"skate"), Vector2(0.0f, 0.0f), Vector2(56.0f, 70.0f), 2, Vector2(0.0f, 0.0f), 0.16f);

		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(50.0f, 60.0f));
	}

	void skate::Update()
	{
		if (mbCreated)
		{
			Idle();
		}

		Item::Update();
	}

	void skate::Render(HDC _hdc)
	{
		Item::Render(_hdc);
	}

	void skate::OnCollisionEnter(Collider* _other)
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

	void skate::OnCollisionStay(Collider* _other)
	{
	}

	void skate::OnCollisionExit(Collider* _other)
	{
	}

	void skate::Idle()
	{
		mAnimator->PlayAnimation(L"skate", true);
		mbCreated = false;
	}
}