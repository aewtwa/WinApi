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

		Sprite sprite = mSpriteSheet[mIndex];
		Transform* tr = mAnimator->GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Animator* animator = mAnimator;

		mTexture->Render(_hdc
			, pos
			, sprite.size
			, sprite.leftTop
			, sprite.size
			, sprite.offset
			, animator->GetScale()
			, animator->GetAlpha()
			, tr->GetRotation());
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
			if (sprite.leftTop.x >= _texture->GetWidth())
			{
				sprite.leftTop.x = sprite.leftTop.x - _texture->GetWidth();
				sprite.leftTop.y = _leftTop.y + _size.y;
			}
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