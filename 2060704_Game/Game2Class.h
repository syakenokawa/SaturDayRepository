#pragma once
#include"Config.h"
#include"Animationヘッダー.h"
#include"Animationソース.cpp"
#include"Framatinヘッダー.h"

class Game2Class
{
private:

	//フレーム
	FrameManager frameManager;
   //アニメーション
	Animation animations;
	//分割
	int images[Config::PLAYER_TOTAL_FRAMES];
	//現在のアニメーション
	AnimationType currenAnim;
	//前回のスペース
	bool oldSpace;

	//アニメーション
	void PlayerAnimation(AnimationType type);
public:
  //初期
	void Init();
	//更新
	void Update();
	//描画




};

