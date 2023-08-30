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
		, mCreated(true)
		, mBombtime(0.0f)
		, mbBomb(false)
		, mPos(Vector2::Zero)
	{
		SetName(L"WaterBomb");
	}
	WaterBomb::~WaterBomb()
	{
	}
	void WaterBomb::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"WaterBombIdle", Resources::Find<Texture>(L"WaterBomb"), Vector2(0.0f, 0.0f), Vector2(44.0f, 41.0f), 3, Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"BombCenterflow", L"C:\\Project\\WinApi\\Resources\\Image\\Bomb\\Centerflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombLeftflow", L"C:\\Project\\WinApi\\Resources\\Image\\Bomb\\Leftflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombRightflow", L"..\\Resources\\Image\\Bomb\\Rightflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombUpflow", L"..\\Resources\\Image\\Bomb\\Upflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombDownflow", L"..\\Resources\\Image\\Bomb\\Downflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->SetScale(Vector2(1.2f, 1.2f));

		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(50.0f, 50.0f));

		GameObject::Initialize();
	}
	void WaterBomb::Update()
	{
		if (mCreated)
		{
			Idle();
		}

		mBombtime += Time::DeltaTime();
		if (2.0f < mBombtime)
		{
			Bomb();
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

	void WaterBomb::Idle()
	{
		mAnimator->PlayAnimation(L"WaterBombIdle", true);
		mCreated = false;
	}

	void WaterBomb::Bomb()
	{
		mAnimator->PlayAnimation(L"BombCenterflow", false);
		mPos = mTransform->GetPosition();
		WaterFlow* WF = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, mPos);
		mBombtime = 0.0f;
	}
}