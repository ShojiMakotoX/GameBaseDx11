#include "PlayScene.h"
#include "Engine\\Model.h"//画像を読み込むヘッダー

namespace
{
	int WIN_WIDTH = 1500;
	int WIN_HEIGHT = 800;
}
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),hModel_(-1)//親と名前を渡す
{
}

void PlayScene::Initialize()
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);

}

void PlayScene::Update()//色々調整したり
{
	static float time;//移動するときにかかる時間

	ot_.position_ = { 0.0f,0.0f,0.0f };//位置
	ot_.scale_ = { 0.5f,0.5f,0.5f };//サイズ
	ot_.rotate_.y += 0.5f;//回転させてみる
	time += 0.1f;//増えていく割合
	float posX = 6.0 * sin(0.2f * time);//どのくらいの割合で移動するか

	ot_.position_.x += posX;//情報をposition_.xに代入


	
}

void PlayScene::Draw()//トランスフォームをセットして描画するだけ
{
	Model::SetTransform(hModel_,ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}
