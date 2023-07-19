#include "ssTexture.h"
#include "ssApplication.h"
#include "ssResources.h"
#include "ssGameObject.h"
#include "ssTransform.h"
#include "ssCamera.h"

extern ss::Application application;

namespace ss
{
	Texture::Texture()
		: mImage(nullptr)
		, mBitmap(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
		, mType(eTextureType::None)
		, mbAffectCamera(false)
	{
	}
	Texture::~Texture()
	{
		delete mImage;
		mImage = nullptr;

		DeleteObject(mBitmap);
		mBitmap = NULL;
	}
	Texture* Texture::Create(const std::wstring& _name, UINT _width, UINT _height)
	{
		Texture* image = Resources::Find<Texture>(_name);
		if (image != nullptr)
			return image;

		image = new Texture();
		image->SetWidth(_width);
		image->SetHeight(_height);
		HDC hdc = application.GetHdc();
		HBITMAP bitmap = CreateCompatibleBitmap(hdc, _width, _height);
		image->SetHBitmap(bitmap);

		HDC bitmapHdc = CreateCompatibleDC(hdc);
		image->SetHdc(bitmapHdc);

		HBITMAP defaultBitmap = (HBITMAP)SelectObject(bitmapHdc, bitmap);
		DeleteObject(defaultBitmap);

		image->SetName(_name);
		image->SetType(eTextureType::AlphaBmp);
		Resources::Insert<Texture>(_name, image);

		return image;
	}

	HRESULT Texture::Load(const std::wstring& _path)
	{
		std::wstring ext = _path.substr(_path.find_last_of(L".") + 1);
		//bmp 일때
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, _path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);


			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			if (info.bmBitsPixel == 32)
				mType = eTextureType::AlphaBmp;

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);

			HBITMAP deafultBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(deafultBitmap);
		}
		//png 일때
		else if (ext == L"png")
		{
			mType = eTextureType::Png;
			// image.png 파일을 이용하여 Texture 객체를 생성합니다.
			mImage = Gdiplus::Image::FromFile(_path.c_str());

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}

		return S_OK;
	}

	void Texture::Render(HDC _hdc
		, Vector2 _pos
		, Vector2 _size
		, Vector2 _leftTop
		, Vector2 _rightBottom
		, Vector2 _offset
		, Vector2 _scale
		, float _alpha
		, float _rotate)
	{
		if (mBitmap == nullptr && mImage == nullptr)
			return;

		if (mbAffectCamera)
			_pos = Camera::CalculatePosition(_pos);

		if (mType == eTextureType::Bmp)
		{
			TransparentBlt(_hdc, (int)_pos.x - (_size.x * _scale.x / 2.0f) + _offset.x
				, (int)_pos.y - (_size.y * _scale.y / 2.0f) + _offset.y
				, _size.x * _scale.x
				, _size.y * _scale.y
				, mHdc
				, _leftTop.x, _leftTop.y, _rightBottom.x, _rightBottom.y
				, RGB(255, 0, 255));
		}
		else if (mType == eTextureType::AlphaBmp)
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			_alpha = (int)(_alpha * 255.0f);

			if (_alpha <= 0)
				_alpha = 0;
			func.SourceConstantAlpha = _alpha; // 0 ~ 255

			AlphaBlend(_hdc, (int)_pos.x - (_size.x * _scale.x / 2.0f) + _offset.x
				, (int)_pos.y - (_size.y * _scale.y / 2.0f) + _offset.y
				, _size.x * _scale.x
				, _size.y * _scale.y
				, mHdc
				, _leftTop.x, _leftTop.y
				, _rightBottom.x, _rightBottom.y
				, func);
		}
		else if (mType == eTextureType::Png)
		{
			//// 내가 원하는 픽셀을 투명화 시킬떄
			Gdiplus::ImageAttributes imageAtt = {};
			//// 투명화 시킬 픽셀 색 범위
			imageAtt.SetColorKey(Gdiplus::Color(100, 100, 100)
				, Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(_hdc);
			graphics.TranslateTransform((float)_pos.x, (float)_pos.y);
			graphics.RotateTransform(_rotate);
			graphics.TranslateTransform(-(float)_pos.x, -(float)_pos.y);
			graphics.DrawImage(mImage
				, Gdiplus::Rect
				(
					(int)(_pos.x - (_size.x * _scale.x / 2.0f) + _offset.x)
					, (int)(_pos.y - (_size.y * _scale.y / 2.0f) + _offset.y)
					, (int)(_size.x * _scale.x)
					, (int)(_size.y * _scale.y)
				)
				, _leftTop.x, _leftTop.y
				, _rightBottom.x, _rightBottom.y
				, Gdiplus::UnitPixel
				, nullptr);
		}
		Rectangle(_hdc
			, _pos.x - 3, _pos.y - 3
			, _pos.x + 3, _pos.y + 3);
	}
}