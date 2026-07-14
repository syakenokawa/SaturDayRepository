#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // ウィンドウモード
    ChangeWindowMode(TRUE);

    // DXライブラリ初期化
    if (DxLib_Init() == -1)
    {
        return -1;
    }

    // ESCキーで終了
    SetDrawScreen(DX_SCREEN_BACK);

    // タイトル画像の読み込み
    int title = LoadGraph("Background");

    while (ProcessMessage() == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        // タイトル画像を表示
        DrawGraph(0, 0, title, TRUE);

        // 画面更新
        ScreenFlip();

        // ESCキーで終了
        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }
    }

    // 画像を削除
    DeleteGraph(title);

    // DXライブラリ終了
    DxLib_End();

    return 0;
}