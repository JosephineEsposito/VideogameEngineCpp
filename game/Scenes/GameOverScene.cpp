#include "GameOverScene.h"
#include "Engine/ENGINE.h"
#include "Engine/Manager/InputManager.h"
#include "Engine/Manager/SceneManager.h"
#include "Engine/Manager/GameManager.h"
#include "utils/Utilities.h"
#include "utils/Vec2.h"


GameOverScene::GameOverScene() : Scene(SceneState::GAMEOVER)
{
  ENGINE::Log("GameOver", "Constructor", "Constructor called.");

  m_cTitle = "";
  m_cSubtitle = "";
  m_cScore = "";

  m_oBackground = Color();
  m_oTextColor = Color();

  m_eState = SceneState::GAMEOVER;
}

void GameOverScene::Init()
{
  ENGINE::Log("GameOver", "Init", "Initializing the object.");

  // we set the window's backgroudn color
  m_oBackground.SetColor(0x73, 0x1f, 0x08);
  ENGINE::GetInstance().SetBackgroundColor(m_oBackground);

  // we set the color of the text
  m_oTextColor.SetColor(0xe0, 0xdc, 0xc8);

  // setting the texts
  m_cTitle = "THE END";
  m_cSubtitle = "UHOH YOU DIED? HIGH SCORE IS:";
}

void GameOverScene::Update()
{
  // we check if the space key has been pressed
  if (InputManager::GetInstance().IsKeyDown(TK_SPACE))
  {
    ENGINE::Log("GameOver", "Update", "Pressed Space - Switching scene.");

    // call to game/save manager to chack and save the score

    // we change back to the main menu scene
    SceneManager::GetInstance().ChangeScene(SceneState::MENU);
  }
}

void GameOverScene::Draw()
{
  // we get the instance of the engine
  ENGINE& engine = ENGINE::GetInstance();

  // we draw the title
  Vec2* titlePos = new Vec2(360, 240);
  engine.Print(utils::toString(m_cTitle), titlePos, &m_oTextColor);

  // we draw the subtitle
  Vec2* subtitlePos = new Vec2(314, 260);
  engine.Print(utils::toString(m_cSubtitle), subtitlePos, &m_oTextColor);

  // we draw the score
  Vec2* scorePos = new Vec2(345, 280);
  engine.Print(utils::toString(utils::toString(GameManager::GetInstance().GetHighScore())), scorePos, &m_oTextColor);

  // deleting the vectors as they are not needed
  delete titlePos;
  delete subtitlePos;
  delete scorePos;
}

void GameOverScene::Unload()
{
  // we unload the scene
  ENGINE::Log("GameOver", "Unload", "Unloading the object.");
}