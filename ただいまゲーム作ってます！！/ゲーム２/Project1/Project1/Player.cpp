#include "DxLib.h"
#include"Map.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    // ウィンドウを表示する
    ChangeWindowMode(TRUE);

    // DxLibを初期化する
    if (DxLib_Init() == -1)
    {
        return -1;
    }

    // 裏画面に描画する
    SetDrawScreen(DX_SCREEN_BACK);

    // 画面の大きさカメラ
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 500;
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);


    //マップ
    Map map;
    map.Initialize();

    // 画像を読み込む
    SetTransColor(0, 0, 0);
    int playerImage = LoadGraph("ge-mu/player.bmp.png");

    if (playerImage == -1)
    {
        MessageBox(NULL,
            "画像を読み込めませんでした。ファイル名と場所を確認してください。",
            "エラー", MB_OK);

        DxLib_End();
        return -1;
    }

    // 画像全体のサイズ
    int imageWidth, imageHeight;
    GetGraphSize(playerImage, &imageWidth, &imageHeight);
    // 画像サイズを表示
    DrawFormatString(
        10, 100,
        GetColor(255, 255, 255),
        "画像サイズ：",
        imageWidth,
        imageHeight
    );



    // 横5コマ、縦4段 画像を割ることが書かれていますここをいじると画像の位置を返る
    const int FRAME_COUNT = 5;
    const int DIRECTION_COUNT = 4;

    // プレイヤーの座標
    int playerX = 7 * TILE_SIZE + TILE_SIZE / 2;
    int playerY = 5 * TILE_SIZE + TILE_SIZE / 2;

    // 方向：0=正面、1=左、2=右、3=後ろ
    int direction = 0;

    // カメラの座標
    int cameraX = -1;
    int cameraY = -1;

    // アニメーション用
    int animationFrame = 0;
    int animationCounter = 0;
    //各方面の画像の切り取り
    //画像サイズ
    int rowTop[5] = { 0, 286, 542, 796, 1057 };


    // ゲームループ
    while (ProcessMessage() == 0)
    {
        int nexetX = playerX;
        int nametY = playerY;

        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }

        ClearDrawScreen();

        // 移動しているかどうか
        bool isMoving = false;

        // 上へ移動（後ろ向き）
        if (CheckHitKey(KEY_INPUT_W))
        {
            playerY -= 5;
            direction = 3;
            isMoving = true;
        }

        // 下へ移動（正面向き）
        if (CheckHitKey(KEY_INPUT_S))
        {
            playerY += 5;
            direction = 0;
            isMoving = true;
        }

        // 左へ移動
        if (CheckHitKey(KEY_INPUT_A))
        {
            playerX -= 5;
            direction = 1;
            isMoving = true;
        }

        // 右へ移動
        if (CheckHitKey(KEY_INPUT_D))
        {
            playerX += 5;
            direction = 2;
            isMoving = true;
        }




        // 歩くアニメーション
        if (isMoving)
        {
            animationCounter++;

            if (animationCounter >= 8)
            {
                animationCounter = 0;
                animationFrame++;

                if (animationFrame >= FRAME_COUNT)
                {
                    animationFrame = 0;
                }
            }
        }
        else
        {
            // 止まったら最初のコマに戻す
            animationFrame = 0;
            animationCounter = 0;
        }

        // カメラをプレイヤーに合わせる
        cameraX = playerX - SCREEN_WIDTH / 2;
        cameraY = playerY - SCREEN_HEIGHT / 2 - 80;
        //
        map.DrawMap(cameraX, cameraY);
        // 表示する画像のコマを計算
        int srcX = animationFrame * imageWidth / FRAME_COUNT;

        // 横方向の切り取り
        int srcRight =
            (animationFrame + 1) * imageWidth / FRAME_COUNT;

        // 縦方向の切り取り
        int srcY = rowTop[direction];
        int srcBottom = rowTop[direction + 1];

        int frameWidth = srcRight - srcX;
        int frameHeight = srcBottom - srcY;



        // プレイヤーの描画位置
        int drawX = playerX - cameraX - frameWidth / 2;
        int drawY = playerY - cameraY - frameHeight;

        // プレイヤー画像を描画する
        DrawRectGraph(
            drawX,
            drawY,
            srcX,
            srcY,
            frameWidth,
            frameHeight,
            playerImage,
            TRUE
        );



        // 画面を更新する
        ScreenFlip();
    }

    // 画像を解放する
    DeleteGraph(playerImage);

    // DxLibを終了する
    DxLib_End();

    return 0;
}