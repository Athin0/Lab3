# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /cygdrive/c/Users/arina/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/arina/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/arina/CLionProjects/Lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/arina/CLionProjects/Lab3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab3.dir/flags.make

CMakeFiles/Lab3.dir/main.cpp.o: CMakeFiles/Lab3.dir/flags.make
CMakeFiles/Lab3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/arina/CLionProjects/Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab3.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab3.dir/main.cpp.o -c /cygdrive/c/Users/arina/CLionProjects/Lab3/main.cpp

CMakeFiles/Lab3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab3.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/arina/CLionProjects/Lab3/main.cpp > CMakeFiles/Lab3.dir/main.cpp.i

CMakeFiles/Lab3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab3.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/arina/CLionProjects/Lab3/main.cpp -o CMakeFiles/Lab3.dir/main.cpp.s

CMakeFiles/Lab3.dir/BinaryTree.cpp.o: CMakeFiles/Lab3.dir/flags.make
CMakeFiles/Lab3.dir/BinaryTree.cpp.o: ../BinaryTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/arina/CLionProjects/Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab3.dir/BinaryTree.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab3.dir/BinaryTree.cpp.o -c /cygdrive/c/Users/arina/CLionProjects/Lab3/BinaryTree.cpp

CMakeFiles/Lab3.dir/BinaryTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab3.dir/BinaryTree.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/arina/CLionProjects/Lab3/BinaryTree.cpp > CMakeFiles/Lab3.dir/BinaryTree.cpp.i

CMakeFiles/Lab3.dir/BinaryTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab3.dir/BinaryTree.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/arina/CLionProjects/Lab3/BinaryTree.cpp -o CMakeFiles/Lab3.dir/BinaryTree.cpp.s

CMakeFiles/Lab3.dir/menuTree.cpp.o: CMakeFiles/Lab3.dir/flags.make
CMakeFiles/Lab3.dir/menuTree.cpp.o: ../menuTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/arina/CLionProjects/Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Lab3.dir/menuTree.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab3.dir/menuTree.cpp.o -c /cygdrive/c/Users/arina/CLionProjects/Lab3/menuTree.cpp

CMakeFiles/Lab3.dir/menuTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab3.dir/menuTree.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/arina/CLionProjects/Lab3/menuTree.cpp > CMakeFiles/Lab3.dir/menuTree.cpp.i

CMakeFiles/Lab3.dir/menuTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab3.dir/menuTree.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/arina/CLionProjects/Lab3/menuTree.cpp -o CMakeFiles/Lab3.dir/menuTree.cpp.s

CMakeFiles/Lab3.dir/baseFunc.cpp.o: CMakeFiles/Lab3.dir/flags.make
CMakeFiles/Lab3.dir/baseFunc.cpp.o: ../baseFunc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/arina/CLionProjects/Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Lab3.dir/baseFunc.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab3.dir/baseFunc.cpp.o -c /cygdrive/c/Users/arina/CLionProjects/Lab3/baseFunc.cpp

CMakeFiles/Lab3.dir/baseFunc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab3.dir/baseFunc.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/arina/CLionProjects/Lab3/baseFunc.cpp > CMakeFiles/Lab3.dir/baseFunc.cpp.i

CMakeFiles/Lab3.dir/baseFunc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab3.dir/baseFunc.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/arina/CLionProjects/Lab3/baseFunc.cpp -o CMakeFiles/Lab3.dir/baseFunc.cpp.s

# Object files for target Lab3
Lab3_OBJECTS = \
"CMakeFiles/Lab3.dir/main.cpp.o" \
"CMakeFiles/Lab3.dir/BinaryTree.cpp.o" \
"CMakeFiles/Lab3.dir/menuTree.cpp.o" \
"CMakeFiles/Lab3.dir/baseFunc.cpp.o"

# External object files for target Lab3
Lab3_EXTERNAL_OBJECTS =

Lab3.exe: CMakeFiles/Lab3.dir/main.cpp.o
Lab3.exe: CMakeFiles/Lab3.dir/BinaryTree.cpp.o
Lab3.exe: CMakeFiles/Lab3.dir/menuTree.cpp.o
Lab3.exe: CMakeFiles/Lab3.dir/baseFunc.cpp.o
Lab3.exe: CMakeFiles/Lab3.dir/build.make
Lab3.exe: CMakeFiles/Lab3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/arina/CLionProjects/Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Lab3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab3.dir/build: Lab3.exe

.PHONY : CMakeFiles/Lab3.dir/build

CMakeFiles/Lab3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab3.dir/clean

CMakeFiles/Lab3.dir/depend:
	cd /cygdrive/c/Users/arina/CLionProjects/Lab3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/arina/CLionProjects/Lab3 /cygdrive/c/Users/arina/CLionProjects/Lab3 /cygdrive/c/Users/arina/CLionProjects/Lab3/cmake-build-debug /cygdrive/c/Users/arina/CLionProjects/Lab3/cmake-build-debug /cygdrive/c/Users/arina/CLionProjects/Lab3/cmake-build-debug/CMakeFiles/Lab3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab3.dir/depend
