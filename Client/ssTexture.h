#pragma once
#include "ssResource.h"

namespace ss
{
	using namespace math;
	enum class eTextureType
	{
		Bmp,
		AlphaBmp,
		Png,
		None,
	};

	class Texture : public Resource
	{
	public:
		Texture();
		virtual ~Texture();

		static Texture* Create(const std::wstring& _name, UINT _width, UINT _height);

		virtual HRESULT Load(const std::wstring& _path) override;

		void Render(HDC _hdc
			, Vector2 _pos
			, Vector2 _size
			, Vector2 _leftTop
			, Vector2 _rightBottom
			, Vector2 _offset = Vector2::Zero
			, Vector2 _scale = Vector2::One
			, float _alpha = 1.0f
			, float _rotate = 0.0f);

		UINT GetWidth() { return mWidth; }
		void SetWidth(UINT _width) { mWidth = _width; }
		UINT GetHeight() { return mHeight; }
		void SetHeight(UINT _height) { mHeight = _height; }
		Vector2 GetOffset() { return mOffset; }
		void SetOffset(Vector2 _offset) { mOffset = _offset; }

		HDC GetHdc() { return mHdc; }
		eTextureType GetType() { return mType; }
		void SetType(eTextureType _type) { mType = _type; }
		Gdiplus::Image* GetImage() { return mImage; }
		void SetHBitmap(HBITMAP _bitmap) { mBitmap = _bitmap; }
		void SetHdc(HDC _hdc) { mHdc = _hdc; }

	private:
		eTextureType mType;
		Gdiplus::Image* mImage;

		HBITMAP mBitmap;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;
		Vector2 mOffset;
		bool mbAffectCamera;
	};
}
