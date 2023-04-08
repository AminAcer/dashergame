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
      
      // Update textures
      player.updatePlayer(windowHeight, dt);
      obstacle.updateObstacle(windowWidth, dt);
      obstacle2.updateObstacle(windowWidth, dt);

      // Draw obstacle
      DrawTextureRec(obstacle.object, obstacle.rect, obstacle.pos, BLUE);

      // Draw obstacle2
      DrawTextureRec(obstacle2.object, obstacle2.rect, obstacle2.pos, RED);

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

