#pragma once
#include "ssScene.h"
#include "ssTile.h"

namespace ss
{
	class IceMap1 : public Scene
	{
	public:
		IceMap1();
		virtual ~IceMap1();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		void Load();

	private:
		std::vector<Tile*> mTiles;
	};
}