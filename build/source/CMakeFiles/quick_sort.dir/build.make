# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.11.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.11.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/build

# Include any dependencies generated for this target.
include source/CMakeFiles/quick_sort.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/quick_sort.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/quick_sort.dir/flags.make

source/CMakeFiles/quick_sort.dir/quick_sort.cpp.o: source/CMakeFiles/quick_sort.dir/flags.make
source/CMakeFiles/quick_sort.dir/quick_sort.cpp.o: ../source/quick_sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/quick_sort.dir/quick_sort.cpp.o"
	cd /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/build/source && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quick_sort.dir/quick_sort.cpp.o -c /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/source/quick_sort.cpp

source/CMakeFiles/quick_sort.dir/quick_sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quick_sort.dir/quick_sort.cpp.i"
	cd /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/build/source && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/source/quick_sort.cpp > CMakeFiles/quick_sort.dir/quick_sort.cpp.i

source/CMakeFiles/quick_sort.dir/quick_sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quick_sort.dir/quick_sort.cpp.s"
	cd /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/build/source && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/source/quick_sort.cpp -o CMakeFiles/quick_sort.dir/quick_sort.cpp.s

# Object files for target quick_sort
quick_sort_OBJECTS = \
"CMakeFiles/quick_sort.dir/quick_sort.cpp.o"

# External object files for target quick_sort
quick_sort_EXTERNAL_OBJECTS =

source/quick_sort: source/CMakeFiles/quick_sort.dir/quick_sort.cpp.o
source/quick_sort: source/CMakeFiles/quick_sort.dir/build.make
source/quick_sort: source/CMakeFiles/quick_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable quick_sort"
	cd /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quick_sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/quick_sort.dir/build: source/quick_sort

.PHONY : source/CMakeFiles/quick_sort.dir/build

source/CMakeFiles/quick_sort.dir/clean:
	cd /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/build/source && $(CMAKE_COMMAND) -P CMakeFiles/quick_sort.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/quick_sort.dir/clean

source/CMakeFiles/quick_sort.dir/depend:
	cd /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4 /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/source /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/build /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/build/source /Users/Theresa/Desktop/programmiersprachen-aufgabenblatt-4/build/source/CMakeFiles/quick_sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/quick_sort.dir/depend

