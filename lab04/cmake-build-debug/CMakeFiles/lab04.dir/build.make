# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /var/lib/snapd/snap/clion/198/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /var/lib/snapd/snap/clion/198/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yarin/Tecniche-di-Programmazione-Lab-PoliTO-2022/lab04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yarin/Tecniche-di-Programmazione-Lab-PoliTO-2022/lab04/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab04.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab04.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab04.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab04.dir/flags.make

CMakeFiles/lab04.dir/main1.c.o: CMakeFiles/lab04.dir/flags.make
CMakeFiles/lab04.dir/main1.c.o: ../main1.c
CMakeFiles/lab04.dir/main1.c.o: CMakeFiles/lab04.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yarin/Tecniche-di-Programmazione-Lab-PoliTO-2022/lab04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab04.dir/main1.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lab04.dir/main1.c.o -MF CMakeFiles/lab04.dir/main1.c.o.d -o CMakeFiles/lab04.dir/main1.c.o -c /home/yarin/Tecniche-di-Programmazione-Lab-PoliTO-2022/lab04/main1.c

CMakeFiles/lab04.dir/main1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab04.dir/main1.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yarin/Tecniche-di-Programmazione-Lab-PoliTO-2022/lab04/main1.c > CMakeFiles/lab04.dir/main1.c.i

CMakeFiles/lab04.dir/main1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab04.dir/main1.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yarin/Tecniche-di-Programmazione-Lab-PoliTO-2022/lab04/main1.c -o CMakeFiles/lab04.dir/main1.c.s

# Object files for target lab04
lab04_OBJECTS = \
"CMakeFiles/lab04.dir/main1.c.o"

# External object files for target lab04
lab04_EXTERNAL_OBJECTS =

lab04: CMakeFiles/lab04.dir/main1.c.o
lab04: CMakeFiles/lab04.dir/build.make
lab04: CMakeFiles/lab04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yarin/Tecniche-di-Programmazione-Lab-PoliTO-2022/lab04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab04"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab04.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab04.dir/build: lab04
.PHONY : CMakeFiles/lab04.dir/build

CMakeFiles/lab04.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab04.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab04.dir/clean

CMakeFiles/lab04.dir/depend:
	cd /home/yarin/Tecniche-di-Programmazione-Lab-PoliTO-2022/lab04/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yarin/Tecniche-di-Programmazione-Lab-PoliTO-2022/lab04 /home/yarin/Tecniche-di-Programmazione-Lab-PoliTO-2022/lab04 /home/yarin/Tecniche-di-Programmazione-Lab-PoliTO-2022/lab04/cmake-build-debug /home/yarin/Tecniche-di-Programmazione-Lab-PoliTO-2022/lab04/cmake-build-debug /home/yarin/Tecniche-di-Programmazione-Lab-PoliTO-2022/lab04/cmake-build-debug/CMakeFiles/lab04.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab04.dir/depend

