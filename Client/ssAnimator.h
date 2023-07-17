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
			, Vector2 _leftTop, Vector2 _size, UINT _spriteLength
			, Vector2 _offset = Vector2::Zero, float _duration = 0.1f);

		void CreateAnimationFolder(const std::wstring& name
			, const std::wstring& path
			, Vector2 offset = Vector2::Zero, float duration = 0.1f);

		Animation* FindAnimation(const std::wstring& _name);
		void PlayAnimation(const std::wstring& _name, bool _loop = false);

		bool GetAffectedCamera() { return mbAffectedCamera; }
		void SetAffectedCamera(bool _enable) { mbAffectedCamera = _enable; }
		float GetAlpha() { return mAlpha; }
		void SetAlpha(float _alpha) { mAlpha = _alpha; }
		Vector2 GetScale() { return mScale; }
		void SetScale(Vector2 _scale) { mScale = _scale; }

	private:
		std::map<std::wstring, Animation*> mAnimations;

		Animation* mActiveAnimation;
		bool mbLoop;
		bool mbAffectedCamera;
		float mAlpha;
		Vector2 mScale;
	};
}