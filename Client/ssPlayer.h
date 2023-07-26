#pragma once
#include "ssGameObject.h"

namespace ss
{
	using namespace math;
	class Player : public GameObject
	{
	public:
		enum class eState
		{
			Idle,
			Up,
			Left,
			Down,
			Right,
			DropWaterBomb,
			Death,
			End
		};

		Player();
		virtual ~Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* _other) override;
		virtual void OnCollisionStay(class Collider* _other) override;
		virtual void OnCollisionExit(class Collider* _other) override;

		void Idle();
		void Up();
		void Left();
		void Down();
		void Right();
		void DropWaterBomb();
		void Death();
	private:
		eState mState;
		class Transform* mTransform;
		Vector2 mPos;
		class Animator* mAnimator;
		class Collider* mCollider;
	};
}
