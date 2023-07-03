#include "ssApplication.h"
#include "ssInput.h"
#include "ssTime.h"
#include <time.h>

namespace ss
{
	Application::Application()
		: mHWND(NULL)
		, mHDC(NULL)
		, mDirect(rand() % 8)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND HWND)
	{
		mHWND = HWND;
		mHDC = GetDC(mHWND);

		Time::Initailize();
		Input::Initailize();
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();

		if (mDirect == 0)
		{
			mPos.y -= 500.0f * Time::DeltaTime();
			if (mPos.y <= 0)
			{
				mDirect = rand() % 8;
			}
		}
		else if (mDirect == 1)
		{
			mPos.x += 500.0f * Time::DeltaTime();
			mPos.y -= 500.0f * Time::DeltaTime();
			if (mPos.x >= 1484 || mPos.y <= 0)
			{
				mDirect = rand() % 8;
			}
		}
		else if (mDirect == 2)
		{
			mPos.x += 500.0f * Time::DeltaTime();
			if (mPos.x >= 1484)
			{
				mDirect = rand() % 8;
			}
		}
		else if (mDirect == 3)
		{
			mPos.x += 500.0f * Time::DeltaTime();
			mPos.y += 500.0f * Time::DeltaTime();
			if (mPos.x >= 1484 || mPos.y >= 741)
			{
				mDirect = rand() % 8;
			}
		}
		else if (mDirect == 4)
		{
			mPos.y += 500.0f * Time::DeltaTime();
			if (mPos.y >= 741)
			{
				mDirect = rand() % 8;
			}
		}
		else if (mDirect == 5)
		{
			mPos.x -= 500.0f * Time::DeltaTime();
			mPos.y += 500.0f * Time::DeltaTime();
			if (mPos.y >= 741 || mPos.x <= 0)
			{
				mDirect = rand() % 8;
			}
		}
		else if (mDirect == 6)
		{
			mPos.x -= 500.0f * Time::DeltaTime();
			if (mPos.x <= 0)
			{
				mDirect = rand() % 8;
			}
		}
		else if (mDirect == 7)
		{
			mPos.x -= 500.0f * Time::DeltaTime();
			mPos.y -= 500.0f * Time::DeltaTime();
			if (mPos.y <= 0 || mPos.x <= 0)
			{
				mDirect = rand() % 8;
			}
		}
		
		/*if (Input::GetKey(eKeyCode::W))
		{
			mPos.y -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			mPos.x -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mPos.y += 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mPos.x += 300.0f * Time::DeltaTime();
		}*/
	}

	void Application::Render()
	{
		Time::Render(mHDC);
		//Rectangle(mHdc, 100, 100, 200, 200);
		InvalidateRect(mHWND, NULL, true);
		Ellipse(mHDC, mPos.x, mPos.y, 100 + mPos.x, 100 + mPos.y);
	}
}