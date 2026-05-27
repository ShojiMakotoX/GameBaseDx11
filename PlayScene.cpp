#include "PlayScene.h"
#include "Engine\\Model.h"//画像を読み込むヘッダー
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Engine\\SceneManager.h"
#include "Engine\\Camera.h"

namespace
{
}
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),hModel_(-1)//親と名前を渡す
{
}

void PlayScene::Initialize()
{
	
		float posX = ((float)rand() / RAND_MAX * 800.0f) - 400.0f;
		Enemy* e = Instantiate<Enemy>(this);
		e->SetPosition(posX, 0.0f, 20.0f);


	Instantiate<Player>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
	
	//Instantiate<Bullet>(this);

	Camera::SetPosition(XMFLOAT3(0.0f, 5.0f, -10.0f));
	Camera::SetTarget(XMFLOAT3(0.0f, 3.0f, 10.0f));

}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
