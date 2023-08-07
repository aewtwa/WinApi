#pragma once
#include "ssGameObject.h"

namespace ss
{
	class IceFloor : public GameObject
	{
	public:
		IceFloor();
		virtual ~IceFloor();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

	private:
		class Transform* mTransform;
		class Texture* mTexture;
		class SpriteRenderer* mSpriteRenderer;
	};
}