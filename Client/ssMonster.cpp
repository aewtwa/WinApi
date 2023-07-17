#include "ssMonster.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"

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

		Transform* tr = GetComponent<Transform>();
		Animator* at = GetComponent<Animator>();
		Vector2 Pos = tr->GetPosition();


		tr->SetPosition(Pos);
	}
	void Monster::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}