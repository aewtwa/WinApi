#pragma once
#include "ssStatObject.h"

namespace ss
{
	class Monster : public StatObject
	{
	public:
		Monster();
		virtual ~Monster();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* _other) override;
		virtual void OnCollisionStay(class Collider* _other) override;
		virtual void OnCollisionExit(class Collider* _other) override;

		virtual void Move();
		virtual void Die();

		bool GetisDeath() { return mbDeath; }
		void SetisDeath(bool _death) { mbDeath = _death; }

	private:
		bool mbDeath;
	};
}