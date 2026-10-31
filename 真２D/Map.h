#pragma once

#include "Collision.h"

class Map
{
private:

    bool LoadMap(const char* filePath, std::vector<std::vector<int>>& mapData);

    void DrawLayer(const std::vector<std::vector<int>>& mapData) const;

	bool IsValidMapPosition(int mapX, int mapY) const;

	int chipImages[Config::MAP_CHIP_IMAGE_COUNT];
	//マップの内容
	std::vector<std::vector<int>> backMap;
	std::vector<std::vector<int>> baseMap;
	std::vector<std::vector<int>> nearMap;

	int mapXNum;
	int mapYNum;
	bool isInitialized;





public:

    void Init();

    void Draw();

    void Finalize();

    bool CheckCollision(Collision& collision);
};


