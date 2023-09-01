#pragma once
#include "ssStatObject.h"

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
	class WaterBomb : public StatObject
	{
	public:
		WaterBomb();
		virtual ~WaterBomb();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* _other) override;
		virtual void OnCollisionStay(class Collider* _other) override;
		virtual void OnCollisionExit(class Collider* _other) override;

		void Created();
		void Idle();

		StatObject* GetOwner() const { return mOwner; }
		void SetOwner(StatObject* _Owner) { mOwner = _Owner; }

	private:
		class Animator* mAnimator;
		class Collider* mCollider;
		class Transform* mTransform;

		float mBombtime;

		std::bitset<static_cast<UINT>(eWaterBombState::End)> mState;
		std::bitset<static_cast<UINT>(eDirection::End)> mDirection;

		StatObject* mOwner;
		Vector2 mPos;
	};
}
