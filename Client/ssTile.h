#pragma once
#include "ssGameObject.h"

namespace ss
{
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

		void SetTile(int _x, int _y);

	private:
		class SpriteRenderer* mSpriteRenderer;
	};
}