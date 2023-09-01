#include "ssPirate1.h"
#include "ssTransform.h"
#include "ssAnimator.h"
#include "ssCollider.h"
#include "ssMonster.h"

namespace ss
{
	Pirate1::Pirate1()
		: mDirection{}
	{
	}
	Pirate1::~Pirate1()
	{
	}
	void Pirate1::Initialize()
	{
		Animator* animator = {};
		animator = AddComponent<Animator>();
		animator->CreateAnimationFolder(L"ForestMobUp", L"..\\Resources\\Image\\Monster\\Forest\\Up", Vector2(0.0f, 0.0f), 0.16f);
		animator->CreateAnimationFolder(L"ForestMobDown", L"..\\Resources\\Image\\Monster\\Forest\\Down", Vector2(0.0f, 0.0f), 0.16f);
		animator->CreateAnimationFolder(L"ForestMobLeft", L"..\\Resources\\Image\\Monster\\Forest\\Left", Vector2(0.0f, 0.0f), 0.16f);
		animator->CreateAnimationFolder(L"ForestMobRight", L"..\\Resources\\Image\\Monster\\Forest\\Right", Vector2(0.0f, 0.0f), 0.16f);
		animator->CreateAnimationFolder(L"ForestMobDie", L"..\\Resources\\Image\\Monster\\Forest\\Die", Vector2(0.0f, 0.0f), 0.16f);

		Collider* collider = {};
		collider = AddComponent<Collider>();
		collider->SetSize(Vector2(35.0f, 41.0f));

		Monster::Initialize();
	}
	void Pirate1::Update()
	{
		if (!this->GetisDeath())
		{
			Move();
		}



		Monster::Update();
	}
	void Pirate1::Render(HDC _hdc)
	{
		Monster::Render(_hdc);
	}
	void Pirate1::OnCollisionEnter(Collider* _other)
	{
		if (L"WaterFlow" == _other->GetOwner()->GetName())
		{
			Die();
		}
	}
	void Pirate1::OnCollisionStay(Collider* _other)
	{
	}
	void Pirate1::OnCollisionExit(Collider* _other)
	{
	}
	void Pirate1::Move()
	{
		int a = 0;
	}
	void Pirate1::Die()
	{
		this->SetisDeath(true);
		Destroy(this);
	}
}