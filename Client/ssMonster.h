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

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

	};
}