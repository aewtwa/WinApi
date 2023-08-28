#include "ssPlayer.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssInput.h"
#include "ssWaterBomb.h"
#include "ssMonster.h"
#include "ssCollider.h"
#include "ssCollisionManager.h"
#include "ssResources.h"
#include "ssTexture.h"
#include "ssObject.h"

namespace ss
{
	Player::Player()
		: mState{}
		, mDirection{}
		, mTransform{ GetComponent<Transform>() }
		, mAnimator{}
		, mCollider{}
		, mDeathTime(0.0f)
		, mOnCollision(false)
		, mSpeed(200.f)
		, mWaterBombs(1)
		, mWaterBombPower(1)
	{
		SetName(L"Player");
	}

	Player::~Player()
	{
	}

	void Player::Initialize()
	{
		mPos = mTransform->GetPosition();
		mPos = Vector2((BLANK_WIDTH + TILE_WIDTH / 2) + TILE_WIDTH, (BLANK_HEIGHT + TILE_HEIGHT / 2) + TILE_HEIGHT);
		mTransform->SetPosition(mPos);

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"Bazzi_Idle", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 0.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.3f);
		mAnimator->CreateAnimation(L"Bazzi_Up", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 60.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Left", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 180.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Down", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 120.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Right", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 240.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Death", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 300.0f), Vector2(50.0f, 60.0f), 4, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Up_Idle", Resources::Find<Texture>(L"Bazzi"), Vector2(0.0f, 360.0f), Vector2(50.0f, 60.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Left_Idle", Resources::Find<Texture>(L"Bazzi"), Vector2(100.0f, 360.0f), Vector2(50.0f, 60.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Down_Idle", Resources::Find<Texture>(L"Bazzi"), Vector2(50.0f, 360.0f), Vector2(50.0f, 60.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Right_Idle", Resources::Find<Texture>(L"Bazzi"), Vector2(150.0f, 360.0f), Vector2(50.0f, 60.0f), 1, Vector2(0.0f, 0.0f), 0.1f);
		mAnimator->CreateAnimation(L"Bazzi_Trap", Resources::Find<Texture>(L"Bazzi_Trap"), Vector2(0.0f, 0.0f), Vector2(88.0f, 144.0f), 13, Vector2(0.0f, 0.0f), 0.2f);
		mAnimator->CreateAnimation(L"Bazzi_Die", Resources::Find<Texture>(L"Bazzi_Die"), Vector2(0.0f, 0.0f), Vector2(88.0f, 144.0f), 13, Vector2(0.0f, 0.0f), 0.2f);
		mAnimator->PlayAnimation(L"Bazzi_Idle", true);

		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(50.0f, 60.0f));

		GameObject::Initialize();
	}

	void Player::Update()
	{
		if (Input::AllKeyNone())
		{
			mState.reset();
			mDirection.reset();
			mState[static_cast<UINT>(Player::eState::Idle)] = true;
		}
		if (mState[static_cast<UINT>(Player::eState::Idle)])
		{
			Idle();
		}
		if (mState[static_cast<UINT>(Player::eState::Move)])
		{
			Move();
		}
		if (mState[static_cast<UINT>(Player::eState::DropWaterBomb)])
		{
			DropWaterBomb();
		}
		if (mState[static_cast<UINT>(Player::eState::Trap)])
		{
			Trap();
		}
		GameObject::Update();
	}

	void Player::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}

	void Player::OnCollisionEnter(Collider* _other)
	{
		if (L"Monster" == _other->GetOwner()->GetName())
		{
			mAnimator->PlayAnimation(L"Bazzi_Trap", true);
			mState[static_cast<UINT>(Player::eState::Trap)] = true;
			// 여기서 다이나믹캐스트를 씁니다.
			// _other->GetOwner()얘는 게임 오브젝트임
			// 얘를 다오로 형변환 해주는거임 (다오는 예시)
			// 그럼 형변환 된 _other->GetOwner()를 dao 형으로 사용할 수 있음
		}
		if (L"WaterBomb" == _other->GetOwner()->GetName())
		{

		}
		if (L"Tile" == _other->GetOwner()->GetName())
		{
			eDirection CurDir = CurDirection_flag();
			if (CurDir == eDirection::Down || CurDir == eDirection::Left)
			{
				RECT resultRect = GetInterSectColliderRect(_other);

				Vector2 interSectVec = { static_cast<float>(resultRect.right - resultRect.left)
					, static_cast<float>(resultRect.top - resultRect.bottom) };

				Vector2 curDir = CurDirection();
				interSectVec = curDir * interSectVec;

				mPos += curDir * interSectVec;
			}
			else if (CurDir == eDirection::Up || CurDir == eDirection::Right)
			{
				RECT resultRect = GetInterSectColliderRect(_other);

				Vector2 interSectVec = { static_cast<float>(resultRect.right - resultRect.left)
					, static_cast<float>(resultRect.top - resultRect.bottom) };

				Vector2 curDir = CurDirection();
				interSectVec = curDir * interSectVec;

				mPos -= curDir * interSectVec;
			}

			mTransform->SetPosition(mPos);
		}
	}
	void Player::OnCollisionStay(Collider* _other)
	{
		if (L"Tile" == _other->GetOwner()->GetName())
		{
			eDirection CurDir = CurDirection_flag();
			if (CurDir == eDirection::Down || CurDir == eDirection::Left)
			{
				RECT resultRect = GetInterSectColliderRect(_other);

				Vector2 interSectVec = { static_cast<float>(resultRect.right - resultRect.left)
					, static_cast<float>(resultRect.top - resultRect.bottom) };

				Vector2 curDir = CurDirection();
				interSectVec = curDir * interSectVec;

				mPos += curDir * interSectVec;
			}
			else if (CurDir == eDirection::Up || CurDir == eDirection::Right)
			{
				RECT resultRect = GetInterSectColliderRect(_other);

				Vector2 interSectVec = { static_cast<float>(resultRect.right - resultRect.left)
					, static_cast<float>(resultRect.top - resultRect.bottom) };

				Vector2 curDir = CurDirection();
				interSectVec = curDir * interSectVec;

				mPos -= curDir * interSectVec;
			}
			mTransform->SetPosition(mPos);
		}
	}
	void Player::OnCollisionExit(Collider* _other)
	{
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

	Vector2 Player::GetMapIDX()
	{
		Vector2 MapIdx = {};

		MapIdx.x = floor((mPos.x - BLANK_WIDTH) / TILE_WIDTH) * TILE_WIDTH + BLANK_WIDTH + TILE_WIDTH / 2;
		MapIdx.y = floor((mPos.y - BLANK_HEIGHT) / TILE_HEIGHT) * TILE_HEIGHT + BLANK_HEIGHT + TILE_HEIGHT / 2;

		return MapIdx;
	}

	void Player::Idle()
	{
		if (Input::GetKey(eKeyCode::W))
		{
			mAnimator->PlayAnimation(L"Bazzi_Up", true);
			SetDirection(eDirection::Up);
			mState[static_cast<int>(eState::Move)] = true;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mAnimator->PlayAnimation(L"Bazzi_Down", true);
			SetDirection(eDirection::Down);
			mState[static_cast<int>(eState::Move)] = true;
		}
		if (Input::GetKey(eKeyCode::A))
		{
			mAnimator->PlayAnimation(L"Bazzi_Left", true);
			SetDirection(eDirection::Left);
			mState[static_cast<int>(eState::Move)] = true;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mAnimator->PlayAnimation(L"Bazzi_Right", true);
			SetDirection(eDirection::Right);
			mState[static_cast<int>(eState::Move)] = true;
		}

		if (Input::GetKeyUp(eKeyCode::W))
		{
			mDirection[static_cast<UINT>(eDirection::Up)] = false;
			if (Input::AllKeyNone())
			{
				mAnimator->PlayAnimation(L"Bazzi_Up_Idle");
			}
		}
		else if (Input::GetKeyUp(eKeyCode::S))
		{
			mDirection[static_cast<UINT>(eDirection::Down)] = false;
			if (Input::AllKeyNone())
			{
				mAnimator->PlayAnimation(L"Bazzi_Down_Idle");
			}
		}
		else if (Input::GetKeyUp(eKeyCode::A))
		{
			mDirection[static_cast<UINT>(eDirection::Left)] = false;
			if (Input::AllKeyNone())
			{
				mAnimator->PlayAnimation(L"Bazzi_Left_Idle");
			}
		}
		else if (Input::GetKeyUp(eKeyCode::D))
		{
			mDirection[static_cast<UINT>(eDirection::Right)] = false;
			if (Input::AllKeyNone())
			{
				mAnimator->PlayAnimation(L"Bazzi_Right_Idle");
			}
		}

		if (Input::GetKey(eKeyCode::LShift))
		{
			mState[static_cast<int>(eState::DropWaterBomb)] = true;
		}
	}

	void Player::Move()
	{
		if (mDirection[static_cast<UINT>(eDirection::Up)])
		{
			mPos.y -= mSpeed * Time::DeltaTime();
		}
		else if (mDirection[static_cast<UINT>(eDirection::Down)])
		{
			mPos.y += mSpeed * Time::DeltaTime();
		}
		else if (mDirection[static_cast<UINT>(eDirection::Left)])
		{
			mPos.x -= mSpeed * Time::DeltaTime();
		}
		else if (mDirection[static_cast<UINT>(eDirection::Right)])
		{
			mPos.x += mSpeed * Time::DeltaTime();
		}
		mTransform->SetPosition(mPos);

		if (Input::GetKey(eKeyCode::LShift))
		{
			mState[static_cast<int>(eState::DropWaterBomb)] = true;
		}
	}

	void Player::DropWaterBomb()
	{
		Vector2 BombPos = GetMapIDX();
		WaterBomb* WB = Object::Instantiate<WaterBomb>(eLayerType::WaterBomb, BombPos);
		mState[static_cast<int>(eState::DropWaterBomb)] = false;
	}

	void Player::Trap()
	{
		mState[static_cast<int>(eState::Idle)] = false;
		mState[static_cast<int>(eState::Move)] = false;
		mState[static_cast<int>(eState::DropWaterBomb)] = false;
		mState[static_cast<int>(eState::Trap)] = false;
		mAnimator->PlayAnimation(L"Bazzi_Trap");
	}
	void Player::SetDirection(eDirection _dir)
	{
		mDirection.reset();
		mDirection[static_cast<UINT>(_dir)] = true;
	}
	eDirection Player::CurDirection_flag()
	{
		for (size_t i = 0; i < mDirection.size(); i++)
		{
			if (mDirection[i])
			{
				return static_cast<eDirection>(i);
			}
		}
	}
	Vector2 Player::CurDirection()
	{
		eDirection Dir = CurDirection_flag();

		switch (Dir)
		{
		case ss::enums::eDirection::Up:
			return { 0.f, -1.f };
			break;
		case ss::enums::eDirection::Down:
			return { 0.f, 1.f };
			break;
		case ss::enums::eDirection::Left:
			return { -1.f, 0.f };
			break;
		case ss::enums::eDirection::Right:
			return { 1.f, 0.f };
			break;
		case ss::enums::eDirection::End:
		default:
			return { 0.f, 0.f };
			break;
		}

		return { 0.f, 0.f };
	}
}