#include<tchar.h>
#include "20260716_Header_umi.h"
int scene = GROW1;
int clickCount = 0;

int taneImg;
int meImg;
int hanaImg;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//画像読み込み
	taneImg = LoadGraph(_T("tane.png"));
	meImg = LoadGraph(_T("me.png"));
	hanaImg = LoadGraph(_T("hana.png"));

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();

		switch (scene)
		{
		case GROW1:
			Grow();
			break;

		case CLEAR:
			Clear();
			break;
		}

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}