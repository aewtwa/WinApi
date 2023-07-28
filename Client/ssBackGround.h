#pragma once
#include "ssGameObject.h"

namespace ss
{
	using namespace math;
	class BackGround : public GameObject
	{
	public:
		BackGround();
		virtual ~BackGround();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

	private:
		class Transform* mTransform;
		Vector2 mPos;
		class Texture* mTexture;
		class SpriteRenderer* mSpriteRenderer;
	};
}