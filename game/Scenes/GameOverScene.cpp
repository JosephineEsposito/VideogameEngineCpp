#include "GameOverScene.h"

#include "Engine/ENGINE.h"

#include "Engine/Manager/InputManager.h"
#include "Engine/Manager/SceneManager.h"

#include "utils/Utilities.h"
#include "utils/Vec2.h"


GameOverScene::GameOverScene() : Scene(SceneState::GAMEOVER)
{
  ENGINE::Log("GameOver", "Constructor", "Constructor called.");

  m_cTitle = "";
  m_cSubtitle = "";
  m_cScore = "";

  background = Color();
  textColor = Color();

  m_eState = SceneState::GAMEOVER;
}

void GameOverScene::Init()
{
  ENGINE::Log("GameOver", "Init", "Initializing the object.");

  background.setColor(0x73, 0x1f, 0x08);
  ENGINE::GetInstance().setBackgroundColor(background);

  // we set the color of the text
  textColor.setColor(0xe0, 0xdc, 0xc8);

  m_cTitle = "THE END";

  m_cSubtitle = "CONGRATS! YOU SURVIVED!";

  m_cScore = "FOR X SECONDS";
}

void GameOverScene::Update()
{
  if (InputManager::GetInstance().IsKeyDown(TK_SPACE))
  {
    ENGINE::Log("GameOver", "Update", "Pressed Space - Switching scene.");

    // call to game/save manager to chack and save the score
    SceneManager::GetInstance().ChangeScene(SceneState::MENU);
  }
}

void GameOverScene::Draw()
{
  ENGINE& engine = ENGINE::GetInstance();

  Vec2* titlePos = new Vec2(360, 240);
  engine.Print(utils::toString(m_cTitle), titlePos, &textColor);

  Vec2* subtitlePos = new Vec2(314, 260);
  engine.Print(utils::toString(m_cSubtitle), subtitlePos, &textColor);

  Vec2* scorePos = new Vec2(345, 280);
  engine.Print(utils::toString(m_cScore), scorePos, &textColor);

  delete titlePos;
  delete subtitlePos;
  delete scorePos;
}

void GameOverScene::Unload()
{
  ENGINE::Log("GameOver", "Unload", "Unloading the object.");
}