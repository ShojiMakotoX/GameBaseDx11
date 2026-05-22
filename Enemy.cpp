#include "Enemy.h"
#include "Engine\\Model.h"

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
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);

}

void Enemy::Update()
{
	static float time = 0.0f;//移動するときにかかる時間

	ot_.position_ = { 0.0f,0.0f,10.0f };//位置
	ot_.scale_ = { 0.5f,0.5f,0.5f };//サイズ
	ot_.rotate_ = { 0.0f,0.0f,0.0f };//回転

	//ot_.rotate_.y += time;//回転させてみる
	time += 0.025f;//増えていく割合
	ot_.position_.x = 6.0f * sin(time);
	float posX = 6.0 * sin(0.2f * time);//どのくらいの割合で移動するか
	//float posY = cos(3.0f * time);

	ot_.position_.x += posX;//情報をposition_.xに代入
	//ot_.position_.y += posY;
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
