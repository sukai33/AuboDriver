# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/sk/CLion-2020.1.1/clion-2020.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sk/CLion-2020.1.1/clion-2020.1.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sk/workspas/AuboDriver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sk/workspas/AuboDriver/cmake-build-debug

# Include any dependencies generated for this target.
include src/02-movel/CMakeFiles/movel.dir/depend.make

# Include the progress variables for this target.
include src/02-movel/CMakeFiles/movel.dir/progress.make

# Include the compile flags for this target's objects.
include src/02-movel/CMakeFiles/movel.dir/flags.make

src/02-movel/CMakeFiles/movel.dir/movel_autogen/mocs_compilation.cpp.o: src/02-movel/CMakeFiles/movel.dir/flags.make
src/02-movel/CMakeFiles/movel.dir/movel_autogen/mocs_compilation.cpp.o: src/02-movel/movel_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/02-movel/CMakeFiles/movel.dir/movel_autogen/mocs_compilation.cpp.o"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/movel.dir/movel_autogen/mocs_compilation.cpp.o -c /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel/movel_autogen/mocs_compilation.cpp

src/02-movel/CMakeFiles/movel.dir/movel_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/movel.dir/movel_autogen/mocs_compilation.cpp.i"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel/movel_autogen/mocs_compilation.cpp > CMakeFiles/movel.dir/movel_autogen/mocs_compilation.cpp.i

src/02-movel/CMakeFiles/movel.dir/movel_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/movel.dir/movel_autogen/mocs_compilation.cpp.s"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel/movel_autogen/mocs_compilation.cpp -o CMakeFiles/movel.dir/movel_autogen/mocs_compilation.cpp.s

src/02-movel/CMakeFiles/movel.dir/main.cpp.o: src/02-movel/CMakeFiles/movel.dir/flags.make
src/02-movel/CMakeFiles/movel.dir/main.cpp.o: ../src/02-movel/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/02-movel/CMakeFiles/movel.dir/main.cpp.o"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/movel.dir/main.cpp.o -c /home/sk/workspas/AuboDriver/src/02-movel/main.cpp

src/02-movel/CMakeFiles/movel.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/movel.dir/main.cpp.i"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sk/workspas/AuboDriver/src/02-movel/main.cpp > CMakeFiles/movel.dir/main.cpp.i

src/02-movel/CMakeFiles/movel.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/movel.dir/main.cpp.s"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sk/workspas/AuboDriver/src/02-movel/main.cpp -o CMakeFiles/movel.dir/main.cpp.s

src/02-movel/CMakeFiles/movel.dir/MainWindow.cpp.o: src/02-movel/CMakeFiles/movel.dir/flags.make
src/02-movel/CMakeFiles/movel.dir/MainWindow.cpp.o: ../src/02-movel/MainWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/02-movel/CMakeFiles/movel.dir/MainWindow.cpp.o"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/movel.dir/MainWindow.cpp.o -c /home/sk/workspas/AuboDriver/src/02-movel/MainWindow.cpp

src/02-movel/CMakeFiles/movel.dir/MainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/movel.dir/MainWindow.cpp.i"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sk/workspas/AuboDriver/src/02-movel/MainWindow.cpp > CMakeFiles/movel.dir/MainWindow.cpp.i

src/02-movel/CMakeFiles/movel.dir/MainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/movel.dir/MainWindow.cpp.s"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sk/workspas/AuboDriver/src/02-movel/MainWindow.cpp -o CMakeFiles/movel.dir/MainWindow.cpp.s

src/02-movel/CMakeFiles/movel.dir/__/utils/Robot.cpp.o: src/02-movel/CMakeFiles/movel.dir/flags.make
src/02-movel/CMakeFiles/movel.dir/__/utils/Robot.cpp.o: ../src/utils/Robot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/02-movel/CMakeFiles/movel.dir/__/utils/Robot.cpp.o"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/movel.dir/__/utils/Robot.cpp.o -c /home/sk/workspas/AuboDriver/src/utils/Robot.cpp

src/02-movel/CMakeFiles/movel.dir/__/utils/Robot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/movel.dir/__/utils/Robot.cpp.i"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sk/workspas/AuboDriver/src/utils/Robot.cpp > CMakeFiles/movel.dir/__/utils/Robot.cpp.i

src/02-movel/CMakeFiles/movel.dir/__/utils/Robot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/movel.dir/__/utils/Robot.cpp.s"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sk/workspas/AuboDriver/src/utils/Robot.cpp -o CMakeFiles/movel.dir/__/utils/Robot.cpp.s

src/02-movel/CMakeFiles/movel.dir/__/utils/util.cpp.o: src/02-movel/CMakeFiles/movel.dir/flags.make
src/02-movel/CMakeFiles/movel.dir/__/utils/util.cpp.o: ../src/utils/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/02-movel/CMakeFiles/movel.dir/__/utils/util.cpp.o"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/movel.dir/__/utils/util.cpp.o -c /home/sk/workspas/AuboDriver/src/utils/util.cpp

src/02-movel/CMakeFiles/movel.dir/__/utils/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/movel.dir/__/utils/util.cpp.i"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sk/workspas/AuboDriver/src/utils/util.cpp > CMakeFiles/movel.dir/__/utils/util.cpp.i

src/02-movel/CMakeFiles/movel.dir/__/utils/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/movel.dir/__/utils/util.cpp.s"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sk/workspas/AuboDriver/src/utils/util.cpp -o CMakeFiles/movel.dir/__/utils/util.cpp.s

# Object files for target movel
movel_OBJECTS = \
"CMakeFiles/movel.dir/movel_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/movel.dir/main.cpp.o" \
"CMakeFiles/movel.dir/MainWindow.cpp.o" \
"CMakeFiles/movel.dir/__/utils/Robot.cpp.o" \
"CMakeFiles/movel.dir/__/utils/util.cpp.o"

# External object files for target movel
movel_EXTERNAL_OBJECTS =

../build/bin/movel: src/02-movel/CMakeFiles/movel.dir/movel_autogen/mocs_compilation.cpp.o
../build/bin/movel: src/02-movel/CMakeFiles/movel.dir/main.cpp.o
../build/bin/movel: src/02-movel/CMakeFiles/movel.dir/MainWindow.cpp.o
../build/bin/movel: src/02-movel/CMakeFiles/movel.dir/__/utils/Robot.cpp.o
../build/bin/movel: src/02-movel/CMakeFiles/movel.dir/__/utils/util.cpp.o
../build/bin/movel: src/02-movel/CMakeFiles/movel.dir/build.make
../build/bin/movel: ../3rdparty/qt/lib/libQt5OpenGL.so.5.7.1
../build/bin/movel: ../3rdparty/qt/lib/libQt5Network.so.5.7.1
../build/bin/movel: ../3rdparty/qt/lib/libQt5Widgets.so.5.7.1
../build/bin/movel: ../3rdparty/qt/lib/libQt5Gui.so.5.7.1
../build/bin/movel: ../3rdparty/qt/lib/libQt5Core.so.5.7.1
../build/bin/movel: src/02-movel/CMakeFiles/movel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../../../build/bin/movel"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/movel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/02-movel/CMakeFiles/movel.dir/build: ../build/bin/movel

.PHONY : src/02-movel/CMakeFiles/movel.dir/build

src/02-movel/CMakeFiles/movel.dir/clean:
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel && $(CMAKE_COMMAND) -P CMakeFiles/movel.dir/cmake_clean.cmake
.PHONY : src/02-movel/CMakeFiles/movel.dir/clean

src/02-movel/CMakeFiles/movel.dir/depend:
	cd /home/sk/workspas/AuboDriver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sk/workspas/AuboDriver /home/sk/workspas/AuboDriver/src/02-movel /home/sk/workspas/AuboDriver/cmake-build-debug /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel /home/sk/workspas/AuboDriver/cmake-build-debug/src/02-movel/CMakeFiles/movel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/02-movel/CMakeFiles/movel.dir/depend

