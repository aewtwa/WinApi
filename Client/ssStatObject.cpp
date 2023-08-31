#include "ssStatObject.h"
#include "ssWaterBomb.h"
#include "ssObject.h"
#include "ssPlayer.h"
#include "ssTile.h"

namespace ss
{
	StatObject::StatObject()
		: mStats{}
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
}