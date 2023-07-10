#include "ssImage.h"
#include "ssApplication.h"

extern ss::Application application;

namespace ss
{
	Image::Image()
		: mBitmap(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
	{
	}
	Image::~Image()
	{
	}
	HRESULT Image::Load(const std::wstring& _path)
	{
		mBitmap = (HBITMAP)LoadImageW(nullptr, _path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		if (mBitmap == nullptr)
			return S_FALSE;

		BITMAP info = {};
		GetObject(mBitmap, sizeof(BITMAP), &info);

		mWidth = info.bmWidth;
		mHeight = info.bmHeight;

		HDC mainDC = application.GetHdc();
		mHdc = CreateCompatibleDC(mainDC);

		HBITMAP deafultBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
		DeleteObject(deafultBitmap);

		return S_OK;
	}
}