#pragma once
#include "ssScene.h"
#include "ssGameObject.h"
#include "ssSceneManager.h"
#include "ssTransform.h"

namespace ss::Object
{
	template<typename T>
	static __forceinline T* Instantiate(eLayerType _type)
	{
		T* gameObject = new T;
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(_type, gameObject);
		gameObject->Initialize();

		return gameObject;
	}

	template <typename T>
	static __forceinline T* Instantiate(eLayerType type, Vector2 position)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameObject);
		gameObject->Initialize();
		gameObject->GetComponent<Transform>()->SetPosition(position);

		return gameObject;
	}
}