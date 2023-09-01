#include "ssTileObjectBack.h"
#include "ssAnimator.h"
#include "ssResources.h"
#include "ssCollider.h"

namespace ss
{
	TileObjectBack::TileObjectBack()
		: mTransform{}
		, mSpriteRenderer{}
	{
		SetName(L"TileObjectBack");
	}
	TileObjectBack::~TileObjectBack()
	{
	}
	void TileObjectBack::Initialize()
	{
		GameObject::Initialize();
	}
	void TileObjectBack::Update()
	{
		GameObject::Update();
	}
	void TileObjectBack::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
	void TileObjectBack::OnCollisionEnter(Collider* _other)
	{
	}
	void TileObjectBack::OnCollisionStay(Collider* _other)
	{
	}
	void TileObjectBack::OnCollisionExit(Collider* _other)
	{
	}
}