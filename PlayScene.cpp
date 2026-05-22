#include "PlayScene.h"
#include "Engine\\Model.h"//画像を読み込むヘッダー
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

namespace
{
}
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),hModel_(-1)//親と名前を渡す
{
}

void PlayScene::Initialize()
{
	

	Instantiate<Player>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
	Instantiate<Enemy>(this);
	//Instantiate<Bullet>(this);

}

void PlayScene::Update()
{

}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
