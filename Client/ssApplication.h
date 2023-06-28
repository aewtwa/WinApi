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

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void Render();

	private:
		HWND mHWND;
		HDC mHDC;

		Vector2 mPos;
	};
}
