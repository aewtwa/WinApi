#pragma once
#include "Commoninclude.h"
#include "ssMath.h"
#include "ssTime.h"

namespace ss
{
	using namespace math;
	class Circle
	{
	public:
		Circle()
			:mPos{}
			, mDirect{}
			,mTimecheck(0.0f)
			,mSpeed(300.0f)
		{
			int RandomX = GetRandomNumber(1500, 0);
			int RandomY = GetRandomNumber(780, 0);
			mPos.x = RandomX;
			mPos.y = RandomY;
		}
		void GetRandDirect();
		void Count();
		void Update();
		void Render(HDC hdc);

	private:
		Vector2 mPos;
		Vector2 mDirect;
		float mTimecheck;
		float mSpeed;
	};
}