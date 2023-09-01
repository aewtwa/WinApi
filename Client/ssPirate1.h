#pragma once
#include "ssMonster.h"

namespace ss
{
	using namespace math;
	class Pirate1 : public Monster
	{
	public:
		Pirate1();
		virtual ~Pirate1();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* _other) override;
		virtual void OnCollisionStay(class Collider* _other) override;
		virtual void OnCollisionExit(class Collider* _other) override;

		void Move() override;
		void Die() override;
	
	private:
		std::bitset<static_cast<UINT>(eDirection::End)> mDirection;

		class Animator* mAnimator;
		class Collider* mCollider;
	};
}