#include "Bullet.h"
#include "Engine\\Model.h"
#include "Player.h"
#include "Engine\\SphereCollider.h"

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
	transform_.scale_ = { 0.5f,0.5f,0.5f };
	//Player* player = static_cast <Player *>(FindObject("Player"));//FindGameObjectみたいなもの


	//transform_.position_ = { 0.0f,-2.0f,10.0f };
	transform_.rotate_ = { 90.0f,0.0f,1.0f };

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(collider);

}

void Bullet::Update()
{
	transform_.position_.z = transform_.position_.z += speed_;
	if (transform_.position_.z > 50.0f)
	{
		KillMe();//消すフラグを立てて、立ってたら消す
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
