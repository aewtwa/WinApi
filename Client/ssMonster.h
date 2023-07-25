#pragma once
#include "ssGameObject.h"

namespace ss
{
	class Monster : public GameObject
	{
	public:
		Monster();
		virtual ~Monster();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* _other);
		virtual void OnCollisionStay(class Collider* _other);
		virtual void OnCollisionExit(class Collider* _other);

	};
}