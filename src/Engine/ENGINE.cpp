#include "ENGINE.h"

#include <iostream>
#include <stdio.h>

#include "libs/tigr.h"


#pragma region | Constructor and Destructor Methods

ENGINE::ENGINE()
{
  m_bIsRunning = false;
  m_pScreen = nullptr;
  m_fDeltaTime = 0.0f;
  m_cTitle = "Init";
  m_iScreenWidth = 60;
  m_iScreenHeight = 60;
}

ENGINE::~ENGINE()
{
  m_bIsRunning = false;

  m_fDeltaTime = 0.0f;

  delete m_pScreen;
  m_pScreen = nullptr;
}

#pragma endregion


#pragma region | Initialization

bool ENGINE::Init()
{
  // we create a window with TiGR
  m_pScreen = tigrWindow(m_iScreenWidth, m_iScreenHeight, m_cTitle, 0);

  // we check if the window has been created correctly
  if (!m_pScreen)
  {
    return false;
  }

  m_bIsRunning = true;

  return true;
}

bool ENGINE::Quit()
{
  // we close the window
  tigrFree(m_pScreen);

  // we clean the pointer
  m_pScreen = nullptr;

  m_bIsRunning = false;

  return true;
}

#pragma endregion


void ENGINE::Clear()
{
  // clearing the screen
  tigrClear(m_pScreen, tigrRGB(0xf2, 0xf2, 0xe9));
}


#pragma region | Main Loop

bool ENGINE::Input()
{
  //@review -> leggi l'input qui
  return true;
}

void ENGINE::Render()
{
  // we draw on the screen
  tigrClear(m_pScreen, tigrRGB(0xf2, 0xf2, 0xe9));
}

void ENGINE::Update()
{
  // we update the engine here
  tigrUpdate(m_pScreen);
}

#pragma endregion


#pragma region | Check methods

bool ENGINE::IsRunning()
{
  if (tigrClosed(m_pScreen) || tigrKeyDown(m_pScreen, TK_ESCAPE))
  {
    m_bIsRunning = false;
  }

  return m_bIsRunning;
}

#pragma endregion


#pragma region | Logs and Prints

void ENGINE::Log(const char* _text)
{
  puts(_text);
}

void ENGINE::Log(std::string& _text)
{
  puts(_text.c_str());
}


void ENGINE::Print(const char* _text, unsigned char _r, unsigned char _g, unsigned char _b)
{
  tigrPrint(m_pScreen, tfont, 0, 0, tigrRGB(_r, _g, _b), _text);
}

void ENGINE::Print(std::string& _text, int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b)
{
  tigrPrint(m_pScreen, tfont, _x, _y, tigrRGB(_r, _g, _b), _text.c_str());
}

#pragma endregion


#pragma region | Getters

float ENGINE::getDeltaTime() const
{
  return m_fDeltaTime;
}

Tigr* ENGINE::getScreen() const
{
  return m_pScreen;
}

#pragma endregion


#pragma region | Setters

void ENGINE::StartTime()
{
  m_fDeltaTime = tigrTime();
}

void ENGINE::setDeltaTime(float& _time)
{
  m_fDeltaTime = _time;
}

void ENGINE::setWindowSize(int& _width, int& _height)
{
  m_iScreenWidth = _width;
  m_iScreenHeight = _height;
}

void ENGINE::setWindowTitle(std::string& _title)
{
  m_cTitle = _title.c_str();
}

#pragma endregion

//EOF