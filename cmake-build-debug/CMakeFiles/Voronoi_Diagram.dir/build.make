# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Xiaomi\Documents\Programming\C++\Projects\Voronoi_Diagram

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Xiaomi\Documents\Programming\C++\Projects\Voronoi_Diagram\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Voronoi_Diagram.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Voronoi_Diagram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Voronoi_Diagram.dir/flags.make

CMakeFiles/Voronoi_Diagram.dir/main.cpp.obj: CMakeFiles/Voronoi_Diagram.dir/flags.make
CMakeFiles/Voronoi_Diagram.dir/main.cpp.obj: CMakeFiles/Voronoi_Diagram.dir/includes_CXX.rsp
CMakeFiles/Voronoi_Diagram.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Xiaomi\Documents\Programming\C++\Projects\Voronoi_Diagram\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Voronoi_Diagram.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Voronoi_Diagram.dir\main.cpp.obj -c C:\Users\Xiaomi\Documents\Programming\C++\Projects\Voronoi_Diagram\main.cpp

CMakeFiles/Voronoi_Diagram.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Voronoi_Diagram.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Xiaomi\Documents\Programming\C++\Projects\Voronoi_Diagram\main.cpp > CMakeFiles\Voronoi_Diagram.dir\main.cpp.i

CMakeFiles/Voronoi_Diagram.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Voronoi_Diagram.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Xiaomi\Documents\Programming\C++\Projects\Voronoi_Diagram\main.cpp -o CMakeFiles\Voronoi_Diagram.dir\main.cpp.s

# Object files for target Voronoi_Diagram
Voronoi_Diagram_OBJECTS = \
"CMakeFiles/Voronoi_Diagram.dir/main.cpp.obj"

# External object files for target Voronoi_Diagram
Voronoi_Diagram_EXTERNAL_OBJECTS =

Voronoi_Diagram.exe: CMakeFiles/Voronoi_Diagram.dir/main.cpp.obj
Voronoi_Diagram.exe: CMakeFiles/Voronoi_Diagram.dir/build.make
Voronoi_Diagram.exe: CMakeFiles/Voronoi_Diagram.dir/linklibs.rsp
Voronoi_Diagram.exe: CMakeFiles/Voronoi_Diagram.dir/objects1.rsp
Voronoi_Diagram.exe: CMakeFiles/Voronoi_Diagram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Xiaomi\Documents\Programming\C++\Projects\Voronoi_Diagram\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Voronoi_Diagram.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Voronoi_Diagram.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Voronoi_Diagram.dir/build: Voronoi_Diagram.exe

.PHONY : CMakeFiles/Voronoi_Diagram.dir/build

CMakeFiles/Voronoi_Diagram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Voronoi_Diagram.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Voronoi_Diagram.dir/clean

CMakeFiles/Voronoi_Diagram.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Xiaomi\Documents\Programming\C++\Projects\Voronoi_Diagram C:\Users\Xiaomi\Documents\Programming\C++\Projects\Voronoi_Diagram C:\Users\Xiaomi\Documents\Programming\C++\Projects\Voronoi_Diagram\cmake-build-debug C:\Users\Xiaomi\Documents\Programming\C++\Projects\Voronoi_Diagram\cmake-build-debug C:\Users\Xiaomi\Documents\Programming\C++\Projects\Voronoi_Diagram\cmake-build-debug\CMakeFiles\Voronoi_Diagram.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Voronoi_Diagram.dir/depend

