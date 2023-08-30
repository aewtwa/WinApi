#include "ssTransform.h"
#include "ssAnimator.h"
#include "ssCollider.h"
#include "ssItem.h"

namespace ss
{
	ss::Item::Item()
		: mAnimator{}
		, mCollider{}
		, mTransform{ GetComponent<Transform>() }
	{
	}

	Item::~Item()
	{
	}

	void Item::Initialize()
	{
		GameObject::Initialize();
	}

	void Item::Update()
	{
		GameObject::Update();
	}

	void Item::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}

	void Item::OnCollisionEnter(Collider* _other)
	{
	}

	void Item::OnCollisionStay(Collider* _other)
	{
	}

	void Item::OnCollisionExit(Collider* _other)
	{
	}
}