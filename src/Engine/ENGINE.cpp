#include "ENGINE.h"

#include <iostream>
#include <stdio.h>

#include "libs/tigr.h"

#include "utils/Color.h"
#include "utils/Vec2.h"

#include "Engine/Manager/TimerManager.h"


#pragma region | Constructor and Destructor Methods

ENGINE::ENGINE()
{
  m_bIsRunning = false;
  m_pScreen = nullptr;

  m_cTitle = "Init";

  m_BackgroundColor = Color();
  
  m_iScreenWidth = 60;
  m_iScreenHeight = 60;
}

ENGINE::~ENGINE()
{
  m_bIsRunning = false;

  delete m_pScreen;
  m_pScreen = nullptr;
}

#pragma endregion


#pragma region | Initialization

bool ENGINE::Init()
{
  m_BackgroundColor.setColor(0xf2, 0xf2, 0xe9);

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
  tigrClear(m_pScreen, m_BackgroundColor.getColor());
}


#pragma region | Main Loop
void ENGINE::BeginFrame()
{
  TimerManager::GetInstance().StartFrame();

  Clear();

  //@review -> gestisci input qui
}

void ENGINE::EndFrame()
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


void ENGINE::Print(const char* _text, Color* _color)
{
  tigrPrint(m_pScreen, tfont, 0, 0, _color->getColor(), _text);
}

void ENGINE::Print(std::string _text, Vec2* _pos, Color* _color)
{
  tigrPrint(m_pScreen, tfont, _pos->x, _pos->y, _color->getColor(), _text.c_str());
}

#pragma endregion


#pragma region | Getters

Tigr* ENGINE::getScreen() const
{
  return m_pScreen;
}

int ENGINE::GetWidth() const
{
  return m_iScreenWidth;
}

int ENGINE::GetHeight() const
{
  return m_iScreenHeight;
}

ENGINE& ENGINE::GetInstance()
{
  static ENGINE instance;
  return instance;
}
#pragma endregion


#pragma region | Setters

void ENGINE::setWindowSize(int& _width, int& _height)
{
  m_iScreenWidth = _width;
  m_iScreenHeight = _height;
}

void ENGINE::setWindowTitle(std::string& _title)
{
  m_cTitle = _title.c_str();
}

void ENGINE::setBackgroundColor(Color& _color)
{
  m_BackgroundColor = _color;
}
#pragma endregion

//EOF