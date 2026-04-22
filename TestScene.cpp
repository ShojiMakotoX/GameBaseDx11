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
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TestScene::Draw()
{
	Image::SetTransform(hTitlePic_, transform_);//画像の位置や向きなどを指定する
	Image::Draw(hTitlePic_);//画像表示
}

//開放
void TestScene::Release()
{
}
