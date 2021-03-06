#include "Application2D.h"

// Higher
#include "Input.h"

// Lower
#include "GameManager.h"

// Defines
#define RES_X	 1280	/*1920*/	/*640*/		// CB:DEBUG
#define RES_Y	 720	/*1080*/	/*480*/		// Until I allow the player to choose the resolution
#define RES_ISFULLSCREEN false	//

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Application2D::Application2D() 
{	
	m_pRes = new Resolution;
	SetRes();
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
Application2D::~Application2D() 
{
}

//----------------------------------------------------------
// startup
//		is called constructor
//----------------------------------------------------------
bool Application2D::startup() 
{
	glDisable(GL_CULL_FACE);

	m_pRenderer2D = new aie::Renderer2D;
	m_pGame = new GameManager(this);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

//----------------------------------------------------------
// shutdown
//		is called destructor
//----------------------------------------------------------
void Application2D::shutdown() 
{
	delete m_pRes;
	delete m_pRenderer2D;
	delete m_pGame;
}

//----------------------------------------------------------
// update
//		Calls all update functions
//----------------------------------------------------------
void Application2D::update(float deltaTime) 
{

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();
	
	m_pGame->Update(input, deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

//----------------------------------------------------------
// draw
//		Calls all draw functions
//----------------------------------------------------------
void Application2D::draw() 
{
	// set background colour
	setBackgroundColour(0, 162, 232, 0.75);

	// wipe the screen to the background colour
	clearScreen();
	
	// set the camera position before we begin rendering
	m_pRenderer2D->setCameraPos(m_cameraX, m_cameraY);

	m_pGame->Draw();

	// begin drawing sprites
	m_pRenderer2D->begin();

	
	// done drawing sprites
	m_pRenderer2D->end();
}

//----------------------------------------------------------
// SetRes
//		Sets Resolution of play window
//----------------------------------------------------------
void Application2D::SetRes()
{
	//CB:DEBUG
	m_pRes->fX = RES_X;
	m_pRes->fY = RES_Y;
	m_pRes->bIsFullscreen = RES_ISFULLSCREEN;
}

//----------------------------------------------------------
// SetCameraPos
//		Sets Camera Position
//
//			fX (float): 
//				sets camera X Pos
//			fY (float): 
//				sets camera Y Pos
//----------------------------------------------------------
void Application2D::SetCameraPos(float fX, float fY)
{
	m_cameraX = fX;
	m_cameraY = fY;
}

//----------------------------------------------------------
// Get Renderer
//		Gets Renderer pointer
//
//			return:
//				Renderer2D pointer
//----------------------------------------------------------
aie::Renderer2D* Application2D::GetRenderer()
{
	return m_pRenderer2D;
}

//----------------------------------------------------------
// GetRes
//		Gets Resolution of play window
//
//			&fX (float):
//				Reference to X pos
//			&fY (float):
//				Reference to Y pos
//			&bFullscreeen (bool):
//				Reference to isFullscreen
//----------------------------------------------------------
void Application2D::GetRes(float &fX, float &fY, bool &bIsFullscreen)
{
	fX = m_pRes->fX;
	fY = m_pRes->fY;
	bIsFullscreen = m_pRes->bIsFullscreen;
}

//----------------------------------------------------------
//	GetCameraPos
//		Gets Camera Position
//
//			&fX (float):
//				Reference to camera X pos
//			&fY (float):
//				Reference to camera Y pos
//----------------------------------------------------------
void Application2D::GetCameraPos(float &fX, float &fY)
{
	fX = m_cameraX;
	fY = m_cameraY;
}

//----------------------------------------------------------
// GetTimer
//		Gets Timer
//
//			&fTimer (float):
//				Reference to timer
//----------------------------------------------------------
void Application2D::GetTimer(float &fTimer)
{
	fTimer = m_timer;
}