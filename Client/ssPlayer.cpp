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
#include "ssTile.h"

namespace ss
{
	Player::Player()
		: mState{}
		, mAnimator{}
		, mCollider{}
		, mDeathTime(0.0f)
		, mOnCollision(false)
	{
		SetName(L"Player");
	}

	Player::~Player()
	{
	}

	void Player::Initialize()
	{
		Stat stat = {};
		stat.Speed = 200.0f;
		stat.BombPower = 1;
		stat.Bombs = 1;
		SetStat(stat);

		mState[static_cast<UINT>(Player::eState::Idle)] = true;

		Vector2 Pos = this->GetPos();
		Pos = Vector2(Tile::ConvertNumberToTile(9,9));
		Transform* transform = GetComponent<Transform>();
		transform->SetPosition(Pos);
		SetTransform(transform);
		SetPos(Pos);

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

		// 콜라이더 홀수로 지정하면 1픽셀씩 밀어냄
		mCollider->SetSize(Vector2(50.f, 50.f));
		mCollider->SetOffset(Vector2(0.f, 2.f));

		StatObject::Initialize();
	}

	void Player::Update()
	{
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

		StatObject::Update();
	}

	void Player::Render(HDC _hdc)
	{
		StatObject::Render(_hdc);
	}

	void Player::OnCollisionEnter(Collider* _other)
	{
		if (L"Monster" == _other->GetOwner()->GetName())
		{
			mState[static_cast<UINT>(Player::eState::Trap)] = true;
		}
		if (L"WaterBomb" == _other->GetOwner()->GetName())
		{
			Vector2 Pos = this->GetPos();
			Transform* transform = GetTransform();
			CollideWall(_other);
			transform->SetPosition(Pos);
		}
		if (L"TileBox" == _other->GetOwner()->GetName())
		{
			Vector2 Pos = this->GetPos();
			Transform* transform = GetTransform();
			CollideWall(_other);
			transform->SetPosition(Pos);
		}
		if (L"TileObject" == _other->GetOwner()->GetName())
		{
			Vector2 Pos = this->GetPos();
			Transform* transform = GetTransform();
			CollideWall(_other);
			transform->SetPosition(Pos);
		}
		if (L"ballon" == _other->GetOwner()->GetName())
		{
			Stat stat = this->GetStat();
			stat.Bombs++;
			SetStat(stat);
		}
		if (L"potion" == _other->GetOwner()->GetName())
		{
			Stat stat = this->GetStat();
			stat.BombPower++;
			SetStat(stat);
		}
		if (L"skate" == _other->GetOwner()->GetName())
		{
			Stat stat = this->GetStat();
			stat.Speed *= 1.5f;
			SetStat(stat);
		}
		if (L"WaterFlow" == _other->GetOwner()->GetName())
		{
			mState[static_cast<UINT>(Player::eState::Trap)] = true;
		}
	}
	void Player::OnCollisionStay(Collider* _other)
	{
		if (L"TileBox" == _other->GetOwner()->GetName())
		{
			Vector2 Pos = this->GetPos();
			Transform* transform = GetTransform();
			CollideWall(_other);
			transform->SetPosition(Pos);
		}
		if (L"TileObject" == _other->GetOwner()->GetName())
		{
			Vector2 Pos = this->GetPos();
			Transform* transform = GetTransform();
			CollideWall(_other);
			transform->SetPosition(Pos);
		}
		if (L"WaterBomb" == _other->GetOwner()->GetName())
		{
			if (mOnCollision == false)
			{
				Vector2 Pos = this->GetPos();
				Transform* transform = GetTransform();
				CollideWall(_other);
				transform->SetPosition(Pos);
			}
		}
		
	}
	void Player::OnCollisionExit(Collider* _other)
	{
		if (L"WaterBomb" == _other->GetOwner()->GetName())
		{
			mOnCollision = false;
		}
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

	void Player::Idle()
	{
		std::bitset<static_cast<UINT>(eDirection::End)> direction = GetDirect();
		if (Input::GetKey(eKeyCode::Up))
		{
			mAnimator->PlayAnimation(L"Bazzi_Up", true);
			direction.reset();
			direction[static_cast<UINT>(eDirection::Up)] = true;
			SetDirect(direction);
			mState[static_cast<int>(eState::Move)] = true;
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mAnimator->PlayAnimation(L"Bazzi_Down", true);
			direction.reset();
			direction[static_cast<UINT>(eDirection::Down)] = true;
			SetDirect(direction);
			mState[static_cast<int>(eState::Move)] = true;
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			mAnimator->PlayAnimation(L"Bazzi_Left", true);
			direction.reset();
			direction[static_cast<UINT>(eDirection::Left)] = true;
			SetDirect(direction);
			mState[static_cast<int>(eState::Move)] = true;
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mAnimator->PlayAnimation(L"Bazzi_Right", true);
			direction.reset();
			direction[static_cast<UINT>(eDirection::Right)] = true;
			SetDirect(direction);
			mState[static_cast<int>(eState::Move)] = true;
		}

		if (Input::GetKeyUp(eKeyCode::Up))
		{
			direction[static_cast<UINT>(eDirection::Up)] = false;
			if (Input::AllKeyNone())
			{
				mAnimator->PlayAnimation(L"Bazzi_Up_Idle");
			}
			SetDirect(direction);
		}
		else if (Input::GetKeyUp(eKeyCode::Down))
		{
			direction[static_cast<UINT>(eDirection::Down)] = false;
			if (Input::AllKeyNone())
			{
				mAnimator->PlayAnimation(L"Bazzi_Down_Idle");
			}
			SetDirect(direction);
		}
		else if (Input::GetKeyUp(eKeyCode::Left))
		{
			direction[static_cast<UINT>(eDirection::Left)] = false;
			if (Input::AllKeyNone())
			{
				mAnimator->PlayAnimation(L"Bazzi_Left_Idle");
			}
			SetDirect(direction);
		}
		else if (Input::GetKeyUp(eKeyCode::Right))
		{
			direction[static_cast<UINT>(eDirection::Right)] = false;
			if (Input::AllKeyNone())
			{
				mAnimator->PlayAnimation(L"Bazzi_Right_Idle");
			}
			SetDirect(direction);
		}

		if (Input::GetKey(eKeyCode::Space))
		{
			mState[static_cast<int>(eState::DropWaterBomb)] = true;
		}
	}

	void Player::Move()
	{
		Vector2 Pos = this->GetPos();
		Transform* transform = GetTransform();
		std::bitset<static_cast<UINT>(eDirection::End)> direction = GetDirect();
		if (direction[static_cast<UINT>(eDirection::Up)])
		{
			Pos.y -= this->GetStat().Speed * Time::DeltaTime();
			SetPos(Pos);
		}
		else if (direction[static_cast<UINT>(eDirection::Down)])
		{
			Pos.y += this->GetStat().Speed * Time::DeltaTime();
			SetPos(Pos);
		}
		else if (direction[static_cast<UINT>(eDirection::Left)])
		{
			Pos.x -= this->GetStat().Speed * Time::DeltaTime();
			SetPos(Pos);
		}
		else if (direction[static_cast<UINT>(eDirection::Right)])
		{
			Pos.x += this->GetStat().Speed * Time::DeltaTime();
			SetPos(Pos);
		}
		transform->SetPosition(Pos);

		if (Input::GetKey(eKeyCode::LShift))
		{
			mState[static_cast<int>(eState::DropWaterBomb)] = true;
		}
	}

	void Player::DropWaterBomb()
	{
		StatObject::DropWaterBomb();

		mState[static_cast<int>(eState::DropWaterBomb)] = false;
	}

	void Player::CollideWall(Collider* _other)
	{
		StatObject::CollideWall(_other);
	}

	void Player::Trap()
	{
		mState.reset();
		mAnimator->PlayAnimation(L"Bazzi_Trap");
	}
}