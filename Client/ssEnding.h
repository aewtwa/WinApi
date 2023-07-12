#pragma once
#include "ssGameObject.h"

namespace ss
{
	class Ending : public GameObject
	{
	public:
		Ending();
		virtual ~Ending();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

	private:

	};
}