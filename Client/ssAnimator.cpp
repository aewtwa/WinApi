#include "ssAnimator.h"
#include "ssResources.h"
#include "ssTexture.h"

namespace ss
{
	Animator::Animator()
		: Component(eComponentType::Animator)
		, mActiveAnimation()
		, mbAffectedCamera(false)
		, mbLoop(true)
		, mAlpha(1.0f)
		, mScale(Vector2::One)
	{
	}
	Animator::~Animator()
	{
	}
	void Animator::Initialize()
	{
	}
	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();
			if (mActiveAnimation->IsComplete() && mbLoop)
			{
				mActiveAnimation->Reset();
			}
		}
	}

	void Animator::Render(HDC _hdc)
	{
		if (mActiveAnimation)
			mActiveAnimation->Render(_hdc);
	}

	void Animator::CreateAnimation(const std::wstring& _name
		, Texture* _texture
		, Vector2 _leftTop, Vector2 _size
		, UINT _spriteLength, Vector2 _offset
		, float _duration)
	{
		Animation* animation = nullptr;
		animation = Resources::Find<Animation>(_name);
		if (animation != nullptr)
			return;

		animation = new Animation();
		animation->Create(_name, _texture
			, _leftTop, _size, _offset
			, _spriteLength, _duration);
		animation->SetAnimator(this);

		mAnimations.insert(std::make_pair(_name, animation));
		Resources::Insert<Animation>(_name, animation);
	}

	void Animator::CreateAnimationFolder(const std::wstring& _name
		, const std::wstring& _path, Vector2 _offset, float _duration)
	{
		UINT width = 0;
		UINT height = 0;
		UINT fileCout = 0;

		std::filesystem::path fs(_path);
		std::vector<Texture*> images = {};
		for (auto& p : std::filesystem::recursive_directory_iterator(_path))
		{
			std::wstring fileName = p.path().filename();
			std::wstring fullName = p.path();

			Texture* image = Resources::Load<Texture>(fileName, fullName);
			images.push_back(image);

			if (width < image->GetWidth())
				width = image->GetWidth();

			if (height < image->GetHeight())
				height = image->GetHeight();

			fileCout++;
		}

		Texture* spriteSheet = Texture::Create(_name, width * fileCout, height);

		int idx = 0;
		for (Texture* image : images)
		{
			BitBlt(spriteSheet->GetHdc(), width * idx, 0
				, image->GetWidth(), image->GetHeight()
				, image->GetHdc(), 0, 0, SRCCOPY);

			idx++;
		}

		CreateAnimation(_name
			, spriteSheet, Vector2(0.0f, 0.0f)
			, Vector2(width, height), fileCout
			, _offset, _duration);
	}

	Animation* Animator::FindAnimation(const std::wstring& _name)
	{
		auto iter = mAnimations.find(_name);
		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
	}

	void Animator::PlayAnimation(const std::wstring& _name, bool _loop)
	{
		Animation* animation = FindAnimation(_name);
		if (animation == nullptr)
			return;

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = _loop;
	}
}