# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/mohamed/C03CCDB43CCDA62E/work/Code/VC_example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/mohamed/C03CCDB43CCDA62E/work/Code/VC_example

# Include any dependencies generated for this target.
include CMakeFiles/Vc_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Vc_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Vc_example.dir/flags.make

CMakeFiles/Vc_example.dir/src/main.cpp.o: CMakeFiles/Vc_example.dir/flags.make
CMakeFiles/Vc_example.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/mohamed/C03CCDB43CCDA62E/work/Code/VC_example/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Vc_example.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vc_example.dir/src/main.cpp.o -c /media/mohamed/C03CCDB43CCDA62E/work/Code/VC_example/src/main.cpp

CMakeFiles/Vc_example.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vc_example.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/mohamed/C03CCDB43CCDA62E/work/Code/VC_example/src/main.cpp > CMakeFiles/Vc_example.dir/src/main.cpp.i

CMakeFiles/Vc_example.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vc_example.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/mohamed/C03CCDB43CCDA62E/work/Code/VC_example/src/main.cpp -o CMakeFiles/Vc_example.dir/src/main.cpp.s

# Object files for target Vc_example
Vc_example_OBJECTS = \
"CMakeFiles/Vc_example.dir/src/main.cpp.o"

# External object files for target Vc_example
Vc_example_EXTERNAL_OBJECTS =

Vc_example: CMakeFiles/Vc_example.dir/src/main.cpp.o
Vc_example: CMakeFiles/Vc_example.dir/build.make
Vc_example: /home/mohamed/vcpkg/installed/x64-linux/debug/lib/libbox2d.a
Vc_example: /usr/lib/x86_64-linux-gnu/libX11.so
Vc_example: /usr/lib/x86_64-linux-gnu/libXrandr.so
Vc_example: /lib/x86_64-linux-gnu/libudev.so
Vc_example: CMakeFiles/Vc_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/mohamed/C03CCDB43CCDA62E/work/Code/VC_example/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Vc_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vc_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Vc_example.dir/build: Vc_example

.PHONY : CMakeFiles/Vc_example.dir/build

CMakeFiles/Vc_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Vc_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Vc_example.dir/clean

CMakeFiles/Vc_example.dir/depend:
	cd /media/mohamed/C03CCDB43CCDA62E/work/Code/VC_example && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/mohamed/C03CCDB43CCDA62E/work/Code/VC_example /media/mohamed/C03CCDB43CCDA62E/work/Code/VC_example /media/mohamed/C03CCDB43CCDA62E/work/Code/VC_example /media/mohamed/C03CCDB43CCDA62E/work/Code/VC_example /media/mohamed/C03CCDB43CCDA62E/work/Code/VC_example/CMakeFiles/Vc_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Vc_example.dir/depend

