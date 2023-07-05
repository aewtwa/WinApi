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

		void AddGameObject()
		{
			GameObject* obj = new GameObject;
			mGameObjects.push_back(obj);
		}

	private:
		std::vector<GameObject*> mGameObjects;
	};
}

