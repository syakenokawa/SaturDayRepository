#pragma once
//幅のマップ
const int MAP_WIDTH = 15;

const int MAP_HEIGHT = 40;
const int TILE_SIZE = 80;

class Map
{
public:
    int mapData[MAP_HEIGHT][MAP_WIDTH];

    int mapImage;

    void Initialize();
    void DrawMap(int cameraX, int cameraY);

    // マップ情報を取得
    int GetMapData(int x, int y);
};
