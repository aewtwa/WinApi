#include "ssScene.h"

namespace ss
{
	Scene::Scene()
	{
		mLayers.resize((int)eLayerType::End);
	}
	Scene::~Scene()
	{

	}
	void Scene::Initialize()
	{

	}
	void Scene::Update()
	{
		//for (size_t i = 0; i < mLayers.size(); i++)
		//{

		//}
		
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}
	void Scene::Render(HDC _hdc)
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(_hdc);
		}
	}
	void Scene::SceneEnter()
	{
	}
	void Scene::SceneExit()
	{
	}
}