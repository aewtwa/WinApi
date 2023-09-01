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
		: mbDeath(false)
	{
		SetName(L"Monster");
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
		StatObject::Initialize();
	}
	void Monster::Update()
	{
		if (!mbDeath)
		{
			Move();
		}

		StatObject::Update();
	}
	void Monster::Render(HDC _hdc)
	{
		StatObject::Render(_hdc);
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