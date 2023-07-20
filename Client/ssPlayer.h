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
			Death,
			End
		};

		Player();
		virtual ~Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void Idle();
		void Move();
		void DropWaterBomb();
		void Death();
	private:
		eState mState;
	};
}
