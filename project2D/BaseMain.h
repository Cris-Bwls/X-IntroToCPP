#pragma once

#include "EnumActor.h"
#include "StructResolution.h"

#include "Input.h"
#include "Font.h"

class Application2D;
class CameraOperator;
class Textures;
class UIElement;
class Actor;
class Player;

class BaseMain
{
public:
	BaseMain(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCapOp, Resolution* pResMod, Textures* pTextures);
	virtual ~BaseMain();

	virtual void Update(float deltaTime);
	virtual void Draw();

	virtual void UpdateUI(float deltaTime) = 0;

protected:
	Application2D*	 m_pApp2D;
	CameraOperator*  m_pCamOp;
	Resolution*		 m_pResMod;
	UIElement**		 m_apUIElement;
	Actor***		 m_apActor;
	Player*			 m_pPlayer = nullptr;

	int m_nUIElements = 1;

	int m_nActors[EACTOR_TOTAL];
};
