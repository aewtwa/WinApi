#pragma once
#include "ssGameObject.h"

namespace ss
{
	class PlayGround : public GameObject
	{
	public:
		PlayGround();
		virtual ~PlayGround();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

	private:

	};
}