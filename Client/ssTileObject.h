#pragma once
#include "ssGameObject.h"

namespace ss
{
	using namespace math;
	class TileObject : public GameObject
	{
	public:
		TileObject();
		virtual ~TileObject();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* _other) override;
		virtual void OnCollisionStay(class Collider* _other) override;
		virtual void OnCollisionExit(class Collider* _other) override;

	private:
		class Transform* mTransform;
		class SpriteRenderer* mSpriteRenderer;
		class Collider* mCollider;
	};
}