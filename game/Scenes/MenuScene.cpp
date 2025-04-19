#include "MenuScene.h"

#include "Engine/ENGINE.h"

#include "utils/Utilities.h"
#include "utils/Vec2.h"

#include <iostream>

MenuScene::MenuScene() : Scene(SceneState::MENU)
{
  m_sTitle = "";
  m_sText = "";
  background = new Color();
  textColor = new Color();
  // we set the scene state
  m_eState = SceneState::MENU;
  std::cout << "[MenuScene]\tConstructor, m_eState: " << (int)m_eState << "\n";
}

void MenuScene::Init()
{
  // we load the assets here

  // we set the color of the background
  background->setColor(0x69, 0x85, 0x45);
  ENGINE::GetInstance().setBackgroundColor(*background);

  // we set the color of the text
  textColor->setColor(0xe0, 0xdc, 0xc8);

  // we set the title content
  m_sTitle = "DEMO GAME";

  // we set the subtitle content
  m_sText = "PRESS SPACE TO CONTINUE";
}

void MenuScene::Update()
{
  // we update the scene logic

  // we read the input
}

void MenuScene::Draw()
{
  // we render the scene
  ENGINE& engine = ENGINE::GetInstance();

  // we draw the text onto the screen
  Vec2* titlePos = new Vec2(360, 200);
  engine.Print(utils::toString(m_sTitle), titlePos, textColor);

  // we draw the subtitle onto the screen
  Vec2* subtitlePos = new Vec2(314, 220);
  engine.Print(utils::toString(m_sText), subtitlePos, textColor);

  delete titlePos;
  delete subtitlePos;
}

void MenuScene::Unload()
{
  // we clean the memory
  puts("[MenuScene]\tUnloading the scene.");
  delete background;
  delete textColor;
}