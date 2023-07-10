#pragma once
#include "ssEntity.h"

namespace ss
{
	class Resource : public Entity
	{
	public:
		Resource();
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& _path) = 0;

		std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& _path) { mPath = _path; }
	private:
		std::wstring mPath;
	};
}
