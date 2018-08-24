#pragma once
#include "../ESGLib.h"

/*“¹˜H‚Ì—¼‘¤‚É‚ ‚é’Œ‚Ì3Dƒ‚ƒfƒ‹‚ğŠÇ—‚·‚éƒNƒ‰ƒX*/
class Pillar
{
public:
	Pillar();
	~Pillar();
	bool Initialize();
	void Draw();
private:
	MODEL pillar_model[2];
	int MAX_PILLAR_COUNT;
};
