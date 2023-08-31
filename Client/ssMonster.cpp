#include "ssMonster.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssPlayer.h"
#include "ssCollider.h"
#include "ssResources.h"
#include "ssTexture.h"

namespace ss
{
	Monster::Monster()
		: mTransform{ GetComponent<Transform>() }
		, mAnimator{}
		, mCollider{}
		, mbDeath(false)
	{
		SetName(L"Monster");
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
		/*mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimationFolder(L"ForestMobUp", L"..\\Resources\\Image\\Monster\\Forest\\Up", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"ForestMobDown", L"..\\Resources\\Image\\Monster\\Forest\\Down", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"ForestMobLeft", L"..\\Resources\\Image\\Monster\\Forest\\Left", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"ForestMobRight", L"..\\Resources\\Image\\Monster\\Forest\\Right", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"ForestMobDie", L"..\\Resources\\Image\\Monster\\Forest\\Die", Vector2(0.0f, 0.0f), 0.16f);

		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(35.0f, 41.0f));*/

		GameObject::Initialize();
	}
	void Monster::Update()
	{
		if (!mbDeath)
		{
			Move();
		}

		GameObject::Update();
	}
	void Monster::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
	void Monster::OnCollisionEnter(Collider* _other)
	{
		if (L"WaterFlow" == _other->GetOwner()->GetName())
		{
			Die();
		}
	}
	void Monster::OnCollisionStay(Collider* other)
	{
	}
	void Monster::OnCollisionExit(Collider* other)
	{
	}

	void Monster::Move()
	{

	}
	void Monster::Die()
	{
		Destroy(this);
	}
}