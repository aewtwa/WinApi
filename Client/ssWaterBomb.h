#pragma once
#include "ssGameObject.h"

namespace ss
{
	class WaterBomb : public GameObject
	{
	public:
		WaterBomb();
		virtual ~WaterBomb();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

	private:
		std::bitset<(int)eDirectionType::End> mPlayerDirection;
	};
}
