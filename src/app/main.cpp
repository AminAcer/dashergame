#include <iostream>

#include "raylib.h"
#include "Texture.h"

int main()
{
   // Window dimensions
   const int windowWidth{1920};
   const int windowHeight{1080};
   InitWindow(windowWidth, windowHeight, "Dasher");
   ToggleFullscreen();
   SetWindowMonitor(0);

   // Physics
   const int jumpVelocity{-600};
   int gravity{1000};
   bool isInAir{false};

   // ----- Textures PLAYER -----
   dasher::Texture player("/home/vamin/Documents/dashergame/textures/scarfy.png");
   player.spriteTotal = 6;
   player.rect = {0,
                  0, 
                  static_cast<float>(player.object.width/player.spriteTotal), 
                  static_cast<float>(player.object.height)};
   player.pos = {windowWidth/2 - player.rect.width/2,  windowHeight - player.rect.height};
   player.updateTime = 1.0 / 12.0;
   player.velocity = 0;

   // ----- First Obstacle ----
   dasher::Texture obstacle("/home/vamin/Documents/dashergame/textures/12_nebula_spritesheet.png");
   obstacle.spriteTotal = 8;
   obstacle.rect = {0, 
                    0, 
                    static_cast<float>(obstacle.object.width / obstacle.spriteTotal), 
                    static_cast<float>(obstacle.object.height / obstacle.spriteTotal)};
   obstacle.pos = {windowWidth, windowHeight - obstacle.rect.height};
   obstacle.updateTime = 1.0 / 16.0;
   obstacle.velocity = -600;

   // ----- Second Obstacle ----
   dasher::Texture obstacle2("/home/vamin/Documents/dashergame/textures/12_nebula_spritesheet.png");
   obstacle2.spriteTotal = 8;
   obstacle2.rect = {0, 
                    0, 
                    static_cast<float>(obstacle2.object.width / obstacle2.spriteTotal), 
                    static_cast<float>(obstacle2.object.height / obstacle2.spriteTotal)};
   obstacle2.pos = {windowWidth, windowHeight - obstacle2.rect.height};
   obstacle2.updateTime = 1.0 / 16.0;
   obstacle2.velocity = -600;

   // FPS
   const int fps = 140;
   SetTargetFPS(fps);

   while(!WindowShouldClose())
   {
      BeginDrawing();
      ClearBackground(WHITE);

      // Time since last frame (delta time)
      const float dt = GetFrameTime();

      if (player.pos.y >= windowHeight - player.rect.height)
      {
         isInAir = false;
         player.velocity = 0;
      }
      else
      {
         isInAir = true;
         player.velocity += gravity* dt;
      }
  
      if (IsKeyPressed(KEY_SPACE) && !isInAir)
      {
         player.velocity += jumpVelocity;
      }

      if (obstacle.pos.x + obstacle.rect.width <= 0)
      {
         obstacle.pos.x = windowWidth;
      }

      // Update player position
      player.pos.y += player.velocity * dt;

      // Update obstacle postion
      obstacle.pos.x += obstacle.velocity * dt;      
      obstacle2.pos.x += obstacle2.velocity * dt;

      // Update running time
      player.runningTime += dt;

      // Update animation if loop has ran long enough
      if (player.runningTime >= player.updateTime)
      {
         player.runningTime = 0.0;


         if (!isInAir)
         {
            // Update player animation if on the ground
            player.rect.x = player.frame * player.rect.width;
            player.frame ++;
            if (player.frame > player.spriteTotal - 1)
            {
               player.frame = 0;
            }
         }      
      }

      obstacle.runningTime += dt;
      if (obstacle.runningTime >= obstacle.updateTime)
      {
         obstacle.runningTime = 0.0;
         obstacle.rect.x = obstacle.frame * obstacle.rect.width;
         obstacle.frame ++;
         if (obstacle.frame > 7)
         {
            obstacle.frame = 0;
         }
      }

      obstacle.runningTime += dt;
      if (obstacle.runningTime >= obstacle.updateTime)
      {
         obstacle.runningTime = 0.0;
         obstacle2.rect.x = obstacle2.frame * obstacle2.rect.width;
         obstacle2.frame ++;
         if (obstacle2.frame > 7)
         {
            obstacle2.frame = 0;
         }
      }

      // Draw obstacle
      DrawTextureRec(obstacle.object, obstacle.rect, obstacle.pos, WHITE);

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

