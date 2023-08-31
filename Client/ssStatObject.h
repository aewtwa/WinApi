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

		Stat GetStat() const { return mStats; }
		void SetStat(Stat _Stat) { mStats = _Stat; }

	private:
		Stat mStats;
	};
}
