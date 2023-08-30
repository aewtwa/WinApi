#pragma once
#include "ssItem.h"

namespace ss
{
	using namespace math;
	class ballon : public Item
	{
	public:
		ballon();
		virtual ~ballon();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* _other);
		virtual void OnCollisionStay(class Collider* _other);
		virtual void OnCollisionExit(class Collider* _other);

	private:
		class Animator* mAnimator;
		class Collider* mCollider;
		class Transform* mTransform;
	};
}