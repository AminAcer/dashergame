# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vamin/Documents/dashergame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vamin/Documents/dashergame/build

# Include any dependencies generated for this target.
include CMakeFiles/launch.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/launch.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/launch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/launch.dir/flags.make

CMakeFiles/launch.dir/main.cpp.o: CMakeFiles/launch.dir/flags.make
CMakeFiles/launch.dir/main.cpp.o: /home/vamin/Documents/dashergame/main.cpp
CMakeFiles/launch.dir/main.cpp.o: CMakeFiles/launch.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vamin/Documents/dashergame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/launch.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/launch.dir/main.cpp.o -MF CMakeFiles/launch.dir/main.cpp.o.d -o CMakeFiles/launch.dir/main.cpp.o -c /home/vamin/Documents/dashergame/main.cpp

CMakeFiles/launch.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/launch.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vamin/Documents/dashergame/main.cpp > CMakeFiles/launch.dir/main.cpp.i

CMakeFiles/launch.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/launch.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vamin/Documents/dashergame/main.cpp -o CMakeFiles/launch.dir/main.cpp.s

# Object files for target launch
launch_OBJECTS = \
"CMakeFiles/launch.dir/main.cpp.o"

# External object files for target launch
launch_EXTERNAL_OBJECTS =

launch: CMakeFiles/launch.dir/main.cpp.o
launch: CMakeFiles/launch.dir/build.make
launch: /usr/local/lib64/libraylib.so
launch: CMakeFiles/launch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vamin/Documents/dashergame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable launch"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/launch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/launch.dir/build: launch
.PHONY : CMakeFiles/launch.dir/build

CMakeFiles/launch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/launch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/launch.dir/clean

CMakeFiles/launch.dir/depend:
	cd /home/vamin/Documents/dashergame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vamin/Documents/dashergame /home/vamin/Documents/dashergame /home/vamin/Documents/dashergame/build /home/vamin/Documents/dashergame/build /home/vamin/Documents/dashergame/build/CMakeFiles/launch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/launch.dir/depend

