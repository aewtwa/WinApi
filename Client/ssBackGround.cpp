#include "ssBackGround.h"
#include "ssAnimator.h"
#include "ssResources.h"
#include "ssTexture.h"
#include "ssSpriteRenderer.h"
#include "ssTransform.h"

namespace ss
{
	BackGround::BackGround()
		: mTransform{ GetComponent<Transform>() }
	{
	}

	BackGround::~BackGround()
	{
	}

	void BackGround::Initialize()
	{
		mTexture = Resources::Load<Texture>(L"PlayBackGround", L"..\\Resources\\Image\\Bg\\play.bmp");
		mSpriteRenderer = AddComponent<SpriteRenderer>();
		mSpriteRenderer->SetImage(mTexture);
		mSpriteRenderer->SetScale(Vector2(1.3f, 1.3f));
		GetComponent<Transform>()->SetPosition(Vector2(520.0f, 390.0f));
	}

	void BackGround::Update()
	{
		GameObject::Update();
	}

	void BackGround::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
}
