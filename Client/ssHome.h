#pragma once
#include "ssGameObject.h"

namespace ss
{
	class Home : public GameObject
	{
	public:
		Home();
		virtual ~Home();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

	private:

	};
}