
#pragma once

#include <iostream>
#include "raylib.h"

namespace dasher
{
   class Texture
   {
   public:

      /// @brief Constructor
      Texture(std::string textureSource)
      : object(::LoadTexture(textureSource.c_str()))
      {
      }
      
      /// @brief Default Destructor
      ~Texture() = default;
      
      /// @brief Delete default constructor
      Texture() = delete;
      
      /// @brief Delete copy constructor
      Texture(const Texture&) = delete;

      /// @brief Delete move constructor
      Texture(Texture&&) = delete;

      /// @brief Creating the texture
      Texture2D object{};

      /// #brief Instance of the sprite
      Rectangle rect{};
      
      /// @brief Position of sprite
      Vector2 pos{};
      
      /// @brief Multiplier for sprite selection
      int frame{};
      
      /// @brief Total number of sprites
      int spriteTotal{};

      /// @brief How often the sprite should change
      float updateTime{};

      /// @brief How long the sprite has been used for
      float runningTime{};

      /// @brief How fast the texture is moving
      int velocity{};
   
   protected:

   private:
   };

} // namespace dasher
