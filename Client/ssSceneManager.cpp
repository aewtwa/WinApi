#include "ssSceneManager.h"
#include "ssTitleScene.h"
#include "ssHomeScene.h"
#include "ssEndingScene.h"
#include "ssLoadingScene.h"
#include "ssPlayScene.h"
#include "ssToolScene.h"
#include "ssIceMap1.h"

namespace ss
{
	std::map<std::wstring, Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		CreateScene<LoadingScene>(L"LoadingScene");
		CreateScene<TitleScene>(L"TitleScene");
		CreateScene<HomeScene>(L"HomeScene");
		CreateScene<EndingScene>(L"EndingScene");
		CreateScene<PlayScene>(L"PlayScene");
		CreateScene<ToolScene>(L"ToolScene");
		CreateScene<IceMap1>(L"IceMap1");


		mActiveScene = nullptr;

		LoadScene(L"LoadingScene");


	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::Render(HDC _hdc)
	{
		mActiveScene->Render(_hdc);
	}

	Scene* SceneManager::LoadScene(const std::wstring& _name)
	{
		if (mActiveScene != nullptr)
		{
			mActiveScene->SceneExit();
		}
		std::map<std::wstring, Scene*>::iterator iter = mScenes.find(_name);

		if (iter == mScenes.end())
			return nullptr;

		mActiveScene = iter->second;

		mActiveScene->SceneEnter();
		return iter->second;
	}
}