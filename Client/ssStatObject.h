#pragma once
#include "ssGameObject.h"

namespace ss
{
	class StatObject : public GameObject
	{
	public:
		struct Stat
		{
			float Speed;
			UINT BombPower;
			UINT Bombs;
		};

		StatObject();
		virtual ~StatObject();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC _hdc) override;

		virtual void OnCollisionEnter(class Collider* _other) override;
		virtual void OnCollisionStay(class Collider* _other) override;
		virtual void OnCollisionExit(class Collider* _other) override;

		virtual void DropWaterBomb();
		virtual void CollideWall(Collider* _other);

		void SetDirection(eDirection _dir);
		eDirection CurDirection_flag();
		Vector2 CurDirection();

		Stat GetStat() const { return mStats; }
		void SetStat(Stat _Stat) { mStats = _Stat; }

		Vector2 GetPos() { return mPos; }
		void SetPos(Vector2 _pos) { mPos = _pos; }

		Transform* GetTransform() { return mTransform; }
		void SetTransform(Transform* _transform) { mTransform = _transform; }

	private:
		class Transform* mTransform;
		std::bitset<static_cast<UINT>(eDirection::End)> mDirection;

		Vector2 mPos;
		Stat mStats;
	};
}
