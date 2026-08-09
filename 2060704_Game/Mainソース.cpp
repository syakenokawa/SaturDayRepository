#include"DxLib.h"
#include"motoClass.cpp"

int playerX = 300;
int playerY = 200;

int playe,png;

void playerMove()
{
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		playerX -= 5;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		playerX += 5;
	}

	if (CheckHitKey(KEY_INPUT_UP))
	{
		playerY -= 5;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		playerY += 5;
	}

}

void PlayerDraw()
{
	DrawGraph(	playerX,playerY,playerImg,TRUE);
	

}



