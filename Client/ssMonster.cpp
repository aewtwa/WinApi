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
		, mPos()
		, mAnimator{}
		, mCollider{}
	{
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
		mPos = mTransform->GetPosition();
		mPos = Vector2(250.0f, 250.0f);
		mTransform->SetPosition(mPos);

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"ForestMobDown", Resources::Find<Texture>(L"Monster"), Vector2(0.0f, 0.0f), Vector2(35.0f, 41.0f), 2, Vector2(0.0f, 0.0f), 0.3f);
		mAnimator->PlayAnimation(L"ForestMobDown", true);
		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(35.0f, 41.0f));

		GameObject::Initialize();
	}
	void Monster::Update()
	{
		GameObject::Update();
	}
	void Monster::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
	void Monster::OnCollisionEnter(Collider* _other)
	{
	}
	void Monster::OnCollisionStay(Collider* other)
	{
	}
	void Monster::OnCollisionExit(Collider* other)
	{
	}
}