#include "ssLayer.h"

namespace ss
{
	Layer::Layer()
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::Initialize()
	{
	}

	void Layer::Update()
	{
		for (GameObject* obj : mGameObjects)
		{
			obj->Update();
		}
	}

	void Layer::Render(HDC _hdc)
	{
		for (GameObject* obj : mGameObjects)
		{
			obj->Render(_hdc);
		}
	}
}