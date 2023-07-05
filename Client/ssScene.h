#pragma once
#include "ssEntity.h"
#include "ssLayer.h"

namespace ss
{
	using namespace ss::enums;

	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initailize();
		virtual void Update();
		virtual void Render(HDC hdc);

	private:
		std::vector<Layer> mLayers;
	};
}
