#include "ssSpriteRenderer.h"
#include "ssTransform.h"
#include "ssGameObject.h"
#include "ssCamera.h"

namespace ss
{

	/*
	--------------
	Todo Collision
	---------------
	Ÿ�� ���� Ŭ���Ҷ��� �Ǵµ� �巡�׷� �ǰ��ϱ� ( ��Ŀ���� ��ġ��)

	easy : 
	��ǳ�� ������ ���� Ÿ�� �����
	��ǳ�� ��Ʈ���� ���μ��� ��ĭ

	��ǳ�� - �÷��̾� �浹�� �÷��̾� ��� �ִϸ��̼� ���, ��ǳ�� �������

	hard :
	�� �ۿ� �������� �浹

	very hard :
	4�����浹

	very very hard:
	�� �� ���� �̲�������

	--------------
	Todo Engine
	---------------
	Gameobject�� layer type ������ �ְ�
	
	Ư�� Ű �������� ȭ���� ��� ��ǳ���� �����ϱ� ( ������)

	Ÿ�ϸʿ� Ÿ�� ��ȣ ���� (�������� °���ϰ�)


	*/

	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::SpriteRenderer)
		, mbAffectCamera(true)
		, mbTile(false)
		, mTexture(nullptr)
		, mScale(Vector2::One)
		, mAlpha(1.0f)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::Render(HDC _hdc)
	{
		if (mTexture == nullptr)
			return;

		if (mbTile)
		{
			GameObject* gameObj = GetOwner();
			Transform* tr = gameObj->GetComponent<Transform>();

			mTexture->Render(_hdc
				, tr->GetPosition()
				, Vector2(TILE_WIDTH, TILE_HEIGHT)
				, Vector2(mTileIndexX * TILE_WIDTH
					, mTileIndexY * TILE_HEIGHT)
				, Vector2(TILE_WIDTH, TILE_HEIGHT)
				, Vector2::Zero
				, mScale
				, mAlpha
				, tr->GetRotation());
		}
		else
		{
			GameObject* gameObj = GetOwner();
			Transform* tr = gameObj->GetComponent<Transform>();
			mTexture->Render(_hdc
				, tr->GetPosition()
				, Vector2(mTexture->GetWidth(), mTexture->GetHeight())
				, Vector2(0.0f, 0.0f)
				, Vector2(mTexture->GetWidth(), mTexture->GetHeight())
				, Vector2::Zero
				, mScale
				, mAlpha
				, tr->GetRotation());
		}
	}
}