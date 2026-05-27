#include "GameOverScene.h"
#include "Engine\\Image.h"
#include "Engine\\Input.h"
#include "Engine\\SceneManager.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent, "GameOverScene"), hClearPic_(-1)
{
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Initialize()
{
	hClearPic_ = Image::Load("Clear.png");
	assert(hClearPic_ >= 0);
}

void GameOverScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

void GameOverScene::Draw()
{
	Image::SetTransform(hClearPic_, transform_);
	Image::Draw(hClearPic_);
}

void GameOverScene::Release()
{
}
