#pragma once
#include "ssItem.h"

namespace ss
{
	using namespace math;
	class potion : public Item
	{
	public:
		potion();
		virtual ~potion();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* _other) override;
		virtual void OnCollisionStay(class Collider* _other) override;
		virtual void OnCollisionExit(class Collider* _other) override;

		void Idle();

	private:
		class Animator* mAnimator;
		class Collider* mCollider;
		class Transform* mTransform;

		bool mbCreated;
	};
}