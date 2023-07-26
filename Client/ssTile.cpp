#include "ssTile.h"
#include "ssSpriteRenderer.h"
#include "ssCollider.h"
#include "ssTexture.h"
#include "ssResources.h"

namespace ss
{
	UINT Tile::mSelectedX = 0;
	UINT Tile::mSelectedY = 0;

	Tile::Tile()
		: mSpriteRenderer(nullptr)
	{
	}

	Tile::~Tile()
	{
	}

	void Tile::Initialize()
	{
		mSpriteRenderer = AddComponent<SpriteRenderer>();
		//AddComponent<Collider>();

		ss::Texture* Campmap = ss::Resources::Find<ss::Texture>(L"CampmapTile");

		mSpriteRenderer->SetImage(Campmap);
		mSpriteRenderer->SetScale(Vector2(1.0f, 1.0f));
	}

	void Tile::Update()
	{
		GameObject::Update();
	}

	void Tile::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}

	void Tile::SetTile(int _x, int _y)
	{
		mSpriteRenderer->SetTile(_x, _y);
	}
}