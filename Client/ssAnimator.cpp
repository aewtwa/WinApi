#include "ssAnimator.h"
#include "ssResources.h"

namespace ss
{
	Animator::Animator()
		: Component(eComponentType::Animator)
		, mAlpha(1.0f)
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

	void Animator::CreateAnimation(const std::wstring& _name, Texture* _texture, Vector2 _leftTop, Vector2 _size, Vector2 _offset, UINT _spriteLength, float _duration)
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