#pragma once
#include "ssGameObject.h"

namespace ss
{
	using namespace math;
	class WaterBomb : public GameObject
	{
	public:
		WaterBomb();
		virtual ~WaterBomb();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* _other);
		virtual void OnCollisionStay(class Collider* _other);
		virtual void OnCollisionExit(class Collider* _other);

	private:
		class Transform* mTransform;
		Vector2 mPos;
		class Animator* mAnimator;
		class Collider* mCollider;
	};
}
