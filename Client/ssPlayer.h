#pragma once
#include "ssGameObject.h"

namespace ss
{
	using namespace math;
	class Player : public GameObject
	{
	public:
		Player();
		virtual ~Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

	private:
		Vector2 mDirection;
	};
}
