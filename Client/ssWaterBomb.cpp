#include "ssWaterBomb.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssCollider.h"
#include "ssResources.h"
#include "ssTexture.h"
#include "ssPlayer.h"
#include "ssObject.h"
#include "ssWaterFlow.h"

namespace ss
{
	WaterBomb::WaterBomb()
		: mAnimator{}
		, mCollider{}
		, mTransform{ GetComponent<Transform>() }
		, mBombtime(0.0f)
		, mPos(Vector2::Zero)
		, mState{}
		, mDirection{}
	{
		SetName(L"WaterBomb");
	}

	WaterBomb::~WaterBomb()
	{
	}

	void WaterBomb::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimationFolder(L"WaterBombIdle", L"..\\Resources\\Image\\Bomb\\Idle", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"BombCenterflow", L"..\\Resources\\Image\\Bomb\\Centerflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombLeftflow", L"..\\Resources\\Image\\Bomb\\Leftflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombRightflow", L"..\\Resources\\Image\\Bomb\\Rightflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombUpflow", L"..\\Resources\\Image\\Bomb\\Upflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombDownflow", L"..\\Resources\\Image\\Bomb\\Downflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->SetScale(Vector2(1.2f, 1.2f));

		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(50.0f, 50.0f));

		mState[static_cast<UINT>(eWaterBombState::Created)] = true;

		GameObject::Initialize();
	}
	void WaterBomb::Update()
	{
		if (mState[static_cast<UINT>(eWaterBombState::Created)])
		{
			Created();
		}
		if (mState[static_cast<UINT>(eWaterBombState::Idle)])
		{
			Idle();
		}
		if (mState[static_cast<UINT>(eWaterBombState::Flow)])
		{
			if (mAnimator->IsActiveAnimationComplete())
			{
				Destroy(this);
			}
		}

		GameObject::Update();
	}
	void WaterBomb::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
	void WaterBomb::OnCollisionEnter(Collider* _other)
	{
	}
	void WaterBomb::OnCollisionStay(Collider* other)
	{
	}
	void WaterBomb::OnCollisionExit(Collider* other)
	{
	}

	void WaterBomb::Created()
	{
		mAnimator->PlayAnimation(L"WaterBombIdle", true);
		mState.reset();
		mState[static_cast<UINT>(eWaterBombState::Idle)] = true;
	}

	void WaterBomb::Idle()
	{
		if (2.0f < mBombtime)
		{
			//Bomb();
			mPos = mTransform->GetPosition();
			WaterFlow* WF = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, mPos);
		}
		else
		{
			mBombtime += Time::DeltaTime();
		}

	}

	void WaterBomb::Bomb()
	{
		mAnimator->PlayAnimation(L"BombCenterflow", false);
		mState.reset();
		mState[static_cast<UINT>(eWaterBombState::Flow)] = true;

		mPos = mTransform->GetPosition();

		/*Vector2 LeftPos = mPos;
		LeftPos.x = LeftPos.x - TILE_WIDTH;
		WaterBomb* WFL = Object::Instantiate<WaterBomb>(eLayerType::WaterBomb, LeftPos);
		WFL->SetDirection(eDirection::Left);

		Vector2 RightPos = mPos;
		RightPos.x = RightPos.x + TILE_WIDTH;
		WaterBomb* WFR = Object::Instantiate<WaterBomb>(eLayerType::WaterBomb, RightPos);
		WFR->SetDirection(eDirection::Right);

		Vector2 UpPos = mPos;
		UpPos.y = UpPos.y - TILE_HEIGHT;
		WaterBomb* WFU = Object::Instantiate<WaterBomb>(eLayerType::WaterBomb, UpPos);
		WFU->SetDirection(eDirection::Up);

		Vector2 DownPos = mPos;
		DownPos.y = DownPos.y + TILE_HEIGHT;
		WaterBomb* WFD = Object::Instantiate<WaterBomb>(eLayerType::WaterBomb, DownPos);
		WFD->SetDirection(eDirection::Down);*/
	}
	void WaterBomb::SetDirection(eDirection dir)
	{
		mState.reset();
		mState[static_cast<UINT>(dir)] = true;
	}
	bool WaterBomb::GetWaterBombState(eWaterBombState state)
	{
		return mState[static_cast<UINT>(state)];
	}
}