#pragma once
#include "ssScene.h"

namespace ss
{
	class Sound;
	class LoadingScene : public Scene
	{
	public:
		LoadingScene();
		virtual ~LoadingScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;
		virtual void SceneEnter();
		virtual void SceneExit();

	private:
		Sound* mLoadingSound;
	};
}
