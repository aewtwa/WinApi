#include "ssWaterBomb.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssCollider.h"
#include "ssResources.h"
#include "ssTexture.h"

namespace ss
{
	WaterBomb::WaterBomb()
		: mAnimator{}
		, mCollider{}
		, mTransform{}
		, mBombtime(0.0f)
		, mbBomb(false)
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
		mAnimator->CreateAnimationFolder(L"BombCenterflow", L"..\\Resources\\Image\\Bomb\\Centerflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombLeftflow", L"..\\Resources\\Image\\Bomb\\Leftflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombRightflow", L"..\\Resources\\Image\\Bomb\\Rightflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombUpflow", L"..\\Resources\\Image\\Bomb\\Upflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombDownflow", L"..\\Resources\\Image\\Bomb\\Downflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->SetScale(Vector2(1.3f, 1.3f));
		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(50.0f, 50.0f));

		mAnimator->PlayAnimation(L"WaterBombIdle", true);
		GameObject::Initialize();
	}
	void WaterBomb::Update()
	{
		mBombtime += Time::DeltaTime();
		if (2.0f < mBombtime)
		{
			mbBomb = true;
		}

		if (mbBomb)
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

	void WaterBomb::Bomb()
	{
		mbBomb = false;
		mBombtime = 0.0f;
		mAnimator->PlayAnimation(L"BombCenterflow");
	}
}