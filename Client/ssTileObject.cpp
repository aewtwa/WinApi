#include "ssTileObject.h"
#include "ssAnimator.h"
#include "ssResources.h"
#include "ssCollider.h"

namespace ss
{
	TileObject::TileObject()
		: mTransform{}
		, mSpriteRenderer{}
		, mCollider{}
	{
		SetName(L"TileObject");
	}
	TileObject::~TileObject()
	{
	}
	void TileObject::Initialize()
	{
		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(50.f, 50.f));

		GameObject::Initialize();
	}
	void TileObject::Update()
	{
		GameObject::Update();
	}
	void TileObject::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
	void TileObject::OnCollisionEnter(Collider* _other)
	{
	}
	void TileObject::OnCollisionStay(Collider* _other)
	{
	}
	void TileObject::OnCollisionExit(Collider* _other)
	{
	}
}