#pragma once
class FrameManager
{
private:
   //
  //フレームカウンター
  // 
	int frameCounter;
public:

	//コンスタ
	FrameManager();


	//更新
	void Update();


	//フレームカウンターの取得
	int GetFrameCounter() const;
};


