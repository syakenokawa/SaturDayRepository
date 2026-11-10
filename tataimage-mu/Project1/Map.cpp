#include "Map.h"
#include"DxLib.h"
//マップ初期化
void  Map::Initialize()
{
    //ゲームマップ画像設定
	 mapImage = LoadGraph("ge-mu/dungeon.png");
    //調節
    DrawFormatString(
    10,60,
    GetColor(255,255,255),
    "mapImage= %d",
        mapImage
    );



	// マップを上から下へ調べる
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		// 横方向のマスを調べる
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			//最初は全通路
			mapData[y][x] = 0;
		}
		

	}
	//壁追加上下
    for (int x = 0;x < MAP_WIDTH;x++)
    {
        mapData[0][x] = 1;
        mapData[MAP_HEIGHT - 1][x] = 1;

    }
    //壁追加左右
    for(int y=0;y<MAP_HEIGHT;y++)
    {
        mapData[y][0] = 1;
        mapData[y][MAP_WIDTH - 1] = -1;
    
    }

	//宝箱を配置
	mapData[39][2] = 2;
	//スタート時点は通路
	mapData[0][2] = 0;
}
void Map::DrawMap(int cameraX, int cameraY)
{
    // ダンジョン画像をマップ全体に表示
    if (mapImage != -1)
    {
        DrawExtendGraph(
            -cameraX,
            -cameraY,
            MAP_WIDTH * TILE_SIZE - cameraX,
            MAP_HEIGHT * TILE_SIZE - cameraY,
            mapImage,
            TRUE
        );
    }

    // 宝箱を描画
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {


            //宝箱
            if (mapData[y][x] == 2)
            {
                int drawX = x * TILE_SIZE - cameraX;
                int drawY = y * TILE_SIZE - cameraY;

                //壁
                if (mapData[y][x] == 1)
                {
                    DrawBox(
                        drawX,
                        drawY,
                        drawX + TILE_SIZE,
                        drawY+TILE_SIZE,
                        GetColor(100,100,100),
                        TRUE
                    );



                }


                DrawString(
                    drawX + 5,
                    drawY + 5,
                    "TREASURE",
                    GetColor(255, 255, 0)
                );
            }
        }
    }
}
//マップ情報取得
int Map::GetMapData(int x, int y)
{
	if (x < 0 || x >= MAP_WIDTH || y<0 || y>=MAP_HEIGHT)
	{
		return 1;
	}

	return mapData[y][x];
}