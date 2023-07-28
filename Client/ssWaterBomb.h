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

		void Bomb();

	private:
		class Animator* mAnimator;
		class Collider* mCollider;
		class Transform* mTransform;
		float mBombtime;
		bool mbBomb;
	};
}
