# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/zph/OPC UA/runDemoOpen62541"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/zph/OPC UA/runDemoOpen62541/build"

# Include any dependencies generated for this target.
include CMakeFiles/client_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client_test.dir/flags.make

CMakeFiles/client_test.dir/src/client_test.c.o: CMakeFiles/client_test.dir/flags.make
CMakeFiles/client_test.dir/src/client_test.c.o: ../src/client_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/zph/OPC UA/runDemoOpen62541/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/client_test.dir/src/client_test.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/client_test.dir/src/client_test.c.o   -c "/home/zph/OPC UA/runDemoOpen62541/src/client_test.c"

CMakeFiles/client_test.dir/src/client_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/client_test.dir/src/client_test.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/zph/OPC UA/runDemoOpen62541/src/client_test.c" > CMakeFiles/client_test.dir/src/client_test.c.i

CMakeFiles/client_test.dir/src/client_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/client_test.dir/src/client_test.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/zph/OPC UA/runDemoOpen62541/src/client_test.c" -o CMakeFiles/client_test.dir/src/client_test.c.s

CMakeFiles/client_test.dir/src/client_test.c.o.requires:

.PHONY : CMakeFiles/client_test.dir/src/client_test.c.o.requires

CMakeFiles/client_test.dir/src/client_test.c.o.provides: CMakeFiles/client_test.dir/src/client_test.c.o.requires
	$(MAKE) -f CMakeFiles/client_test.dir/build.make CMakeFiles/client_test.dir/src/client_test.c.o.provides.build
.PHONY : CMakeFiles/client_test.dir/src/client_test.c.o.provides

CMakeFiles/client_test.dir/src/client_test.c.o.provides.build: CMakeFiles/client_test.dir/src/client_test.c.o


# Object files for target client_test
client_test_OBJECTS = \
"CMakeFiles/client_test.dir/src/client_test.c.o"

# External object files for target client_test
client_test_EXTERNAL_OBJECTS =

../bin/client_test: CMakeFiles/client_test.dir/src/client_test.c.o
../bin/client_test: CMakeFiles/client_test.dir/build.make
../bin/client_test: CMakeFiles/client_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/zph/OPC UA/runDemoOpen62541/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/client_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client_test.dir/build: ../bin/client_test

.PHONY : CMakeFiles/client_test.dir/build

CMakeFiles/client_test.dir/requires: CMakeFiles/client_test.dir/src/client_test.c.o.requires

.PHONY : CMakeFiles/client_test.dir/requires

CMakeFiles/client_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client_test.dir/clean

CMakeFiles/client_test.dir/depend:
	cd "/home/zph/OPC UA/runDemoOpen62541/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/zph/OPC UA/runDemoOpen62541" "/home/zph/OPC UA/runDemoOpen62541" "/home/zph/OPC UA/runDemoOpen62541/build" "/home/zph/OPC UA/runDemoOpen62541/build" "/home/zph/OPC UA/runDemoOpen62541/build/CMakeFiles/client_test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/client_test.dir/depend

