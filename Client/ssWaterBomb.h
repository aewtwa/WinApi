#pragma once
#include "ssGameObject.h"

namespace ss
{
	using namespace math;
	class WaterBomb : public GameObject
	{
	public:
		WaterBomb();
		virtual ~WaterBomb();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

	private:
		Vector2 mPos;
	};
}
