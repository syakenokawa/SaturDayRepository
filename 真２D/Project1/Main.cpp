#include"Dxlib.h"
#include"Conflg.h"
#include "Map.h"
int WINAPI WinMain(HINSTANCE hIstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)return-1;
	SetDrawScreen(DX_SCREEN_BACK);

	MapDialogRect map;

	if (!map.Init())
	{
		map.Finalize();
		DxLib_End();
		return -1;
	}
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		map.Draw();

		ScreenFlip();
	}

	map.Finalize();
	DxLib_End();

	return 0;
















}
























