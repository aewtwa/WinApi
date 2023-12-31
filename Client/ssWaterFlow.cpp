#include "ssWaterFlow.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssCollider.h"
#include "ssResources.h"
#include "ssTexture.h"
#include "ssObject.h"

namespace ss
{
	WaterFlow::WaterFlow()
		: mAnimator{}
		, mCollider{}
		, mTransform{ GetComponent<Transform>() }
		, mDirection{}
		, mPos(Vector2::Zero)
		, mbBomb(true)
	{
		SetName(L"WaterFlow");
	}

	WaterFlow::~WaterFlow()
	{
	}

	void WaterFlow::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimationFolder(L"BombCenterflow", L"..\\Resources\\Image\\Bomb\\Centerflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombLeftflow", L"..\\Resources\\Image\\Bomb\\Leftflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombRightflow", L"..\\Resources\\Image\\Bomb\\Rightflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombUpflow", L"..\\Resources\\Image\\Bomb\\Upflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimationFolder(L"BombDownflow", L"..\\Resources\\Image\\Bomb\\Downflow", Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->SetScale(Vector2(1.2f, 1.2f));

		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(45.0f, 45.0f));

		GameObject::Initialize();
	}

	void WaterFlow::Update()
	{
		if (mbBomb)
		{
			Bomb();
		}

		if (mAnimator->IsActiveAnimationComplete())
		{
			Destroy(this);
		}

		if (mDirection[static_cast<UINT>(eDirection::Up)])
		{
			mAnimator->PlayAnimation(L"BombUpflow", false);
			mDirection.reset();
		}
		if (mDirection[static_cast<UINT>(eDirection::Down)])
		{
			mAnimator->PlayAnimation(L"BombDownflow", false);
			mDirection.reset();
		}
		if (mDirection[static_cast<UINT>(eDirection::Left)])
		{
			mAnimator->PlayAnimation(L"BombLeftflow", false);
			mDirection.reset();
		}
		if (mDirection[static_cast<UINT>(eDirection::Right)])
		{
			mAnimator->PlayAnimation(L"BombRightflow", false);
			mDirection.reset();
		}
		GameObject::Update();
	}

	void WaterFlow::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}

	void WaterFlow::OnCollisionEnter(Collider* _other)
	{
		if (L"TileBox" == _other->GetOwner()->GetName())
		{
			Destroy(this);
		}
		if (L"TileObject" == _other->GetOwner()->GetName())
		{
			Destroy(this);
		}
	}

	void WaterFlow::OnCollisionStay(Collider* _other)
	{
	}

	void WaterFlow::OnCollisionExit(Collider* _other)
	{
	}

	void WaterFlow::Bomb()
	{
		mbBomb = false;
	}
}