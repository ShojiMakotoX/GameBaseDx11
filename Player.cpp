#include "Player.h"
#include "Engine\\Model.h"

Player::Player(GameObject* parent)
//親のポインタ、オブジェクトの名前
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("StarShip.fbx");
	assert(hModel_ >= 0);
}

void Player::Update()
{
}

void Player::Draw()
{
	Model::SetTransform(hModel_, tr_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
