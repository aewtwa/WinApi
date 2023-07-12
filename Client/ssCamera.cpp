#include "ssCamera.h"
#include "ssApplication.h"
#include "ssTransform.h"
#include "ssInput.h"
#include "ssTime.h"

extern ss::Application application;

namespace ss
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;


	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = mResolution / 2.0f;
	}

	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}

		// 카메라 이동
		/*if (Input::GetKey(eKeyCode::W) && mLookPosition.y > 0.0f)
		{
			mLookPosition.y -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A) && mLookPosition.x > 0.0f)
		{
			mLookPosition.x -= 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S) && mLookPosition.y < 750.0f)
		{
			mLookPosition.y += 300.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D) && mLookPosition.x < 1500.0f)
		{
			mLookPosition.x += 300.0f * Time::DeltaTime();
		}*/

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
}
