#include "ssCircle.h"
#include <iostream>

namespace ss
{
	

	void Circle::GetRandDirect()
	{
		int RandomX = GetRandomNumber(3, -1);
		int RandomY = GetRandomNumber(3, -1);
		/*void* Random = new int;
		srand((int)Random);*/
		mDirect.y = RandomX;
		mDirect.x = RandomY;

		//delete Random;
	}

	void Circle::Count()
	{
		if (mTimecheck < 1.0f)
		{
			mTimecheck += Time::DeltaTime();
		}
		else
		{
			GetRandDirect();
			mTimecheck = 0;
		}
	}

	void Circle::Update()
	{
		Circle::Count();

		if (mPos.x <= 0.0f || mPos.x >= 1500.0f)
			mDirect.x = -mDirect.x;
		if (mPos.y <= 0.0f || mPos.y >= 780.0f)
			mDirect.y = -mDirect.y;

		mPos.x += mDirect.x * Time::DeltaTime() * mSpeed;
		mPos.y += mDirect.y * Time::DeltaTime() * mSpeed;
	}

	void Circle::Render(HDC hdc)
	{
		Ellipse(hdc, mPos.x, mPos.y, 100.0f + mPos.x, 100.0f + mPos.y);
	}
}
