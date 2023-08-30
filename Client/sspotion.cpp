#include "sspotion.h"

namespace ss
{
	potion::potion()
		: mAnimator{}
		, mCollider{}
		, mTransform{ GetComponent<Transform>() }
	{
	}

	potion::~potion()
	{
	}

	void potion::Initialize()
	{
		mAnimator = AddComponent<Animator>();
	}

	void potion::Update()
	{
	}

	void potion::Render(HDC _hdc)
	{
	}

	void potion::OnCollisionEnter(Collider* _other)
	{
	}

	void potion::OnCollisionStay(Collider* _other)
	{
	}

	void potion::OnCollisionExit(Collider* _other)
	{
	}
}