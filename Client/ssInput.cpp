#include "ssInput.h"
#include "ssApplication.h"

extern ss::Application application;

namespace ss
{
	std::vector<Input::Key> Input::mKeys = {};
	math::Vector2 Input::mMousePosition = math::Vector2::Zero;

	int ASCII[(int)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT,
		VK_LSHIFT,VK_RSHIFT,
		VK_LBUTTON, VK_RBUTTON, VK_MBUTTON,
		VK_SPACE
	};

	void Input::Initiailize()
	{
		for (size_t i = 0; i < (int)eKeyCode::End; i++)
		{
			Key key = {};
			key.code = (eKeyCode)i;
			key.state = eKeyState::None;
			key.bPressed = false;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < (int)eKeyCode::End; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Pressed;
				else
					mKeys[i].state = eKeyState::Down;

				mKeys[i].bPressed = true;
			}
			else
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Up;
				else
					mKeys[i].state = eKeyState::None;

				mKeys[i].bPressed = false;
			}
		}

		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetHwnd(), &mousePos);
		mMousePosition.x = (float)mousePos.x;
		mMousePosition.y = (float)mousePos.y;
	}
	bool Input::AllKeyNone()
	{
		for (size_t i = 0; i < (int)eKeyCode::End; i++)
		{
			if (GetKey((eKeyCode)i) == 1)
			{
				return false;
			}
			if (GetKeyDown((eKeyCode)i) == 1)
			{
				return false;
			}
		}
		return true;
	}
}