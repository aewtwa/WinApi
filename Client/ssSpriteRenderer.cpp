#include "ssSpriteRenderer.h"
#include "ssTransform.h"
#include "ssGameObject.h"
#include "ssCamera.h"

namespace ss
{
	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::SpriteRenderer)
		, mbAffectCamera(true)
		, mTexture(nullptr)
		, mScale(Vector2::One)
		, mAlpha(1.0f)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::Render(HDC _hdc)
	{
		if (mTexture == nullptr)
			return;

		GameObject* gameObj = GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		mTexture->Render(_hdc
			, tr->GetPosition()
			, Vector2(mTexture->GetWidth(), mTexture->GetHeight())
			, Vector2(0.0f, 0.0f)
			, Vector2(mTexture->GetWidth(), mTexture->GetHeight())
			, Vector2::Zero
			, mScale
			, mAlpha);
	}
}