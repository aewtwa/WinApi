#pragma once
#include "ssGameObject.h"

namespace ss
{
	class PlayBackGround : public GameObject
	{
	public:
		PlayBackGround();
		virtual ~PlayBackGround();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

	private:

	};
}