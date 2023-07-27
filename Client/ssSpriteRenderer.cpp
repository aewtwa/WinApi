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
	타일 지금 클릭할때만 되는데 드래그로 되게하기 ( 포커스도 고치기)

	easy : 
	물풍선 놓을때 현재 타일 가운데에
	물풍선 터트리기 가로세로 한칸

	물풍선 - 플레이어 충돌시 플레이어 사망 애니메이션 재생, 물풍선 사라지기

	hard :
	맵 밖에 못나가게 충돌

	very hard :
	4방향충돌

	very very hard:
	그 벽 비비면 미끄러지게

	--------------
	Todo Engine
	---------------
	Gameobject가 layer type 가지고 있게
	
	특정 키 눌렀을때 화면의 모든 물풍선만 제거하기 ( 씬에서)

	타일맵에 타일 번호 적기 (왼쪽위에 째깐하게)


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