#include "ssApplication.h"
#include "ssInput.h"
#include "ssTime.h"
#include "ssCircle.h"

std::vector<ss::Circle*> Circles;

namespace ss
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
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
		mHwnd = HWND;
		mHdc = GetDC(mHwnd);

		mWidth = 1600;
		mHeight = 900;


		RECT rect = { 0, 0, mWidth, mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHwnd
			, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(mHwnd, true);

		// 윈도우 해상도 동일한 비트맵 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		// 새로 생성한 비트맵을 가리키는 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

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

		// b 누를때마다 공 생성
		if (Input::GetKeyUp(eKeyCode::B))
		{
			Circle* circle123 = new Circle;
			Circles.push_back(circle123);
		}

		for (size_t i = 0; i < Circles.size(); i++)
		{
			Circles[i]->Update();
		}

		// 키입력
		if (Input::GetKey(eKeyCode::W))
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
		}
	}

	void Application::Render()
	{
		// 화면에 창크기만큼의 네모 그리기
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);

		Time::Render(mBackHdc);

		for (size_t i = 0; i < Circles.size(); i++)
		{
			Circles[i]->Render(mBackHdc);
		}

		Ellipse(mBackHdc, 100 + mPos.x, 100 + mPos.y, 200 + mPos.x, 200 + mPos.y);

		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}