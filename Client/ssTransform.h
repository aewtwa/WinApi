#pragma once
#include "ssComponent.h"


namespace ss
{
	using namespace math;
	class Transform : public Component
	{
	public:
		Transform();
		virtual ~Transform();

		virtual void Initialize()  override;
		virtual void Update()  override;
		virtual void Render(HDC _hdc)  override;

		void SetPosition(Vector2 _position) { mPosition = _position; }
		Vector2 GetPosition() { return mPosition; }

	private:
		Vector2 mPosition;
	};
}