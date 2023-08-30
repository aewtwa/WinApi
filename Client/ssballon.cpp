#include "ssballon.h"
#include "ssAnimator.h"

namespace ss
{
	ballon::ballon()
		: mAnimator{}
		, mCollider{}
		, mTransform{ GetComponent<Transform>() }
	{
	}

	ballon::~ballon()
	{
	}

	void ballon::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimationFolder(L"ballon", L"..\\Resources\\Image\\Items\\ballon.bmp", Vector2(0.0f, 0.0f), 0.1f);
	}

	void ballon::Update()
	{
	}

	void ballon::Render(HDC _hdc)
	{
	}

	void ballon::OnCollisionEnter(Collider* _other)
	{
	}

	void ballon::OnCollisionStay(Collider* _other)
	{
	}

	void ballon::OnCollisionExit(Collider* _other)
	{
	}
}