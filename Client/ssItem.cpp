#include "ssMonster.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssPlayer.h"
#include "ssCollider.h"
#include "ssResources.h"
#include "ssTexture.h"
#include "ssItem.h"

namespace ss
{
	ss::Item::Item()
	{
	}

	Item::~Item()
	{
	}

	void Item::Initialize()
	{
	}

	void Item::Update()
	{
	}

	void Item::Render(HDC _hdc)
	{
	}

	void Item::OnCollisionEnter(Collider* _other)
	{
	}

	void Item::OnCollisionStay(Collider* _other)
	{
	}

	void Item::OnCollisionExit(Collider* _other)
	{
	}
}