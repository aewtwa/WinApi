#include "ssWaterBomb.h"
#include "ssTransform.h"
#include "ssTime.h"
#include "ssAnimator.h"
#include "ssCollider.h"
#include "ssResources.h"
#include "ssTexture.h"
#include "ssPlayer.h"
#include "ssObject.h"
#include "ssWaterFlow.h"
#include "ssStatObject.h"
#include "ssGameObject.h"
#include "ssScene.h"
#include "ssSceneManager.h"

namespace ss
{
	WaterBomb::WaterBomb()
		: mAnimator{}
		, mCollider{}
		, mTransform{ GetComponent<Transform>() }
		, mBombtime(0.0f)
		, mPos(Vector2::Zero)
		, mState{}
		, mDirection{}
		, mOwner{nullptr}
	{
		SetName(L"WaterBomb");
	}

	WaterBomb::~WaterBomb()
	{
	}

	void WaterBomb::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimationFolder(L"WaterBombIdle", L"..\\Resources\\Image\\Bomb\\Idle", Vector2(0.0f, 0.0f), 0.16f);
		mAnimator->SetScale(Vector2(1.2f, 1.2f));

		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(45.0f, 45.0f));

		mState[static_cast<UINT>(eWaterBombState::Created)] = true;

		GameObject::Initialize();
	}
	void WaterBomb::Update()
	{
		if (mState[static_cast<UINT>(eWaterBombState::Created)])
		{
			Created();
		}
		if (mState[static_cast<UINT>(eWaterBombState::Idle)])
		{
			Idle();
		}

		GameObject::Update();
	}
	void WaterBomb::Render(HDC _hdc)
	{
		GameObject::Render(_hdc);
	}
	void WaterBomb::OnCollisionEnter(Collider* _other)
	{
	}
	void WaterBomb::OnCollisionStay(Collider* other)
	{
	}
	void WaterBomb::OnCollisionExit(Collider* other)
	{
	}

	void WaterBomb::Created()
	{
		mAnimator->PlayAnimation(L"WaterBombIdle", true);
		mState.reset();
		mState[static_cast<UINT>(eWaterBombState::Idle)] = true;
	}

	void WaterBomb::Idle()
	{
		if (2.0f < mBombtime)
		{
			mPos = mTransform->GetPosition();

			WaterFlow* WF = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, mPos);
			WF->GetComponent<Animator>()->PlayAnimation(L"BombCenterflow");

			Scene* scene = SceneManager::GetActiveScene();
			std::vector<GameObject*> v = scene->GetLayer(eLayerType::TileBox).GetGameObjects();
			std::vector<GameObject*> b = scene->GetLayer(eLayerType::TileObject).GetGameObjects();

			Vector2 tilePos = {};
			Vector2 objectPos = {};
			bool flag = 0;

			for (size_t i = 1; i <= this->mOwner->GetStat().BombPower; i++)
			{
				Vector2 UpPos = mPos;
				UpPos.y = UpPos.y - TILE_HEIGHT * i;

				for (size_t i = 0; i < v.size(); i++)
				{
					tilePos = v[i]->GetComponent<Transform>()->GetPosition();
					if (UpPos == tilePos)
					{
						WaterFlow* WFU = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, UpPos);
						WFU->GetComponent<Animator>()->PlayAnimation(L"BombUpflow");
						flag = 1;
						break;
					}
				}
				
				for (size_t i = 0; i < b.size(); i++)
				{
					objectPos = b[i]->GetComponent<Transform>()->GetPosition();
					if (UpPos == objectPos)
					{
						flag = 1;
						break;
					}
				}

				if (flag)
				{
					flag = 0;
					break;
				}

				WaterFlow* WFU = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, UpPos);
				WFU->GetComponent<Animator>()->PlayAnimation(L"BombUpflow");
			}
			for (size_t i = 1; i <= this->mOwner->GetStat().BombPower; i++)
			{
				Vector2 DownPos = mPos;
				DownPos.y = DownPos.y + TILE_HEIGHT * i;

				for (size_t i = 0; i < v.size(); i++)
				{
					tilePos = v[i]->GetComponent<Transform>()->GetPosition();
					if (DownPos == tilePos)
					{
						WaterFlow* WFD = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, DownPos);
						WFD->GetComponent<Animator>()->PlayAnimation(L"BombDownflow");
						flag = 1;
						break;
					}
				}

				for (size_t i = 0; i < b.size(); i++)
				{
					objectPos = b[i]->GetComponent<Transform>()->GetPosition();
					if (DownPos == objectPos)
					{
						flag = 1;
						break;
					}
				}

				if (flag)
				{
					flag = 0;
					break;
				}

				WaterFlow* WFD = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, DownPos);
				WFD->GetComponent<Animator>()->PlayAnimation(L"BombDownflow");
			}
			for (size_t i = 1; i <= this->mOwner->GetStat().BombPower; i++)
			{
				Vector2 LeftPos = mPos;
				LeftPos.x = LeftPos.x - TILE_WIDTH * i;

				for (size_t i = 0; i < v.size(); i++)
				{
					tilePos = v[i]->GetComponent<Transform>()->GetPosition();
					if (LeftPos == tilePos)
					{
						WaterFlow* WFL = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, LeftPos);
						WFL->GetComponent<Animator>()->PlayAnimation(L"BombLeftflow");
						flag = 1;
						break;
					}
				}

				for (size_t i = 0; i < b.size(); i++)
				{
					objectPos = b[i]->GetComponent<Transform>()->GetPosition();
					if (LeftPos == objectPos)
					{
						flag = 1;
						break;
					}
				}

				if (flag)
				{
					flag = 0;
					break;
				}

				WaterFlow* WFL = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, LeftPos);
				WFL->GetComponent<Animator>()->PlayAnimation(L"BombLeftflow");
			}
			for (size_t i = 1; i <= this->mOwner->GetStat().BombPower; i++)
			{
				Vector2 RightPos = mPos;
				RightPos.x = RightPos.x + TILE_WIDTH * i;

				for (size_t i = 0; i < v.size(); i++)
				{
					tilePos = v[i]->GetComponent<Transform>()->GetPosition();
					if (RightPos == tilePos)
					{
						WaterFlow* WFR = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, RightPos);
						WFR->GetComponent<Animator>()->PlayAnimation(L"BombRightflow");
						flag = 1;
						break;
					}
				}

				for (size_t i = 0; i < b.size(); i++)
				{
					objectPos = b[i]->GetComponent<Transform>()->GetPosition();
					if (RightPos == objectPos)
					{
						flag = 1;
						break;
					}
				}

				if (flag)
				{
					flag = 0;
					break;
				}

				WaterFlow* WFR = Object::Instantiate<WaterFlow>(eLayerType::WaterFlow, RightPos);
				WFR->GetComponent<Animator>()->PlayAnimation(L"BombRightflow");
			}




			Stat stat = this->mOwner->GetStat();
			stat.Bombs++;
			this->mOwner->SetStat(stat);

			Destroy(this);
		}
		else
		{
			mBombtime += Time::DeltaTime();
		}

	}
}