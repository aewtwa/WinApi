#include "ssApplication.h"
#include "ssInput.h"
#include "ssTime.h"
#include "ssCircle.h"

std::vector<ss::Circle*> Circles;

namespace ss
{
	Application::Application()
		: mHWND(NULL)
		, mHDC(NULL)
		, mWidth(0)
		, mHeight(0)
		, mBackBuffer(NULL)
		, mBackHdc(NULL)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND HWND)
	{
		mHWND = HWND;
		mHDC = GetDC(mHWND);

		mWidth = 1600;
		mHeight = 900;


		RECT rect = { 0, 0, mWidth, mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHWND
			, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(mHWND, true);

		// 윈도우 해상도 동일한 비트맵 생성
		mBackBuffer = CreateCompatibleBitmap(mHDC, mWidth, mHeight);

		// 새로 생성한 비트맵을 가리키는 DC 생성
		mBackHdc = CreateCompatibleDC(mHDC);

		// 새로 생성한 비트맵과 DC를 서로 연결
		HBITMAP defaultBitmap
			= (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(defaultBitmap);

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

		// w 누를때마다 공 생성
		if (Input::GetKeyUp(eKeyCode::W))
		{
			Circle* circle123 = new Circle;
			Circles.push_back(circle123);
		}
		for (size_t i = 0; i < Circles.size(); i++)
		{
			Circles[i]->Update();
		}

		// 키입력
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

		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);

		for (size_t i = 0; i < Circles.size(); i++)
		{
			Circles[i]->Render(mHDC);
		}

		BitBlt(mHDC, 0, 0, mWidth, mHeight , mBackHdc, 0, 0, SRCCOPY);
	}
}