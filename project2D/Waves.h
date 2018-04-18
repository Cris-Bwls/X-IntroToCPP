#pragma once
#include "Environ.h"

class Waves :
	public Environ
{
public:
	Waves(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Pos* pReferencePos);
	~Waves();

	void Draw();
};

