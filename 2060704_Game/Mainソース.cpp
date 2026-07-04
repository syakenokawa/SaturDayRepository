#include"DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetGraphMode(800, 600, 32);
	if (DxLib_Init() == -1)return -1;

	int fontColoor = GetColor(255, 100, 0);

	while ()












}













