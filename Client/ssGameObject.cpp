#include "ssGameObject.h"
#include "ssTransform.h"
#include "ssSpriteRenderer.h"
#include "ssCollider.h"

namespace ss
{
	GameObject::GameObject()
		: mState(eState::Active)
	{
		AddComponent<Transform>();
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}
	}

	void GameObject::Render(HDC _hdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(_hdc);
		}
	}

	void GameObject::OnCollisionEnter(Collider* other)
	{
	}
	void GameObject::OnCollisionStay(Collider* other)
	{
	}
	void GameObject::OnCollisionExit(Collider* other)
	{
	}
	RECT GameObject::GetInterSectColliderRect(Collider* other)
	{
		Collider* col = nullptr;
		col = GetComponent<Collider>();
		RECT resultRect = {};
		if (col)
		{
			const Vector2 thisCollPos = col->GetPosition();
			const Vector2 thisCollSize = col->GetSize() / 2.f;
			const Vector2 otherCollPos = other->GetPosition();
			const Vector2 otherCollSize = other->GetSize() / 2.f;

			const RECT thisRect =
			{
				thisCollPos.x - thisCollSize.x,
				thisCollPos.y - thisCollSize.y,
				thisCollPos.x + thisCollSize.x,
				thisCollPos.y + thisCollSize.y,
			};
			const RECT otherRect =
			{
				otherCollPos.x - otherCollSize.x,
				otherCollPos.y - otherCollSize.y,
				otherCollPos.x + otherCollSize.x,
				otherCollPos.y + otherCollSize.y,
			};
			IntersectRect(&resultRect, &thisRect, &otherRect);
		}
		return resultRect;
	}
}