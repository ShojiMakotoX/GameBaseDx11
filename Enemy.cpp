#include "Enemy.h"
#include "Engine\\Model.h"
#include "Engine\\SphereCollider.h"


namespace
{
	int WIN_WIDTH = 1500;
	int WIN_HEIGHT = 800;
}
Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	
	hModel_ = Model::Load("spaceShip.fbx");
	assert(hModel_ >= 0);
	//transform_.position_ = { 0.0f,0.0f,20.0f };//位置
	transform_.scale_ = { 0.5f,0.5f,0.5f };//サイズ
	transform_.rotate_ = { 0.0f,0.0f,0.0f };//回転

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 1.0f, 0.0f), 1.0f);
	AddCollider(collider);
}

void Enemy::Update()
{
	static float time = 0.0f;//移動するときにかかる時間

	

	//transform_.rotate_.y += time;//回転させてみる
	time += 0.025f;//増えていく割合
	transform_.position_.x = 6.0f * sin(time);
	float posX = 6.0 * sin(0.2f * time);//どのくらいの割合で移動するか
	//float posY = cos(1.0f * time);

	transform_.position_.x += posX;//情報をposition_.xに代入
	//transform_.position_.y += posY;

	

	
	
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName()=="Bullet")//もし、当たったオブジェクトがバレットならば
	{
		pTarget->KillMe();//バレットを消して
		KillMe();//自分も消す
	}
}
