#include "MenuScene.h"

#include "Engine/ENGINE.h"

#include "Engine/Manager/InputManager.h"
#include "Engine/Manager/SceneManager.h"

#include "utils/Utilities.h"
#include "utils/Vec2.h"

MenuScene::MenuScene() : Scene(SceneState::MENU)
{
  ENGINE::Log("MenuScene", "Constructor", "Constructor called.");
  m_sTitle = "";
  m_sText = "";
  background = Color();
  textColor = Color();
  // we set the scene state
  m_eState = SceneState::MENU;
}

void MenuScene::Init()
{
  ENGINE::Log("MenuScene", "Init", "Initializing the object.");
  // we load the assets here

  // we set the color of the background
  background.setColor(0x43, 0x52, 0x21);
  ENGINE::GetInstance().setBackgroundColor(background);

  // we set the color of the text
  textColor.setColor(0xe0, 0xdc, 0xc8);

  // we set the title content
  m_sTitle = "DEMO GAME";

  // we set the subtitle content
  m_sText = "PRESS SPACE TO CONTINUE";
}

void MenuScene::Update()
{
  // we update the scene logic
  if (InputManager::GetInstance().IsKeyDown(TK_SPACE))
  {
    ENGINE::Log("MenuScene", "Update", "Pressed Space - Switching scene.");

    SceneManager::GetInstance().ChangeScene(SceneState::PLAYING);
  }
}

void MenuScene::Draw()
{
  // we render the scene
  ENGINE& engine = ENGINE::GetInstance();

  // we draw the text onto the screen
  Vec2* titlePos = new Vec2(360, 240);
  engine.Print(utils::toString(m_sTitle), titlePos, &textColor);

  // we draw the subtitle onto the screen
  Vec2* subtitlePos = new Vec2(314, 260);
  engine.Print(utils::toString(m_sText), subtitlePos, &textColor);

  delete titlePos;
  delete subtitlePos;
}

void MenuScene::Unload()
{
  // we clean the memory
  ENGINE::Log("MenuScene", "Unload", "Unloading the object.");
}