
#include "Player.h"

namespace dasher
{
   void Player::updateIsInAir(int wHeight, const float dt)
   {
      if (pos.y >= wHeight - rect.height)
      {
         isInAir = false;
         velocity = 0;
      }
      else
      {
         isInAir = true;
         velocity += gravity*dt;
      }
   }

   void Player::jump(const float dt)
   {
      if (::IsKeyPressed(KEY_SPACE) && !isInAir)
      {
         velocity += jumpVelocity;
      }
   }

   void Player::updateAnimation()
   {
      if (runningTime >= updateTime)
      {
         runningTime = 0.0;

         if (!isInAir)
         {
            // Update player animation if on the ground
            rect.x = frame * rect.width;
            frame ++;
            if (frame > (spriteTotal = 1))
            {
               frame = 0;
            }
         }
      }
   }
   
   void Player::updatePlayer(int wHeight, const float dt)
   {
      // Update isInAir
      updateIsInAir(wHeight, dt);
      
      // Check if jump
      jump(dt);

      // Update animation
      updateAnimation();
   }
} // namespace dasher
