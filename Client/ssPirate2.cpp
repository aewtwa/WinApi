#include "ssPirate2.h"
#include "ssTransform.h"
#include "ssAnimator.h"
#include "ssCollider.h"
#include "ssMonster.h"
#include "ssTime.h"

namespace ss
{
	Pirate2::Pirate2()
		: mDirection{}
		, mAnimator{}
		, mCollider{}
		, mMovetime(0.0f)
	{
	}
	Pirate2::~Pirate2()
	{
	}
	void Pirate2::Initialize()
	{
		Stat stat = {};
		stat.Speed = 100.0f;
		stat.BombPower = 0;
		stat.Bombs = 0;
		SetStat(stat);

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimationFolder(L"Pirate2MobUp", L"..\\Resources\\Image\\Monster\\Pirate2\\Up", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"Pirate2MobDown", L"..\\Resources\\Image\\Monster\\Pirate2\\Down", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"Pirate2MobLeft", L"..\\Resources\\Image\\Monster\\Pirate2\\Left", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"Pirate2MobRight", L"..\\Resources\\Image\\Monster\\Pirate2\\Right", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->CreateAnimationFolder(L"Pirate2MobDie", L"..\\Resources\\Image\\Monster\\Pirate2\\Die", Vector2(0.0f, 0.0f), 0.16f);
		mDirection[static_cast<UINT>(eDirection::Up)] = true;
		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(35.0f, 41.0f));

		Monster::Initialize();
	}
	void Pirate2::Update()
	{
		mMovetime += Time::DeltaTime();

		if (mMovetime > 2.0f)
		{
			if (mDirection[static_cast<UINT>(eDirection::Up)])
			{
				mDirection.reset();
				mDirection[static_cast<UINT>(eDirection::Down)] = true;
			}
			else if(mDirection[static_cast<UINT>(eDirection::Down)])
			{
				mDirection.reset();
				mDirection[static_cast<UINT>(eDirection::Up)] = true;
			}

			mMovetime = 0;
		}

		Move();

		Monster::Update();
	}
	void Pirate2::Render(HDC _hdc)
	{
		Monster::Render(_hdc);
	}
	void Pirate2::OnCollisionEnter(Collider* _other)
	{
	}
	void Pirate2::OnCollisionStay(Collider* _other)
	{
	}
	void Pirate2::OnCollisionExit(Collider* _other)
	{
	}
	void Pirate2::Move()
	{
		Vector2 pos = GetPos();
		Transform* transform = GetTransform();
		if (mDirection[static_cast<UINT>(eDirection::Up)])
		{
			pos.y -= this->GetStat().Speed * Time::DeltaTime();
			SetPos(pos);
		}
		if (mDirection[static_cast<UINT>(eDirection::Down)])
		{
			pos.y += this->GetStat().Speed * Time::DeltaTime();
			SetPos(pos);
		}
		transform->SetPosition(pos);
		Monster::Move();
	}
	void Pirate2::Die()
	{
		Monster::Die();
	}
}