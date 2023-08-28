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

		Vector2 GetMapIDX();
		Vector2 GetPos() { return mPos; }

		void Idle();
		void Move();
		void DropWaterBomb();
		void Trap();

		void SetDirection(eDirection _dir);
		eDirection CurDirection_flag();
		Vector2 CurDirection();

		int GetWaterBombs() { return mWaterBombs; }
		void SetWaterBombs(int _WaterBombs) { mWaterBombs = _WaterBombs; }
		int GetWaterBombPower() { return mWaterBombPower; }
		void SetWaterBombPower(int _WaterBombPower) { mWaterBombPower = _WaterBombPower; }

	private:
		std::bitset<static_cast<UINT>(eState::End)> mState;
		std::bitset<static_cast<UINT>(eDirection::End)> mDirection;
		class Transform* mTransform;
		Vector2 mPos;
		class Animator* mAnimator;
		class Collider* mCollider;
		float mDeathTime;
		bool mOnCollision;

		float mSpeed;
		int mWaterBombs;
		int mWaterBombPower;
	};
}
