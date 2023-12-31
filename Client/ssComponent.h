#pragma once
#include "ssEntity.h"

namespace ss
{
	using namespace enums;
	class Component : public Entity
	{
	public:
		Component(eComponentType _type);
		virtual ~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);

		void SetOwner(class GameObject* _owner) { mOwner = _owner; }
		class GameObject* GetOwner() { return mOwner; }

	private:
		const eComponentType mType;
		class GameObject* mOwner;
	};
}

