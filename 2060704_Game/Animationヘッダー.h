#pragma once
class Aimation
{
private:

	int* images;

	int startFrame;
 
	int frameCount;

	int speed;

	int starTime;
public:

	//コンストラクタ

	void Animation();

	void SetImages(int* img);
	void Play(int startFrame, int frameCount, int speed);

	void GetImage(int currentTime);



};




















