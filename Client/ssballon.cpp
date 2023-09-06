#include "ssballon.h"
#include "ssAnimator.h"
#include "ssResources.h"
#include "ssCollider.h"
#include "ssTexture.h"
#include "ssTransform.h"

namespace ss
{
	ballon::ballon()
		: mAnimator{}
		, mCollider{}
		, mTransform{ GetComponent<Transform>() }
		, mbCreated(true)
	{
		SetName(L"ballon");
	}

	ballon::~ballon()
	{
	}

	void ballon::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"ballon", Resources::Find<Texture>(L"ballon"), Vector2(0.0f, 0.0f), Vector2(56.0f, 70.0f), 2, Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->SetScale(Vector2(0.8f, 0.8f));
		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(40.0f, 50.0f));
	}

	void ballon::Update()
	{
		if (mbCreated)
		{
			Idle();
		}

		Item::Update();
	}

	void ballon::Render(HDC _hdc)
	{
		Item::Render(_hdc);
	}

	void ballon::OnCollisionEnter(Collider* _other)
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

	void ballon::OnCollisionStay(Collider* _other)
	{
	}

	void ballon::OnCollisionExit(Collider* _other)
	{

	}

	void ballon::Idle()
	{
		mAnimator->PlayAnimation(L"ballon", true);
		mbCreated = false;
	}
}