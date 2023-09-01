#include "ssTileBox.h"
#include "ssAnimator.h"
#include "ssResources.h"
#include "ssCollider.h"

namespace ss
{
	TileBox::TileBox()
		: mTransform{}
		, mSpriteRenderer{}
		, mCollider{}
	{
		SetName(L"TileBox");
	}
	TileBox::~TileBox()
	{
	}
	void TileBox::Initialize()
	{
		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(50.f, 50.f));

		GameObject::Initialize();
	}
	void TileBox::Update()
	{
		GameObject::Update();
	}
	void TileBox::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
	void TileBox::OnCollisionEnter(Collider* _other)
	{
		if (L"WaterFlow" == _other->GetOwner()->GetName())
		{
			Destroy(this);
		}
	}
	void TileBox::OnCollisionStay(Collider* _other)
	{
	}
	void TileBox::OnCollisionExit(Collider* _other)
	{
	}
}