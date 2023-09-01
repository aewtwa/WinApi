#pragma once
#include "ssStatObject.h"

namespace ss
{
	using namespace math;
	class Player : public StatObject
	{
	public:
		enum class eState
		{
			Idle,
			Move,
			DropWaterBomb,
			Trap,
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
		void Move();
		void Trap();
		void DropWaterBomb() override;
		void CollideWall(Collider* _other) override;

	private:
		std::bitset<static_cast<UINT>(eState::End)> mState;

		class Animator* mAnimator;
		class Collider* mCollider;

		float mDeathTime;
		bool mOnCollision;
	};
}
