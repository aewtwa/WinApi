#pragma once
#include "ssScene.h"

namespace ss
{
	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		template<typename T>
		static T* CreateScene(const std::wstring& _name)
		{
			T* scene = new T();
			scene->SetName(_name);
			mScenes.insert(std::make_pair(_name, scene));
			mActiveScene = scene;
			scene->Initialize();

			return scene;
		}

		static Scene* LoadScene(const std::wstring& _name);
		static Scene* GetActiveScene() { return mActiveScene; }
	private:
		// 트리 자료구조
		static std::map<std::wstring, Scene*> mScenes;
		static Scene* mActiveScene;
		// key value 구조로 이루어져 있다.
		// key는 데이터를 검색하는 용도
		// value는 실제 우리가 사용할 데이터
	};
}
