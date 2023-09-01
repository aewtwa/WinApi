#include "ssStatObject.h"
#include "ssWaterBomb.h"
#include "ssObject.h"
#include "ssPlayer.h"
#include "ssTile.h"

namespace ss
{
	StatObject::StatObject()
		: mTransform{}
		, mPos(Vector2::Zero)
		, mStats{}
	{
	}
	StatObject::~StatObject()
	{
	}
	void StatObject::Initialize()
	{
		GameObject::Initialize();
	}
	void StatObject::Update()
	{
		GameObject::Update();
	}
	void StatObject::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
	void StatObject::OnCollisionEnter(Collider* _other)
	{
	}
	void StatObject::OnCollisionStay(Collider* _other)
	{
	}
	void StatObject::OnCollisionExit(Collider* _other)
	{
	}
	void StatObject::DropWaterBomb()
	{
		if (this->GetStat().Bombs > 0)
		{
			Vector2 BombPos = Tile::ConvertPosToTile(GetComponent<Transform>()->GetPosition());
			WaterBomb* WB = Object::Instantiate<WaterBomb>(eLayerType::WaterBomb, BombPos);
			WB->SetOwner(this);
			Stat stat = this->GetStat();
			stat.Bombs--;
			SetStat(stat);
		}
	}

	void StatObject::CollideWall(Collider* _other)
	{
		eDirection CurDir = CurDirection_flag();
		if (CurDir == eDirection::Down || CurDir == eDirection::Left)
		{
			RECT resultRect = GetInterSectColliderRect(_other);

			Vector2 interSectVec = { static_cast<float>(resultRect.right - resultRect.left)
				, static_cast<float>(resultRect.top - resultRect.bottom) };

			Vector2 curDir = CurDirection();
			interSectVec = curDir * interSectVec;

			this->mPos += curDir * interSectVec;
			SetPos(this->mPos);
		}
		else if (CurDir == eDirection::Up || CurDir == eDirection::Right)
		{
			RECT resultRect = GetInterSectColliderRect(_other);

			Vector2 interSectVec = { static_cast<float>(resultRect.right - resultRect.left)
				, static_cast<float>(resultRect.top - resultRect.bottom) };

			Vector2 curDir = CurDirection();
			interSectVec = curDir * interSectVec;

			this->mPos -= curDir * interSectVec;
			SetPos(this->mPos);
		}

		mTransform->SetPosition(mPos);
	}
	void StatObject::SetDirection(eDirection _dir)
	{
		mDirection.reset();
		mDirection[static_cast<UINT>(_dir)] = true;
	}
	eDirection StatObject::CurDirection_flag()
	{
		for (size_t i = 0; i < mDirection.size(); i++)
		{
			if (mDirection[i])
			{
				return static_cast<eDirection>(i);
			}
		}
	}
	Vector2 StatObject::CurDirection()
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