# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = /home/ghost/progects/opengl/systemparticles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ghost/progects/opengl/systemparticles

# Include any dependencies generated for this target.
include CMakeFiles/particlesOpenGl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/particlesOpenGl.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/particlesOpenGl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/particlesOpenGl.dir/flags.make

CMakeFiles/particlesOpenGl.dir/particles.cpp.o: CMakeFiles/particlesOpenGl.dir/flags.make
CMakeFiles/particlesOpenGl.dir/particles.cpp.o: particles.cpp
CMakeFiles/particlesOpenGl.dir/particles.cpp.o: CMakeFiles/particlesOpenGl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ghost/progects/opengl/systemparticles/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/particlesOpenGl.dir/particles.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/particlesOpenGl.dir/particles.cpp.o -MF CMakeFiles/particlesOpenGl.dir/particles.cpp.o.d -o CMakeFiles/particlesOpenGl.dir/particles.cpp.o -c /home/ghost/progects/opengl/systemparticles/particles.cpp

CMakeFiles/particlesOpenGl.dir/particles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/particlesOpenGl.dir/particles.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ghost/progects/opengl/systemparticles/particles.cpp > CMakeFiles/particlesOpenGl.dir/particles.cpp.i

CMakeFiles/particlesOpenGl.dir/particles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/particlesOpenGl.dir/particles.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ghost/progects/opengl/systemparticles/particles.cpp -o CMakeFiles/particlesOpenGl.dir/particles.cpp.s

# Object files for target particlesOpenGl
particlesOpenGl_OBJECTS = \
"CMakeFiles/particlesOpenGl.dir/particles.cpp.o"

# External object files for target particlesOpenGl
particlesOpenGl_EXTERNAL_OBJECTS =

particlesOpenGl: CMakeFiles/particlesOpenGl.dir/particles.cpp.o
particlesOpenGl: CMakeFiles/particlesOpenGl.dir/build.make
particlesOpenGl: /usr/lib/libGL.so
particlesOpenGl: libglad.a
particlesOpenGl: /usr/lib/libglfw.so.3.3
particlesOpenGl: CMakeFiles/particlesOpenGl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ghost/progects/opengl/systemparticles/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable particlesOpenGl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/particlesOpenGl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/particlesOpenGl.dir/build: particlesOpenGl
.PHONY : CMakeFiles/particlesOpenGl.dir/build

CMakeFiles/particlesOpenGl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/particlesOpenGl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/particlesOpenGl.dir/clean

CMakeFiles/particlesOpenGl.dir/depend:
	cd /home/ghost/progects/opengl/systemparticles && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ghost/progects/opengl/systemparticles /home/ghost/progects/opengl/systemparticles /home/ghost/progects/opengl/systemparticles /home/ghost/progects/opengl/systemparticles /home/ghost/progects/opengl/systemparticles/CMakeFiles/particlesOpenGl.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/particlesOpenGl.dir/depend

