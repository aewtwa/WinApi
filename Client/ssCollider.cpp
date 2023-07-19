#include "ssCollider.h"
#include "ssTransform.h"
#include "ssGameObject.h"


namespace ss
{
	Collider::Collider()
		:Component(eComponentType::Collider)
		, mSize(Vector2::Zero)
		, mOffset(Vector2::Zero)
	{
	}

	Collider::~Collider()
	{
	}

	void Collider::Initialize()
	{
	}

	void Collider::Update()
	{
	}

	void Collider::Render(HDC _hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.x -= mSize.x / 2.0f;
		pos.y -= mSize.y / 2.0f;
		pos.x += mOffset.x;
		pos.y += mOffset.y;

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(50, 255, 50));
		HPEN oldPen = (HPEN)SelectObject(_hdc, greenPen);

		Rectangle(_hdc
			, pos.x, pos.y
			, pos.x + mSize.x, pos.y + mSize.y);

		SelectObject(_hdc, oldBrush);
		DeleteObject(transparentBrush);

		SelectObject(_hdc, oldPen);
		DeleteObject(greenPen);
	}
}