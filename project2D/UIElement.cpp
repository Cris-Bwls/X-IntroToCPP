#include "UIElement.h"

#include <iostream>
#include "Application2D.h"


//----------------------------------------------------------
// Constructor
//		Constructs UIElement
//
//			pApp2D (Application2D*):
//				Pointer to Application2D
//			eColour (EColour):
//				colour of element
//			pFont (aie::pFont)
//				pointer to Font for text
//			sText (const char*):
//				text on element
//			fWidth (float):
//				Width of element
//			fHeight (float):
//				Height of element
//			fPosX (float):
//				Pos X of element 
//			fPosY (float):
//				Pos Y of element
//			fDepth (float):
//				Depth of element (0-100)
//					lower is closer to screen
//----------------------------------------------------------
UIElement::UIElement(Application2D* pApp2D, EColour eColour, aie::Font* pFont, const char* sText, float fWidth, float fHeight, float fPosX, float fPosY, float fDepth)
{
	m_pApp2D	= pApp2D;
	m_eColour	= eColour;
	m_pFont		= pFont;
	m_sText		= sText;
	m_fWidth	= fWidth;
	m_fHeight	= fHeight;
	m_fPosX		= fPosX;
	m_fPosY		= fPosY;
	m_fDepth	= fDepth;

	m_eColourOriginal	= m_eColour;
	m_fWidthOriginal	= m_fWidth;
	m_fHeightOriginal	= m_fHeight;
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
UIElement::~UIElement()
{
}

//----------------------------------------------------------
// ChangePos
//		Changes Position of UI element, 
//		either by fixed amount or by offset
//			
//			fPosX (float):
//				Pos X of element 
//			fPosY (float):
//				Pos Y of element
//			fOffsetX (float):
//				Offset X of element 
//			fOffsetY (float):
//				Offset Y of element
//----------------------------------------------------------
void UIElement::ChangePos(float fPosX, float fPosY, float fOffsetX, float fOffsetY)
{
	m_fPosX = fPosX + fOffsetX;
	m_fPosY = fPosY + fOffsetY;
}

//----------------------------------------------------------
// Update
//		Checks if mouse is over or has clicked on the element
//		changes elements properties if hovered over
//
//			input (aie::Input*):
//				Pointer to input
//
//			return (bool)
//				-True if mouse clicked on element

//				-False if mouse did not click on element
//----------------------------------------------------------
bool UIElement::Update(aie::Input* input)
{
	int nMouseX, nMouseY;
	input->getMouseXY(&nMouseX, &nMouseY);

	// Checks if Mouse is over element
	if ((nMouseX > m_fPosX - (m_fWidth / 2)) && (nMouseX < m_fPosX + (m_fWidth / 2)))
	{
		if ((nMouseY > m_fPosY - (m_fHeight / 2)) && (nMouseY < m_fPosY + (m_fHeight / 2)))
		{
			m_eColour = ECOLOUR_WHITE;
			m_fWidth = m_fWidthOriginal * 1.1;
			m_fHeight = m_fHeightOriginal * 1.1;
		}
		else
		{
			m_eColour = m_eColourOriginal;
			m_fWidth = m_fWidthOriginal;
			m_fHeight = m_fHeightOriginal;

		}
	}
	else
	{
		m_eColour = m_eColourOriginal;
		m_fWidth = m_fWidthOriginal;
		m_fHeight = m_fHeightOriginal;
	}

	if (input->wasMouseButtonPressed(0))
	{
		if ((nMouseX > m_fPosX - (m_fWidth / 2)) && (nMouseX < m_fPosX + (m_fWidth / 2)))
		{
			if ((nMouseY > m_fPosY - (m_fHeight / 2)) && (nMouseY < m_fPosY + (m_fHeight / 2)))
			{				
				printf("%s pressed\n", m_sText); //CB:DEBUG
				
				return true;
			}
		}
	}
	return false;
}

//----------------------------------------------------------
// Draw
//		Draws the element
//----------------------------------------------------------
void UIElement::Draw()
{
	// Start of Draw
	m_pApp2D->GetRenderer()->begin();

	switch (m_eColour)
	{
	case ECOLOUR_RED:
		m_pApp2D->GetRenderer()->setRenderColour(1, 0, 0, 0.75);
		break;
	case ECOLOUR_GREEN:
		m_pApp2D->GetRenderer()->setRenderColour(0, 1, 0, 0.75);
		break;
	case ECOLOUR_WHITE:
		m_pApp2D->GetRenderer()->setRenderColour(0, 0, 0, 0.75);
		break;
	case ECOLOUR_SKY_BLUE:
		m_pApp2D->GetRenderer()->setRenderColour(0, 162, 232, 0.75);
		break;
	default:
		//ERROR
		printf("ERROR\n");
		printf("UIElement::Draw, Invalid colour\n");
	}

	m_pApp2D->GetRenderer()->drawBox(m_fPosX, m_fPosY, m_fWidth, m_fHeight, 0.0f, m_fDepth + 1);

	m_pApp2D->GetRenderer()->setRenderColour(1, 1, 1, 1);
	m_pApp2D->GetRenderer()->drawText(m_pFont, m_sText, m_fPosX - (m_fWidth / 2), m_fPosY - (m_fHeight / 2), m_fDepth);

	// End of draw
	m_pApp2D->GetRenderer()->end();
}