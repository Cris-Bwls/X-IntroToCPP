#include "Level01.h"

//Higher
#include "Application2D.h"
#include "GameManager.h"

//Lower
#include "UIElement.h"
#include "Actor.h"
#include "Clouds.h"
#include "Waves.h"
#include "Enemy.h"
#include "Fish.h"
#include "Player.h"

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Level01::Level01(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, GameManager* pGame) : MainLevel(pApp2D, pFont, pCamOp, pResMod, pTextures, pGame)
{
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
Level01::~Level01()
{
}
