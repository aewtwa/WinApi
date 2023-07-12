#include "ssSpriteRenderer.h"
#include "ssTransform.h"
#include "ssGameObject.h"

namespace ss
{
	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::SpriteRenderer)
		, mScale(Vector2::One)
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
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mTexture->GetType() == eTextureType::Bmp)
		{
			TransparentBlt(_hdc, (int)pos.x, (int)pos.y
				, mTexture->GetWidth() * mScale.x, mTexture->GetHeight() * mScale.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), RGB(255, 0, 255));
		}
		else if (mTexture->GetType() == eTextureType::Png)
		{
			Gdiplus::Graphics graphics(_hdc);
			graphics.DrawImage(mTexture->GetImage(), (int)pos.x, (int)pos.y
				, (int)(mTexture->GetWidth() * mScale.x)
				, (int)(mTexture->GetHeight() * mScale.y));
		}
	}
}