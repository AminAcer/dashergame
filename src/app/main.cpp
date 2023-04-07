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
   player.updateTime = 1.0/12.0;
   player.velocity = 0;

   // ----- Textures Obstacle ----
   Texture2D obstacle = LoadTexture("/home/vamin/Documents/dashergame/textures/12_nebula_spritesheet.png");
   Rectangle obRec{0.0, 0.0, static_cast<float>(obstacle.width / 8), static_cast<float>(obstacle.height / 8)};
   Vector2 obPos{windowWidth, windowHeight - obRec.height};

   Rectangle ob2Rec{0.0, 0.0, static_cast<float>(obstacle.width / 8), static_cast<float>(obstacle.height / 8)};
   Vector2 ob2Pos{windowWidth + 300, windowHeight - ob2Rec.height};

   int obFrame{};
   int ob2Frame{};
   // Amount of time before updateing the animation frame

   const float updateTimeObstacle = 1.0 / 16.0;
   const float updateTimeObstacle2 = 1.0 / 16.0;
   float runningTimeOb{};
   float runningTimeOb2{};

   // Obstacle x velocity (pixels/sec)
   int obVel{-600};

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

      if (obPos.x + obRec.width <= 0)
      {
         obPos.x = windowWidth;
      }

      // Update player position
      player.pos.y += player.velocity * dt;

      // Update obstacle postion
      obPos.x += obVel * dt;      
      ob2Pos.x += obVel * dt;

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

      runningTimeOb += dt;
      if (runningTimeOb >= updateTimeObstacle)
      {
         runningTimeOb = 0.0;
         obRec.x = obFrame * obRec.width;
         obFrame++;
         if (obFrame > 7)
         {
            obFrame = 0;
         }
      }

      runningTimeOb2 += dt;
      if (runningTimeOb2 >= updateTimeObstacle2)
      {
         runningTimeOb2 = 0.0;
         ob2Rec.x = ob2Frame * ob2Rec.width;
         ob2Frame++;
         if (ob2Frame > 7)
         {
            ob2Frame = 0;
         }
      }

      // Draw obstacle
      DrawTextureRec(obstacle, obRec, obPos, WHITE);

      // Draw obstacle2
      DrawTextureRec(obstacle, ob2Rec, ob2Pos, RED);

      // Draw player
      DrawTextureRec(player.object, player.rect, player.pos, WHITE);

      EndDrawing();
   }
   UnloadTexture(player.object);
   UnloadTexture(obstacle);
   CloseWindow();

   return 0;
}

