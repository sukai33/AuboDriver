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
include src/03-FKIK/CMakeFiles/fkik.dir/depend.make

# Include the progress variables for this target.
include src/03-FKIK/CMakeFiles/fkik.dir/progress.make

# Include the compile flags for this target's objects.
include src/03-FKIK/CMakeFiles/fkik.dir/flags.make

src/03-FKIK/CMakeFiles/fkik.dir/fkik_autogen/mocs_compilation.cpp.o: src/03-FKIK/CMakeFiles/fkik.dir/flags.make
src/03-FKIK/CMakeFiles/fkik.dir/fkik_autogen/mocs_compilation.cpp.o: src/03-FKIK/fkik_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/03-FKIK/CMakeFiles/fkik.dir/fkik_autogen/mocs_compilation.cpp.o"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fkik.dir/fkik_autogen/mocs_compilation.cpp.o -c /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK/fkik_autogen/mocs_compilation.cpp

src/03-FKIK/CMakeFiles/fkik.dir/fkik_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fkik.dir/fkik_autogen/mocs_compilation.cpp.i"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK/fkik_autogen/mocs_compilation.cpp > CMakeFiles/fkik.dir/fkik_autogen/mocs_compilation.cpp.i

src/03-FKIK/CMakeFiles/fkik.dir/fkik_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fkik.dir/fkik_autogen/mocs_compilation.cpp.s"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK/fkik_autogen/mocs_compilation.cpp -o CMakeFiles/fkik.dir/fkik_autogen/mocs_compilation.cpp.s

src/03-FKIK/CMakeFiles/fkik.dir/main.cpp.o: src/03-FKIK/CMakeFiles/fkik.dir/flags.make
src/03-FKIK/CMakeFiles/fkik.dir/main.cpp.o: ../src/03-FKIK/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/03-FKIK/CMakeFiles/fkik.dir/main.cpp.o"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fkik.dir/main.cpp.o -c /home/sk/workspas/AuboDriver/src/03-FKIK/main.cpp

src/03-FKIK/CMakeFiles/fkik.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fkik.dir/main.cpp.i"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sk/workspas/AuboDriver/src/03-FKIK/main.cpp > CMakeFiles/fkik.dir/main.cpp.i

src/03-FKIK/CMakeFiles/fkik.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fkik.dir/main.cpp.s"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sk/workspas/AuboDriver/src/03-FKIK/main.cpp -o CMakeFiles/fkik.dir/main.cpp.s

src/03-FKIK/CMakeFiles/fkik.dir/MainWindow.cpp.o: src/03-FKIK/CMakeFiles/fkik.dir/flags.make
src/03-FKIK/CMakeFiles/fkik.dir/MainWindow.cpp.o: ../src/03-FKIK/MainWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/03-FKIK/CMakeFiles/fkik.dir/MainWindow.cpp.o"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fkik.dir/MainWindow.cpp.o -c /home/sk/workspas/AuboDriver/src/03-FKIK/MainWindow.cpp

src/03-FKIK/CMakeFiles/fkik.dir/MainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fkik.dir/MainWindow.cpp.i"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sk/workspas/AuboDriver/src/03-FKIK/MainWindow.cpp > CMakeFiles/fkik.dir/MainWindow.cpp.i

src/03-FKIK/CMakeFiles/fkik.dir/MainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fkik.dir/MainWindow.cpp.s"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sk/workspas/AuboDriver/src/03-FKIK/MainWindow.cpp -o CMakeFiles/fkik.dir/MainWindow.cpp.s

# Object files for target fkik
fkik_OBJECTS = \
"CMakeFiles/fkik.dir/fkik_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/fkik.dir/main.cpp.o" \
"CMakeFiles/fkik.dir/MainWindow.cpp.o"

# External object files for target fkik
fkik_EXTERNAL_OBJECTS =

../build/bin/fkik: src/03-FKIK/CMakeFiles/fkik.dir/fkik_autogen/mocs_compilation.cpp.o
../build/bin/fkik: src/03-FKIK/CMakeFiles/fkik.dir/main.cpp.o
../build/bin/fkik: src/03-FKIK/CMakeFiles/fkik.dir/MainWindow.cpp.o
../build/bin/fkik: src/03-FKIK/CMakeFiles/fkik.dir/build.make
../build/bin/fkik: ../3rdparty/qt/lib/libQt5OpenGL.so.5.7.1
../build/bin/fkik: ../3rdparty/qt/lib/libQt5Network.so.5.7.1
../build/bin/fkik: ../build/lib/libaubo.a
../build/bin/fkik: ../3rdparty/qt/lib/libQt5Widgets.so.5.7.1
../build/bin/fkik: ../3rdparty/qt/lib/libQt5Gui.so.5.7.1
../build/bin/fkik: ../3rdparty/qt/lib/libQt5Core.so.5.7.1
../build/bin/fkik: src/03-FKIK/CMakeFiles/fkik.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sk/workspas/AuboDriver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../../build/bin/fkik"
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fkik.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/03-FKIK/CMakeFiles/fkik.dir/build: ../build/bin/fkik

.PHONY : src/03-FKIK/CMakeFiles/fkik.dir/build

src/03-FKIK/CMakeFiles/fkik.dir/clean:
	cd /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK && $(CMAKE_COMMAND) -P CMakeFiles/fkik.dir/cmake_clean.cmake
.PHONY : src/03-FKIK/CMakeFiles/fkik.dir/clean

src/03-FKIK/CMakeFiles/fkik.dir/depend:
	cd /home/sk/workspas/AuboDriver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sk/workspas/AuboDriver /home/sk/workspas/AuboDriver/src/03-FKIK /home/sk/workspas/AuboDriver/cmake-build-debug /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK /home/sk/workspas/AuboDriver/cmake-build-debug/src/03-FKIK/CMakeFiles/fkik.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/03-FKIK/CMakeFiles/fkik.dir/depend

