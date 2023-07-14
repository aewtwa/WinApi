#pragma once
#include "ssResource.h"

namespace ss
{
	using namespace math;
	class Texture;
	class Animator;
	class Animation : public Resource 
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				: leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.0f)
			{

			}
		};

		Animation();
		~Animation();

		void Update();
		void Render(HDC _hdc);

		virtual HRESULT Load(const std::wstring& _path) { return S_FALSE; };

		void Create(const std::wstring& _name
			, class Texture* _texture
			, Vector2 _leftTop, Vector2 _size, Vector2 _offset
			, UINT _spriteLength, float _duration);

		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAnimator(Animator* _animator) { mAnimator = _animator; }


	private:
		Animator* mAnimator;
		Texture* mTexture;

		std::vector<Sprite> mSpriteSheet;
		int mIndex;
		float mElapsedTime;
		bool mbComplete;
	};
}