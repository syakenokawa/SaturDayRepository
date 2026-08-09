#include "motoClass.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    if (DxLib_Init() == -1)
    {
        return -1;
    }

    playerImg = LoadGraph("playe.png");

    SetDrawScreen(DX_SCREEN_BACK);

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();

        PlayerMove();

        PlayerDraw();

        ScreenFlip();

        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }
    }

    DeleteGraph(playerImg);

    DxLib_End();

    return 0;
}

















