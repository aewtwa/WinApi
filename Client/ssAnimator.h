#pragma once
#include "ssComponent.h"
#include "ssAnimation.h"

namespace ss
{
	using namespace math;
	class Animator : public Component
	{
	public:
		Animator();
		~Animator();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		void CreateAnimation(const std::wstring& _name
			, class Texture* _texture
			, Vector2 _leftTop, Vector2 _size, Vector2 _offset
			, UINT _spriteLength, float _duration);

		Animation* FindAnimation(const std::wstring& _name);
		void PlayAnimation(const std::wstring& _name, bool _loop = false);

		bool GetAffectedCamera() { return mbAffectedCamera; }
		void SetAffectedCamera(bool _enable) { mbAffectedCamera = _enable; }
		float GetAlpha() { return mAlpha; }
		void SetAlpha(float _alpha) { mAlpha = _alpha; }

	private:
		std::map<std::wstring, Animation*> mAnimations;

		Animation* mActiveAnimation;
		bool mbLoop;
		bool mbAffectedCamera;
		float mAlpha;
	};
}