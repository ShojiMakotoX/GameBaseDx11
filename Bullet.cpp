#include "Bullet.h"
#include "Engine\\Model.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"),hModel_(-1)
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("StarShip.fbx");
	assert(hModel_ >= 0);
	tr_.position_ = { 0.0f,-4.0f,10.0f };
}

void Bullet::Update()
{

}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, tr_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
