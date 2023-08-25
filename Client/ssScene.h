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

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void SceneEnter();
		virtual void SceneExit();

		void AddGameObject(eLayerType _type, GameObject* _gameObj)
		{
			mLayers[(int)_type].AddGameObject(_gameObj);
		}

		Layer& GetLayer(eLayerType _type) { return mLayers[(UINT)_type]; }

	private:
		std::vector<Layer> mLayers;
	};
}
