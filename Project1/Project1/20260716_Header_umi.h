#ifndef HEADER_H
#define HEADER_H
#include<tchar.h>
#include "DxLib.h"

enum Scene
{
	GROW1,
	CLEAR
};

extern int scene;
extern int clickCount;

extern int taneImg;
extern int meImg;
extern int hanaImg;

void Grow();
void Clear();

#endif