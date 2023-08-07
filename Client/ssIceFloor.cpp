#include "ssIceFloor.h"
#include "ssAnimator.h"
#include "ssResources.h"
#include "ssTexture.h"
#include "ssSpriteRenderer.h"
#include "ssTransform.h"

namespace ss
{
	IceFloor::IceFloor()
		: mTransform{ GetComponent<Transform>() }
		, mTexture(nullptr)
		, mSpriteRenderer(nullptr)
	{
	}
	IceFloor::~IceFloor()
	{
	}
	void IceFloor::Initialize()
	{
		mTexture = Resources::Load<Texture>(L"ICETILE", L"..\\Resources\\Image\\Bg\\ICETILE.bmp");
		mSpriteRenderer = AddComponent<SpriteRenderer>();
		mSpriteRenderer->SetImage(mTexture);
		mSpriteRenderer->SetScale(Vector2(0.87f, 0.87f));
		GetComponent<Transform>()->SetPosition(Vector2(417.0f, 391.0f));
	}
	void IceFloor::Update()
	{
		GameObject::Update();
	}
	void IceFloor::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}