
#include "Obstacle.h"

namespace dasher
{
   void Obstacle::makeContinuous(int wWidth)
   {
      if (pos.x + rect.width <= 0)
      {
         pos.x = wWidth;
      }
   }

   void Obstacle::updateAnimation()
   {
      if (runningTime >= updateTime)
      {
         runningTime = 0.0;
         rect.x = frame * rect.width;
         frame ++;
         if (frame > (spriteTotal - 1))
         {
            frame = 0;
         }
      }
   }
   
   void Obstacle::updateObstacle(int wWidth, const float dt)
   {
      // Make continuous
      makeContinuous(wWidth);

      // Update obstacle position
      pos.x += velocity*dt;

      // Update animation
      runningTime += dt;
      updateAnimation();

   }
} // namespace dasher
