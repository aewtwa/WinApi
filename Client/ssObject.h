#pragma once
#include "ssScene.h"
#include "ssGameObject.h"
#include "ssSceneManager.h"

namespace ss::Object
{
	template<typename T>
	static __forceinline T* Instantiate(eLayerType _type)
	{
		T* gameObject = new T;
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(_type, gameObject);

		return gameObject;
	}
}