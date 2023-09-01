#pragma once
#include "ssGameObject.h"

namespace ss
{
	using namespace math;
	class TileObjectBack : public GameObject
	{
	public:
		TileObjectBack();
		virtual ~TileObjectBack();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* _other) override;
		virtual void OnCollisionStay(class Collider* _other) override;
		virtual void OnCollisionExit(class Collider* _other) override;

	private:
		class Transform* mTransform;
		class SpriteRenderer* mSpriteRenderer;
	};
}