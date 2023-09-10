#pragma once
#include "ssMonster.h"

namespace ss
{
	class Boss : public Monster
	{
	public:
		Boss();
		virtual ~Boss();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* _other) override;
		virtual void OnCollisionStay(class Collider* _other) override;
		virtual void OnCollisionExit(class Collider* _other) override;

		void Move() override;
		void Die() override;

	private:
		int mHp;
		std::bitset<static_cast<UINT>(eDirection::End)> mDirection;

		class Animator* mAnimator;
		class Collider* mCollider;
	};
}
