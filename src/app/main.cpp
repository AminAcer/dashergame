#include <iostream>
#include "Player.h"
#include "Obstacle.h"

int main()
{
   // Window dimensions
   const int windowWidth{1920};
   const int windowHeight{1080};
   InitWindow(windowWidth, windowHeight, "Dasher");
   ToggleFullscreen();
   SetWindowMonitor(0);
  
   // Background
   Texture2D background = LoadTexture("/home/vamin/Documents/dashergame/textures/far-buildings.png");
   float bgx{};
   Texture2D midground = LoadTexture("/home/vamin/Documents/dashergame/textures/back-buildings.png");
   float mgx{};
   Texture2D foreground = LoadTexture("/home/vamin/Documents/dashergame/textures/foreground.png");
   float fgx{};

   // ----- Textures PLAYER -----
   dasher::Player player("/home/vamin/Documents/dashergame/textures/scarfy.png");
   player.spriteTotal = 6;
   player.rect = {0,
                  0, 
                  static_cast<float>(player.object.width/player.spriteTotal), 
                  static_cast<float>(player.object.height)};
   player.pos = {windowWidth/2 - player.rect.width/2,  windowHeight - player.rect.height};
   player.updateTime = 1.0 / 12.0;
   player.velocity = 0;
   player.jumpVelocity = -600;

   // ----- First Obstacle ----
   dasher::Obstacle obstacle("/home/vamin/Documents/dashergame/textures/12_nebula_spritesheet.png");
   obstacle.spriteTotal = 8;
   obstacle.rect = {0, 
                    0, 
                    static_cast<float>(obstacle.object.width / obstacle.spriteTotal), 
                    static_cast<float>(obstacle.object.height / obstacle.spriteTotal)};
   obstacle.pos = {windowWidth, windowHeight - obstacle.rect.height};
   obstacle.updateTime = 1.0 / 16.0;
   obstacle.velocity = -600;

   // ----- Second Obstacle ----
   dasher::Obstacle obstacle2("/home/vamin/Documents/dashergame/textures/12_nebula_spritesheet.png");
   obstacle2.spriteTotal = 8;
   obstacle2.rect = {0, 
                     0, 
                     static_cast<float>(obstacle2.object.width / obstacle2.spriteTotal), 
                     static_cast<float>(obstacle2.object.height / obstacle2.spriteTotal)};
   obstacle2.pos = {windowWidth, windowHeight - obstacle2.rect.height};
   obstacle2.updateTime = 1.0 / 16.0;
   obstacle2.velocity = -800;

   // FPS
   const int fps = 140;
   SetTargetFPS(fps);

   while(!WindowShouldClose())
   {
      BeginDrawing();
      ClearBackground(WHITE);

      // Time since last frame (delta time)
      const float dt = GetFrameTime();
      
      // bg1
      float bgscale = 5.65;
      bgx -= 50 * dt;
      if (bgx <= -background.width*bgscale)
      {
         bgx = 0.0;
      }
      Vector2 bg1Pos{bgx, 0.0};
      DrawTextureEx(background, bg1Pos, 0.0, bgscale, WHITE);
      Vector2 bg2Pos{bgx + background.width * bgscale, 0.0};
      DrawTextureEx(background, bg2Pos, 0.0, bgscale, WHITE);
      Vector2 bg3Pos{bgx + 2*background.width * bgscale, 0.0};
      DrawTextureEx(background, bg3Pos, 0.0, bgscale, WHITE);
      
      float mgscale = 5.65;
      mgx -= 80 * dt; 
      if (mgx <= -midground.width*mgscale)
      {
         mgx = 0.0;
      }
      Vector2 mg1Pos{mgx, 0.0};
      DrawTextureEx(midground, mg1Pos, 0.0, mgscale, WHITE);
      Vector2 mg2Pos{mgx + midground.width * mgscale, 0.0};
      DrawTextureEx(midground, mg2Pos, 0.0, mgscale, WHITE);
      Vector2 mg3Pos{mgx + 2*midground.width * mgscale, 0.0};
      DrawTextureEx(midground, mg3Pos, 0.0, mgscale, WHITE);
      
      float fgscale = 4.0;
      fgx -= 110 * dt; 
      if (fgx <= -foreground.width*fgscale)
      {
         fgx = 0.0;
      }
      Vector2 fg1Pos{fgx, 340};
      DrawTextureEx(foreground, fg1Pos, 0.0, fgscale, WHITE);
      Vector2 fg2Pos{fgx + foreground.width * fgscale, 340};
      DrawTextureEx(foreground, fg2Pos, 0.0, fgscale, WHITE);
      Vector2 fg3Pos{fgx + 2*foreground.width * fgscale, 340};
      DrawTextureEx(foreground, fg3Pos, 0.0, fgscale, WHITE);
      
      // Update textures
      player.updatePlayer(windowHeight, dt);
      obstacle.updateObstacle(windowWidth, dt);
      obstacle2.updateObstacle(windowWidth, dt);

      // Draw obstacle
      DrawTextureRec(obstacle.object, obstacle.rect, obstacle.pos, WHITE);

      // Draw obstacle2
      DrawTextureRec(obstacle2.object, obstacle2.rect, obstacle2.pos, WHITE);

      // Draw player
      DrawTextureRec(player.object, player.rect, player.pos, WHITE);

      EndDrawing();
   }

   UnloadTexture(player.object);
   UnloadTexture(obstacle.object);
   UnloadTexture(obstacle2.object);

   CloseWindow();

   return 0;
}

