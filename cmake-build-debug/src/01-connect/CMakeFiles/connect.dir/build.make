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
include src/01-connect/CMakeFiles/connect.dir/depend.make

# Include the progress variables for this target.
include src/01-connect/CMakeFiles/connect.dir/progress.make

# Include the compile flags for this target's objects.
include src/01-connect/CMakeFiles/connect.dir/flags.make

src/01-connect/CMakeFiles/connect.dir/connect_autogen/mocs_compilation.cpp.o: src/01-connect/CMakeFiles/connect.dir/flags.make
src/01-connect/CMakeFiles/connect.dir/connect_autogen/mocs_compilation.cpp.o: src/01-connect/connect_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/01-connect/CMakeFiles/connect.dir/connect_autogen/mocs_compilation.cpp.o"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/connect.dir/connect_autogen/mocs_compilation.cpp.o -c /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect/connect_autogen/mocs_compilation.cpp

src/01-connect/CMakeFiles/connect.dir/connect_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/connect.dir/connect_autogen/mocs_compilation.cpp.i"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect/connect_autogen/mocs_compilation.cpp > CMakeFiles/connect.dir/connect_autogen/mocs_compilation.cpp.i

src/01-connect/CMakeFiles/connect.dir/connect_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/connect.dir/connect_autogen/mocs_compilation.cpp.s"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect/connect_autogen/mocs_compilation.cpp -o CMakeFiles/connect.dir/connect_autogen/mocs_compilation.cpp.s

src/01-connect/CMakeFiles/connect.dir/main.cpp.o: src/01-connect/CMakeFiles/connect.dir/flags.make
src/01-connect/CMakeFiles/connect.dir/main.cpp.o: ../src/01-connect/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/01-connect/CMakeFiles/connect.dir/main.cpp.o"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/connect.dir/main.cpp.o -c /home/sk/workspas/AuboDriver/src/01-connect/main.cpp

src/01-connect/CMakeFiles/connect.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/connect.dir/main.cpp.i"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sk/workspas/AuboDriver/src/01-connect/main.cpp > CMakeFiles/connect.dir/main.cpp.i

src/01-connect/CMakeFiles/connect.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/connect.dir/main.cpp.s"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sk/workspas/AuboDriver/src/01-connect/main.cpp -o CMakeFiles/connect.dir/main.cpp.s

src/01-connect/CMakeFiles/connect.dir/MainWindow.cpp.o: src/01-connect/CMakeFiles/connect.dir/flags.make
src/01-connect/CMakeFiles/connect.dir/MainWindow.cpp.o: ../src/01-connect/MainWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/01-connect/CMakeFiles/connect.dir/MainWindow.cpp.o"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/connect.dir/MainWindow.cpp.o -c /home/sk/workspas/AuboDriver/src/01-connect/MainWindow.cpp

src/01-connect/CMakeFiles/connect.dir/MainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/connect.dir/MainWindow.cpp.i"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sk/workspas/AuboDriver/src/01-connect/MainWindow.cpp > CMakeFiles/connect.dir/MainWindow.cpp.i

src/01-connect/CMakeFiles/connect.dir/MainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/connect.dir/MainWindow.cpp.s"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sk/workspas/AuboDriver/src/01-connect/MainWindow.cpp -o CMakeFiles/connect.dir/MainWindow.cpp.s

# Object files for target connect
connect_OBJECTS = \
"CMakeFiles/connect.dir/connect_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/connect.dir/main.cpp.o" \
"CMakeFiles/connect.dir/MainWindow.cpp.o"

# External object files for target connect
connect_EXTERNAL_OBJECTS =

../build/bin/connect: src/01-connect/CMakeFiles/connect.dir/connect_autogen/mocs_compilation.cpp.o
../build/bin/connect: src/01-connect/CMakeFiles/connect.dir/main.cpp.o
../build/bin/connect: src/01-connect/CMakeFiles/connect.dir/MainWindow.cpp.o
../build/bin/connect: src/01-connect/CMakeFiles/connect.dir/build.make
../build/bin/connect: ../3rdparty/qt/lib/libQt5OpenGL.so.5.7.1
../build/bin/connect: ../3rdparty/qt/lib/libQt5Network.so.5.7.1
../build/bin/connect: ../build/lib/libaubo.a
../build/bin/connect: ../3rdparty/qt/lib/libQt5Widgets.so.5.7.1
../build/bin/connect: ../3rdparty/qt/lib/libQt5Gui.so.5.7.1
../build/bin/connect: ../3rdparty/qt/lib/libQt5Core.so.5.7.1
../build/bin/connect: src/01-connect/CMakeFiles/connect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../../build/bin/connect"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/connect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/01-connect/CMakeFiles/connect.dir/build: ../build/bin/connect

.PHONY : src/01-connect/CMakeFiles/connect.dir/build

src/01-connect/CMakeFiles/connect.dir/clean:
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect && $(CMAKE_COMMAND) -P CMakeFiles/connect.dir/cmake_clean.cmake
.PHONY : src/01-connect/CMakeFiles/connect.dir/clean

src/01-connect/CMakeFiles/connect.dir/depend:
	cd /home/sk/workspas/AuboDriver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sk/workspas/AuboDriver /home/sk/workspas/AuboDriver/src/01-connect /home/sk/workspas/AuboDriver/cmake-build-debug /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect /home/sk/workspas/AuboDriver/cmake-build-debug/src/01-connect/CMakeFiles/connect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/01-connect/CMakeFiles/connect.dir/depend
