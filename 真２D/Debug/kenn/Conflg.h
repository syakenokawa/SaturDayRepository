#pragma once

namespace Config
{
	constexpr int MAP_CHIP_SIZE = 64;
	constexpr int MAP_CHIP_IMAGE_COLUMNS = 16;
	constexpr int MAP_CHIP_IMAGE_ROWS = 4;
	constexpr int MAP_CHIP_IMAGE_COUNT = MAP_CHIP_IMAGE_COLUMNS * MAP_CHIP_IMAGE_ROWS;

	constexpr int MAP_DRAW_ORIGIN_X = 0;
	constexpr int MAP_DRAW_ORIGIN_Y = 0;


	constexpr int MAP_EMPTY = 0;

	constexpr char MAP_CHIP_IMAGE_PATH[] = "data/island.png";
	constexpr char MAP_HIT_CSV_PATH[] = "data/island_hit.csv";
	constexpr char MAP_BACK_CSV_PATH[] = "data/island_back.csv";
	constexpr char MAP_BASE_CSV_PATH[] = "data/island_base.csv";
	constexpr char MAP_NEAR_CSV_PATH[] = "data/island_near.csv";


	constexpr unsigned char BLOCK_LEFT = 1 << 0;
	constexpr unsigned char BLOCK_RIGHT = 1 << 1;
	constexpr unsigned char BLOCK_UP = 1 << 2;
	constexpr unsigned char BLOCK_DOWN = 1 << 3;




}


