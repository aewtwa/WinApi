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
#include "ssStatObject.h"
#include "ssGameObject.h"

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
		, mOwner{nullptr}
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
		mAnimator->SetScale(Vector2(1.2f, 1.2f));

		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(45.0f, 45.0f));

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
			mPos = mTransform->GetPosition();

			WaterFlow* WF = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, mPos);
			WF->GetComponent<Animator>()->PlayAnimation(L"BombCenterflow");
			for (size_t i = 1; i <= this->mOwner->GetStat().BombPower; i++)
			{
				Vector2 UpPos = mPos;
				UpPos.y -= TILE_HEIGHT * i;
				WaterFlow* WFU = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, UpPos);
				WFU->GetComponent<Animator>()->PlayAnimation(L"BombUpflow");

				Vector2 DownPos = mPos;
				DownPos.y += TILE_HEIGHT * i;
				WaterFlow* WFD = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, DownPos);
				WFD->GetComponent<Animator>()->PlayAnimation(L"BombDownflow");
				Vector2 LeftPos = mPos;
				LeftPos.x -= TILE_WIDTH * i;
				WaterFlow* WFL = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, LeftPos);
				WFL->GetComponent<Animator>()->PlayAnimation(L"BombLeftflow");
				Vector2 RightPos = mPos;
				RightPos.x += TILE_WIDTH * i;
				WaterFlow* WFR = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, RightPos);
				WFR->GetComponent<Animator>()->PlayAnimation(L"BombRightflow");
			}

			Stat stat = this->mOwner->GetStat();
			stat.Bombs++;
			this->mOwner->SetStat(stat);

			Destroy(this);
		}
		else
		{
			mBombtime += Time::DeltaTime();
		}

	}
}