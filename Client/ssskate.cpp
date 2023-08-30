#include "ssskate.h"

namespace ss
{
	skate::skate()
		: mAnimator{}
		, mCollider{}
		, mTransform{ GetComponent<Transform>() }
	{
	}

	skate::~skate()
	{
	}

	void skate::Initialize()
	{
		mAnimator = AddComponent<Animator>();
	}

	void skate::Update()
	{
	}

	void skate::Render(HDC _hdc)
	{
	}

	void skate::OnCollisionEnter(Collider* _other)
	{
	}

	void skate::OnCollisionStay(Collider* _other)
	{
	}

	void skate::OnCollisionExit(Collider* _other)
	{
	}
}