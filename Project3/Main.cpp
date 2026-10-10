#include "Main.h"
#include"Dxlib.h"

#include<fstream>
#include<sstream>
#include<string>

Map::Map()
{
	mapWidth = 0;
	mapHeight = 0;
	for (int i = 0; i < 64; i++)
	{
		chipImage[i] = -1;
	}
}
bool Map::LoadCSV(const char* fileName, std::vector<int >> &data)
{
	std::ifstream(fileName)






}








