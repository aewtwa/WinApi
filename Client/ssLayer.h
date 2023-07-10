#pragma once
#include "ssEntity.h"
#include "ssGameObject.h"

namespace ss
{
	class Layer : public Entity
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* _gameObj)
		{
			mGameObjects.push_back(_gameObj);
		}

	private:
		std::vector<GameObject*> mGameObjects;
	};
}

