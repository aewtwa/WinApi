#include "ssBoss.h"
#include "ssTransform.h"
#include "ssAnimator.h"
#include "ssCollider.h"
#include "ssMonster.h"
#include "ssTime.h"
#include "ssInput.h"

namespace ss
{
	Boss::Boss()
		:mHp(5)
		, mDirection{}
		, mAnimator{}
		, mCollider{}
	{
	}
	Boss::~Boss()
	{
	}
	void Boss::Initialize()
	{
		Stat stat = {};
		stat.Speed = 200.0f;
		stat.BombPower = 0;
		stat.Bombs = 0;
		SetStat(stat);

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimationFolder(L"BossUp", L"..\\Resources\\Image\\Monster\\ForestBoss\\Up", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"BossDown", L"..\\Resources\\Image\\Monster\\ForestBoss\\Down", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"BossLeft", L"..\\Resources\\Image\\Monster\\ForestBoss\\Left", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"BossRight", L"..\\Resources\\Image\\Monster\\ForestBoss\\Right", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"BossHit", L"..\\Resources\\Image\\Monster\\ForestBoss\\Hit", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"BossDie", L"..\\Resources\\Image\\Monster\\ForestBoss\\Die", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"BossAttack", L"..\\Resources\\Image\\Monster\\ForestBoss\\Attack", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"BossBubble", L"..\\Resources\\Image\\Monster\\ForestBoss\\Bubble", Vector2(0.0f, 0.0f), 0.16f);

		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(110.0f, 110.0f));

		mAnimator->PlayAnimation(L"BossBubble", true);
		Monster::Initialize();
	}
	void Boss::Update()
	{
		Monster::Update();
	}
	void Boss::Render(HDC _hdc)
	{
		Monster::Render(_hdc);
	}
	void Boss::OnCollisionEnter(Collider* _other)
	{
	}
	void Boss::OnCollisionStay(Collider* _other)
	{
	}
	void Boss::OnCollisionExit(Collider* _other)
	{
	}
	void Boss::Move()
	{
		Monster::Move();
	}
	void Boss::Die()
	{
		Monster::Die();
	}
}