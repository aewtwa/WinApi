#pragma once
#include "ssGameObject.h"

namespace ss
{
	using namespace math;
	class Tile : public GameObject
	{
	public:
		static UINT mSelectedX;
		static UINT mSelectedY;
		static Vector2 ConvertNumberToTile(const UINT& _UINT1, const UINT& _UINT2);
		static Vector2 ConvertPosToTile(const Vector2& _pos);

		Tile();
		~Tile();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* _other) override;
		virtual void OnCollisionStay(class Collider* _other) override;
		virtual void OnCollisionExit(class Collider* _other) override;


		Vector2 GetSourceTileIdx() { return Vector2(mSourceIndexX, mSourceIndexY); }
		void SetSourceTileIdx(int _x, int _y) { mSourceIndexX = _x;  mSourceIndexY = _y; }
		Vector2 GetTileIdx() { return Vector2(mIndexX, mIndexY); }
		void SetTileIdx(int _x, int _y) { mIndexX = _x;  mIndexY = _y; }

		void SetTile(int _x, int _y);

	private:
		class SpriteRenderer* mSpriteRenderer;
		class Collider* mCollider;

		UINT mSourceIndexX;
		UINT mSourceIndexY;

		UINT mIndexX;
		UINT mIndexY;
	};
}