#include "TestScene.h"
#include "Engine\\Image.h"
#include "Engine\\Input.h"
#include "Engine\\SceneManager.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene"),hTitlePic_(-1)
{
}

//初期化
void TestScene::Initialize()
{
	hTitlePic_ = Image::Load("Title2.png");
	assert(hTitlePic_ >= 0);

}

//更新
void TestScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))//キーが押されたら画面が変わる
	{
		//見つからない場合はnullptrを返すので、nullptrでないことを確認してから使う
		//SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TestScene::Draw()
{
	//transform_.position_ = { 400.0f,300.0f,0.0f };//画像の位置を変更
	//transform_.rotate_ = { 0.0f,0.0f,0.0f };//画像の回転を変更

	transform_.scale_ = { 1.5f,1.5f,1.0f };//画像の大きさを変更する
	Image::SetTransform(hTitlePic_, transform_);//画像の位置や向きなどを指定する
	Image::Draw(hTitlePic_);//画像表示
}

//開放
void TestScene::Release()
{
}
