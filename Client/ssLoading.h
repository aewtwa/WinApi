#pragma once
#include "ssGameObject.h"

namespace ss
{
	class Loading : public GameObject
	{
	public:
		Loading();
		virtual ~Loading();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

	private:

	};
}