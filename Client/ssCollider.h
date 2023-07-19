#pragma once
#include "ssComponent.h"

namespace ss
{
	using namespace math;
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		Vector2 GetSize() { return mSize; }
		void SetSize(Vector2 _size) { mSize = _size; }
		Vector2 GetOffset() { return mOffset; }
		void SetOffset(Vector2 _offset) { mOffset = _offset; }

	private:
		Vector2 mSize;
		Vector2 mOffset;
	};
}