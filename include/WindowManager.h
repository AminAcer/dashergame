
#pragma once

#include "raylib.h"
#include <iostream>

#define MONITOR 0

namespace dasher
{
   class WindowManager
   {
   public:
      /// @brief Constructor
      /// @param windowWidth Window width
      /// @param windowHeight Window Height
      /// @param windowName Window name
      WindowManager(int windowWidth, int windowHeight, std::string windowName)
      :  width(windowWidth),
         height(windowHeight),
         winName(windowName)
      {
         ::InitWindow(width, height, winName.c_str());
         ::ToggleFullscreen();
         ::SetWindowMonitor(MONITOR);
      }
      
      /// @brief Delete default constructor
      WindowManager() = delete;

      /// @brief Delete copy constructor
      WindowManager(const WindowManager&) = delete;

      /// @brief Delete move constructor
      WindowManager(WindowManager&&) = delete;

      /// @brief Window width
      int width{};

      /// @brief Window height
      int height{};

      /// @brief Window name
      std::string winName{};
   };

} // namespace dasher
