#include "ssPirate1.h"
#include "ssTransform.h"
#include "ssAnimator.h"
#include "ssCollider.h"
#include "ssMonster.h"
#include "ssTime.h"
#include "ssInput.h"

namespace ss
{
	Pirate1::Pirate1()
		: mDirection{}
		, mAnimator{}
		, mCollider{}
	{
	}
	Pirate1::~Pirate1()
	{
	}
	void Pirate1::Initialize()
	{
		Stat stat = {};
		stat.Speed = 200.0f;
		stat.BombPower = 0;
		stat.Bombs = 0;
		SetStat(stat);

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimationFolder(L"ForestMobUp", L"..\\Resources\\Image\\Monster\\Forest\\Up", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"ForestMobDown", L"..\\Resources\\Image\\Monster\\Forest\\Down", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"ForestMobLeft", L"..\\Resources\\Image\\Monster\\Forest\\Left", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"ForestMobRight", L"..\\Resources\\Image\\Monster\\Forest\\Right", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"ForestMobDie", L"..\\Resources\\Image\\Monster\\Forest\\Die", Vector2(0.0f, 0.0f), 0.16f);

		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(35.0f, 41.0f));

		Monster::Initialize();
	}
	void Pirate1::Update()
	{
		std::bitset<static_cast<UINT>(eDirection::End)> direction = GetDirect();
		if (Input::GetKey(eKeyCode::W))
		{
			mAnimator->PlayAnimation(L"ForestMobUp");
			direction.reset();
			direction[static_cast<UINT>(eDirection::Up)] = true;
			SetDirect(direction);
			Move();
		}
		if (Input::GetKeyUp(eKeyCode::W))
		{
			direction[static_cast<UINT>(eDirection::Up)] = false;
			SetDirect(direction);
		}

		Monster::Update();
	}
	void Pirate1::Render(HDC _hdc)
	{
		Monster::Render(_hdc);
	}
	void Pirate1::OnCollisionEnter(Collider* _other)
	{
		Monster::OnCollisionEnter(_other);
	}
	void Pirate1::OnCollisionStay(Collider* _other)
	{
		Monster::OnCollisionStay(_other);
	}
	void Pirate1::OnCollisionExit(Collider* _other)
	{
	}
	void Pirate1::Move()
	{
		Vector2 pos = GetPos();
		Transform* transform = GetTransform();
		std::bitset<static_cast<UINT>(eDirection::End)> direction = GetDirect();
		if (direction[static_cast<UINT>(eDirection::Up)])
		{
			pos.y -= this->GetStat().Speed * Time::DeltaTime();
			SetPos(pos);
		}
		transform->SetPosition(pos);

		Monster::Move();
	}
	void Pirate1::Die()
	{
		Monster::Die();
	}
}