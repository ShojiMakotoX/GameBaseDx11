#include "Bullet.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"

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
	tr_.position_ = { 0.0f,-2.0f,10.0f };
	tr_.rotate_ = { 90.0f,0.0f,1.0f };
}

void Bullet::Update()
{
	if (Input::IsKey(DIK_SPACE))
	{
		//Instantiate<Bullet>(this);
		//tr_.position_.z = tr_.position_.z += 0.5f;
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, tr_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
