#include "ssTile.h"
#include "ssSpriteRenderer.h"
#include "ssCollider.h"
#include "ssTexture.h"
#include "ssResources.h"

namespace ss
{
	UINT Tile::mSelectedX = 0;
	UINT Tile::mSelectedY = 0;

	Vector2 Tile::ConvertPosToTile(const Vector2& _pos)
	{
		Vector2 MapIdx = {};

		MapIdx.x = floor((_pos.x - BLANK_WIDTH) / TILE_WIDTH) * TILE_WIDTH + BLANK_WIDTH + TILE_WIDTH / 2;
		MapIdx.y = floor((_pos.y - BLANK_HEIGHT) / TILE_HEIGHT) * TILE_HEIGHT + BLANK_HEIGHT + TILE_HEIGHT / 2;

		return MapIdx;
	}

	Tile::Tile()
		: mSpriteRenderer(nullptr)
		, mCollider(nullptr)
		, mSourceIndexX(0)
		, mSourceIndexY(0)
		, mIndexX(0)
		, mIndexY(0)
	{
		SetName(L"Tile");
	}

	Tile::~Tile()
	{
	}

	void Tile::Initialize()
	{
		mSpriteRenderer = AddComponent<SpriteRenderer>();
		//AddComponent<Collider>();

		Texture* Campmap = Resources::Find<Texture>(L"Tile");
		mSpriteRenderer->SetImage(Campmap);
		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(52.0f, 52.0f));
	}

	void Tile::Update()
	{
		GameObject::Update();
	}

	void Tile::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}

	void Tile::OnCollisionEnter(Collider* _other)
	{
	}

	void Tile::OnCollisionStay(Collider* _other)
	{
	}

	void Tile::OnCollisionExit(Collider* _other)
	{
	}

	void Tile::SetTile(int _x, int _y)
	{
		mSpriteRenderer->SetTile(_x, _y);
	}
}