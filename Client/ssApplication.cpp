#include "ssApplication.h"


namespace ss
{
	Application::Application()
		: mHWND(NULL)
		, mHDC(NULL)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND HWND)
	{
		mHWND = HWND;
		mHDC = GetDC(mHWND);
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000 && mPos.x > 0)
		{
			mPos.x -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && mPos.x < 1484)
		{
			mPos.x += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000 && mPos.y > 0)
		{
			mPos.y -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000 && mPos.y < 741)
		{
			mPos.y += 0.01f;
		}
	}

	void Application::Render()
	{
		//Rectangle(mHdc, 100, 100, 200, 200);
		Ellipse(mHDC,mPos.x,mPos.y
			, 100 + mPos.x, 100 + mPos.y);
	}
}