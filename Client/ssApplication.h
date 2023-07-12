#pragma once
#include "Commoninclude.h"

namespace ss
{
	using namespace math;
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND _hwnd);
		void Run();
		void Update();
		void Render();

		HWND GetHwnd() { return mHwnd; }
		HDC GetHdc() { return mHdc; }

	private:
		HWND mHwnd;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;

		HDC mBackHdc;
		HBITMAP mBackBuffer;
	};
}