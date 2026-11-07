#pragma once
#include "Conflg.h"
class Collision
{
private:
	int x;
	int y;
	int width;
	int height;
public:
	void SetRect(int x, int y, int width, int height);

	void SetPosition(int x, int y);
	bool IsHit(const Collision& other)const;
	void FixPosition(const Collision& block, unsigned char blockInfo);

	int GetX() const;
	int GetY() const;
	int Getwidth()const;
	int GetHeight()const;
	int GetBottom() const;

};









