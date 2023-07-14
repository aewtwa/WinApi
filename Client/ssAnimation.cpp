#include "ssAnimation.h"
#include "ssTexture.h"
#include "ssAnimator.h"
#include "ssTime.h"
#include "ssTransform.h"
#include "ssGameObject.h"
#include "ssCamera.h"

namespace ss
{
	Animation::Animation()
		: mAnimator(nullptr)
		, mTexture(nullptr)
		, mSpriteSheet{}
		, mIndex(-1)
		, mElapsedTime(0.0f)
		, mbComplete(false)
	{
	}

	Animation::~Animation()
	{
	}

	void Animation::Update()
	{
		if (mbComplete)
			return;

		mElapsedTime += Time::DeltaTime();
		if (mSpriteSheet[mIndex].duration < mElapsedTime)
		{
			mElapsedTime = 0.0f;

			if (mIndex < mSpriteSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}

	void Animation::Render(HDC _hdc)
	{
		if (mTexture == nullptr)
			return;

		Transform* tr = mAnimator->GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mAnimator->GetAffectedCamera())
			pos = Camera::CalculatePosition(pos);

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		// 0.0f ~ 1.0f -> 0 ~ 255
		int alpha = (int)(mAnimator->GetAlpha() * 255.0f);
		if (alpha <= 0)
			alpha = 0;
		func.SourceConstantAlpha = alpha; // 0 ~ 255


		TransparentBlt(_hdc, (int)pos.x - (mSpriteSheet[mIndex].size.x / 2.0f)
			, (int)pos.y - (mSpriteSheet[mIndex].size.y / 2.0f)
			, mSpriteSheet[mIndex].size.x
			, mSpriteSheet[mIndex].size.y
			, mTexture->GetHdc()
			, mSpriteSheet[mIndex].leftTop.x
			, mSpriteSheet[mIndex].leftTop.y
			, mSpriteSheet[mIndex].size.x
			, mSpriteSheet[mIndex].size.y
			, RGB(255, 0, 255));

		//AlphaBlend(_hdc, (int)pos.x - (mSpriteSheet[mIndex].size.x / 2.0f)
		//	, (int)pos.y - (mSpriteSheet[mIndex].size.y / 2.0f)
		//	, mSpriteSheet[mIndex].size.x
		//	, mSpriteSheet[mIndex].size.y
		//	, mTexture->GetHdc()
		//	, mSpriteSheet[mIndex].leftTop.x
		//	, mSpriteSheet[mIndex].leftTop.y
		//	, mSpriteSheet[mIndex].size.x
		//	, mSpriteSheet[mIndex].size.y
		//	, func);

	}

	void Animation::Create(const std::wstring& _name, Texture* _texture
		, Vector2 _leftTop, Vector2 _size, Vector2 _offset
		, UINT _spriteLength, float _duration)
	{
		mTexture = _texture;

		for (size_t i = 0; i < _spriteLength; i++)
		{
			Sprite sprite = {};

			sprite.leftTop.x = _leftTop.x + (_size.x * i);
			sprite.leftTop.y = _leftTop.y;
			sprite.size = _size;
			sprite.offset = _offset;
			sprite.duration = _duration;

			mSpriteSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		mElapsedTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}

}