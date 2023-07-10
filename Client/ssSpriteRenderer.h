#pragma once
#include "ssComponent.h"
#include "ssImage.h"
namespace ss
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		void SetImage(Image* _image) { mImage = _image; }
	private:
		Image* mImage;
	};

}