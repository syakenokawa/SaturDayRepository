#pragma once
#include<vector>
#include<string>
using namespace std;

class Map
{
private:
	vector<vector<int>>mapData;
	vector<vector<int>>hitData;
	int chiplmage[64];


	int mapWindth;
	int mapHeight;

	static constexpr int ChIP_SIZE = 64;

	bool LoadCSV(const char* fileName, vector<vector<int>> &data);
public:
	Map();
	bool Init();
	void Draw(float cameraX, float cameraY);
	bool IsSolid(int tilX, int tileY);


};

