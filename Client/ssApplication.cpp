#include "ssApplication.h"
#include "ssInput.h"

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

		Input::Initailize();
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Input::Update();

		if (Input::GetKey(eKeyCode::W))
		{
			mPos.y -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::A))
		{
			mPos.x -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mPos.y += 0.01f;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mPos.x += 0.01f;
		}
	}

	void Application::Render()
	{
		//Rectangle(mHdc, 100, 100, 200, 200);
		Ellipse(mHDC,mPos.x,mPos.y
			, 100 + mPos.x, 100 + mPos.y);
	}
}