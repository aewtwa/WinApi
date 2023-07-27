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

		Tile();
		~Tile();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		Vector2 GetSourceTileIdx() { return Vector2(mSourceIndexX, mSourceIndexY); }
		void SetSourceTileIdx(int _x, int _y) { mSourceIndexX = _x;  mSourceIndexY = _y; }
		Vector2 GetTileIdx() { return Vector2(mIndexX, mIndexY); }
		void SetTileIdx(int _x, int _y) { mIndexX = _x;  mIndexY = _y; }

		void SetTile(int _x, int _y);

	private:
		class SpriteRenderer* mSpriteRenderer;

		UINT mSourceIndexX;
		UINT mSourceIndexY;

		UINT mIndexX;
		UINT mIndexY;
	};
}