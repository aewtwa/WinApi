#pragma once
#include "ssScene.h"

namespace ss
{
	using namespace math;
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		virtual ~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		Vector2 GetMapidx() { return Vector2(mMapidxX, mMapidxY); }

	private:
		UINT mMapidxX;
		UINT mMapidxY;
	};
}