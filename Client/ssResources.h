#pragma once
#include "ssResource.h"

namespace ss
{
	class Resources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& _name)
		{
			auto iter = mResources.find(_name);
			if (iter == mResources.end())
				return nullptr;

			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& _name, const std::wstring& _path)
		{
			T* resource = Resources::Find<T>(_name);

			if (resource != nullptr)
				return resource;

			resource = new T;
			if (FAILED(resource->Load(_path)))
			{
				MessageBox(nullptr, L"Resource Load Failed!", L"Error", MB_OK);
				delete resource;
				return nullptr;
			}

			resource->SetName(_name);
			resource->SetPath(_path);
			mResources.insert(std::make_pair(_name, resource));

			return resource;
		}

		template <typename T>
		static void Insert(const std::wstring& _name, T* _resource)
		{
			_resource->SetName(_name);
			mResources.insert(std::make_pair(_name, _resource));
		}

	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}
