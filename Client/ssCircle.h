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
			,mSpeed(500.0f)
		{
			mPos.x = 500.0f;
			mPos.y = 500.0f;
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