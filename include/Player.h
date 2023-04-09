
#pragma once

#include "Texture.h"

namespace dasher
{
   class Player: public Texture
   {
   public:

      /// @brief Default constructor
      Player(std::string textureSource)
      : Texture(textureSource)
      {
      }
      
      /// @brief Default Destructor
      ~Player() final{};
     
      /// @brief Delete default constructor
      Player() = default;

      /// @brief Delete copy constructor
      Player(const Player&) = delete;

      /// @brief Delete move constructor
      Player(Player&&) = delete;

      /// @brief Check if player is mid jump
      /// @param wHeight: Window Height, dt: Delta Time
      void updateIsInAir(int wHeight, const float dt);

      /// @brief Player jump functionality
      /// @param dt: Delta Time
      void jump(const float dt);

      /// @brief Updates player animation
      void updateAnimation() override;
 
      /// @brief Updates player
      /// @param wHeight: Window Height, dt: Delta Time
      void updatePlayer(int wHeight, const float dt);

      /// @brief States whether player is in the air
      bool isInAir{};

      /// @brief Jump velocity
      int jumpVelocity{};

      /// @brief Earth's gravity 
      const int gravity{1000};

   };
} // namespace dasher
