# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/build

# Include any dependencies generated for this target.
include CMakeFiles/lab2_exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab2_exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab2_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab2_exe.dir/flags.make

CMakeFiles/lab2_exe.dir/codegen:
.PHONY : CMakeFiles/lab2_exe.dir/codegen

CMakeFiles/lab2_exe.dir/src/main.cpp.o: CMakeFiles/lab2_exe.dir/flags.make
CMakeFiles/lab2_exe.dir/src/main.cpp.o: /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/src/main.cpp
CMakeFiles/lab2_exe.dir/src/main.cpp.o: CMakeFiles/lab2_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab2_exe.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab2_exe.dir/src/main.cpp.o -MF CMakeFiles/lab2_exe.dir/src/main.cpp.o.d -o CMakeFiles/lab2_exe.dir/src/main.cpp.o -c /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/src/main.cpp

CMakeFiles/lab2_exe.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab2_exe.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/src/main.cpp > CMakeFiles/lab2_exe.dir/src/main.cpp.i

CMakeFiles/lab2_exe.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab2_exe.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/src/main.cpp -o CMakeFiles/lab2_exe.dir/src/main.cpp.s

CMakeFiles/lab2_exe.dir/include/solution.cpp.o: CMakeFiles/lab2_exe.dir/flags.make
CMakeFiles/lab2_exe.dir/include/solution.cpp.o: /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/include/solution.cpp
CMakeFiles/lab2_exe.dir/include/solution.cpp.o: CMakeFiles/lab2_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab2_exe.dir/include/solution.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab2_exe.dir/include/solution.cpp.o -MF CMakeFiles/lab2_exe.dir/include/solution.cpp.o.d -o CMakeFiles/lab2_exe.dir/include/solution.cpp.o -c /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/include/solution.cpp

CMakeFiles/lab2_exe.dir/include/solution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab2_exe.dir/include/solution.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/include/solution.cpp > CMakeFiles/lab2_exe.dir/include/solution.cpp.i

CMakeFiles/lab2_exe.dir/include/solution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab2_exe.dir/include/solution.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/include/solution.cpp -o CMakeFiles/lab2_exe.dir/include/solution.cpp.s

# Object files for target lab2_exe
lab2_exe_OBJECTS = \
"CMakeFiles/lab2_exe.dir/src/main.cpp.o" \
"CMakeFiles/lab2_exe.dir/include/solution.cpp.o"

# External object files for target lab2_exe
lab2_exe_EXTERNAL_OBJECTS =

lab2_exe: CMakeFiles/lab2_exe.dir/src/main.cpp.o
lab2_exe: CMakeFiles/lab2_exe.dir/include/solution.cpp.o
lab2_exe: CMakeFiles/lab2_exe.dir/build.make
lab2_exe: CMakeFiles/lab2_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab2_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab2_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab2_exe.dir/build: lab2_exe
.PHONY : CMakeFiles/lab2_exe.dir/build

CMakeFiles/lab2_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab2_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab2_exe.dir/clean

CMakeFiles/lab2_exe.dir/depend:
	cd /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/build /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/build /Users/matveyd/CLionProjects/OOP/Lab2/OOP_MAI-lab2_oop_mai/build/CMakeFiles/lab2_exe.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab2_exe.dir/depend

