#pragma once
#include "Commoninclude.h"

namespace ss
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& _name) { mName = _name; }
		std::wstring& GetName() { return mName; }

	private:
		std::wstring mName;
	};
}