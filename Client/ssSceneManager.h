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
		// Ʈ�� �ڷᱸ��
		static std::map<std::wstring, Scene*> mScenes;
		static Scene* mActiveScene;
		// key value ������ �̷���� �ִ�.
		// key�� �����͸� �˻��ϴ� �뵵
		// value�� ���� �츮�� ����� ������
	};
}
