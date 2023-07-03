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
		int Direct();
		static void Count();
		static void Update();
		static void Render(HDC hdc);

	private:
		Vector2 mPos;
		static float Timecheck;
	};
}

