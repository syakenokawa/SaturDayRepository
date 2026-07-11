#include"Framatinƒwƒbƒ_[.h"


FrameManager::FrameManager()
{

	frameCounter = 0;
}
//
void FrameManager::Update()
{
	frameCounter++;


}

int FrameManager::GetFrameCounter() const
{
	return frameCounter;

}


