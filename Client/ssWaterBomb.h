#pragma once
#include "ssGameObject.h"

namespace ss
{
	enum class eWaterBombState
	{
		Created,
		Idle,
		Flow,
		End,
	};

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

		void Created();
		void Idle();
		void Bomb();

		void SetDirection(eDirection dir);
		bool GetWaterBombState(eWaterBombState state);

	private:
		class Animator* mAnimator;
		class Collider* mCollider;
		class Transform* mTransform;

		float mBombtime;

		std::bitset<static_cast<UINT>(eWaterBombState::End)> mState;
		std::bitset<static_cast<UINT>(eDirection::End)> mDirection;


		Vector2 mPos;
	};
}
