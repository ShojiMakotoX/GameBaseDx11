#pragma once
#include "Engine\\GameObject.h"
class Player :
    public GameObject
{
public:
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
private:
	int hModel_;//モデルハンドル
	//Transform tr_;//トランスフォーム（アフィン返還のパラメータを保存している）
};

