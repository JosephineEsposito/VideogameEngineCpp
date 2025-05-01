#include "MenuScene.h"

#include "Engine/ENGINE.h"

#include "Engine/Manager/InputManager.h"
#include "Engine/Manager/SceneManager.h"

#include "utils/Utilities.h"
#include "utils/Vec2.h"

MenuScene::MenuScene() : Scene(SceneState::MENU)
{
  ENGINE::Log("MenuScene", "Constructor", "Constructor called.");
  m_cTitle = "";
  m_cText = "";
  m_oBackground = Color();
  m_oTextColor = Color();

  // we set the scene state
  m_eState = SceneState::MENU;
}

void MenuScene::Init()
{
  ENGINE::Log("MenuScene", "Init", "Initializing the object.");

  // we set the color of the background
  m_oBackground.SetColor(0x43, 0x52, 0x21);
  ENGINE::GetInstance().SetBackgroundColor(m_oBackground);

  // we set the color of the text
  m_oTextColor.SetColor(0xe0, 0xdc, 0xc8);

  // we set the title content
  m_cTitle = "DEMO GAME";

  // we set the subtitle content
  m_cText = "PRESS SPACE TO CONTINUE";
}

void MenuScene::Update()
{
  // we check if the space key has been pressed
  if (InputManager::GetInstance().IsKeyDown(TK_SPACE))
  {
    ENGINE::Log("MenuScene", "Update", "Pressed Space - Switching scene.");

    // we load the game scene
    SceneManager::GetInstance().ChangeScene(SceneState::PLAYING);
  }
}

void MenuScene::Draw()
{
  // we render the scene
  ENGINE& engine = ENGINE::GetInstance();

  // we draw the text onto the screen
  Vec2* titlePos = new Vec2(360, 240);
  engine.Print(utils::toString(m_cTitle), titlePos, &m_oTextColor);

  // we draw the subtitle onto the screen
  Vec2* subtitlePos = new Vec2(314, 260);
  engine.Print(utils::toString(m_cText), subtitlePos, &m_oTextColor);

  // we delete the vectors
  delete titlePos;
  delete subtitlePos;
}

void MenuScene::Unload()
{
  // we unload the scene
  ENGINE::Log("MenuScene", "Unload", "Unloading the object.");
}