#include "Bullet.h"
#include "Engine\\Model.h"
#include "Player.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"),hModel_(-1),speed_(0.5f)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	Player* player = static_cast <Player *>(FindObject("Player"));//FindGameObjectみたいなもの


	//transform_.position_ = { 0.0f,-2.0f,10.0f };
	transform_.rotate_ = { 90.0f,0.0f,1.0f };
}

void Bullet::Update()
{
	transform_.position_.z = transform_.position_.z += speed_;
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
