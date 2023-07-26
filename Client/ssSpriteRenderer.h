#pragma once
#include "ssComponent.h"
#include "ssTexture.h"

namespace ss
{
	using namespace math;
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		void SetImage(Texture* _image) { mTexture = _image; }
		void SetScale(Vector2 _scale) { mScale = _scale; }
		void SetAffectCamera(bool _enable) { mbAffectCamera = _enable; }
		float GetAlpha() { return mAlpha; }
		void SetAlpha(float _alpha) { mAlpha = _alpha; }
		void SetTile(int _x, int _y) { mbTile = true; mTileIndexX = _x; mTileIndexY = _y; }

	private:
		bool mbAffectCamera;

		bool mbTile;
		int mTileIndexX;
		int mTileIndexY;

		Texture* mTexture;
		Vector2 mScale;
		float mAlpha;
	};
}