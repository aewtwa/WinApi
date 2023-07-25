#include "ssMonster.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssPlayer.h"
#include "ssCollider.h"

namespace ss
{
	Monster::Monster()
	{
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
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
		Player* player = dynamic_cast<Player*>(_other->GetOwner());
		Transform* tr = player->GetComponent<Transform>();

		Vector2 PlayerPos = tr->GetPosition();

	}
	void Monster::OnCollisionStay(Collider* other)
	{
	}
	void Monster::OnCollisionExit(Collider* other)
	{
	}
}