#pragma once
#include "ssScene.h"
#include "ssTile.h"

namespace ss
{
	class ToolScene : public Scene
	{
	public:
		ToolScene();
		virtual ~ToolScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void Save();
		void Load();

	private:
		std::vector<Tile*> mTiles;
	};
}