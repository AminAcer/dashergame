
#pragma once

#include "Texture.h"

namespace dasher
{
   class Obstacle: public Texture
   {
   public:

      /// @brief Default constructor
      Obstacle(std::string textureSource)
      : Texture(textureSource)
      {
      }

      /// @brief Default destructor
      ~Obstacle() final{};

      /// @brief Delete default constructor
      Obstacle() = delete;

      /// @brief Delete copy constructor
      Obstacle(const Obstacle&) = delete;

      /// @brief Delete move constructor
      Obstacle(Obstacle&&) = delete;
      
      /// @brief Reset obstacle position when off screen
      void makeContinuous(int wWidth);

      /// @brief Updates obstacle animation
      void updateAnimation() override;

      /// @brief Updates obstacle
      void updateObstacle(int wWidth, const float dt);
   
   protected:

   private:

   };
} // namespace dasher
