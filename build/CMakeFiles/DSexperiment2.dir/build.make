# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\coding\projects\dsex2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\coding\projects\dsex2\build

# Include any dependencies generated for this target.
include CMakeFiles/DSexperiment2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DSexperiment2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DSexperiment2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DSexperiment2.dir/flags.make

CMakeFiles/DSexperiment2.dir/testDSexperiment2.c.obj: CMakeFiles/DSexperiment2.dir/flags.make
CMakeFiles/DSexperiment2.dir/testDSexperiment2.c.obj: ../testDSexperiment2.c
CMakeFiles/DSexperiment2.dir/testDSexperiment2.c.obj: CMakeFiles/DSexperiment2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\coding\projects\dsex2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DSexperiment2.dir/testDSexperiment2.c.obj"
	E:\coding\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DSexperiment2.dir/testDSexperiment2.c.obj -MF CMakeFiles\DSexperiment2.dir\testDSexperiment2.c.obj.d -o CMakeFiles\DSexperiment2.dir\testDSexperiment2.c.obj -c E:\coding\projects\dsex2\testDSexperiment2.c

CMakeFiles/DSexperiment2.dir/testDSexperiment2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DSexperiment2.dir/testDSexperiment2.c.i"
	E:\coding\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\coding\projects\dsex2\testDSexperiment2.c > CMakeFiles\DSexperiment2.dir\testDSexperiment2.c.i

CMakeFiles/DSexperiment2.dir/testDSexperiment2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DSexperiment2.dir/testDSexperiment2.c.s"
	E:\coding\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\coding\projects\dsex2\testDSexperiment2.c -o CMakeFiles\DSexperiment2.dir\testDSexperiment2.c.s

CMakeFiles/DSexperiment2.dir/DSexperiment2.c.obj: CMakeFiles/DSexperiment2.dir/flags.make
CMakeFiles/DSexperiment2.dir/DSexperiment2.c.obj: ../DSexperiment2.c
CMakeFiles/DSexperiment2.dir/DSexperiment2.c.obj: CMakeFiles/DSexperiment2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\coding\projects\dsex2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/DSexperiment2.dir/DSexperiment2.c.obj"
	E:\coding\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DSexperiment2.dir/DSexperiment2.c.obj -MF CMakeFiles\DSexperiment2.dir\DSexperiment2.c.obj.d -o CMakeFiles\DSexperiment2.dir\DSexperiment2.c.obj -c E:\coding\projects\dsex2\DSexperiment2.c

CMakeFiles/DSexperiment2.dir/DSexperiment2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DSexperiment2.dir/DSexperiment2.c.i"
	E:\coding\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\coding\projects\dsex2\DSexperiment2.c > CMakeFiles\DSexperiment2.dir\DSexperiment2.c.i

CMakeFiles/DSexperiment2.dir/DSexperiment2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DSexperiment2.dir/DSexperiment2.c.s"
	E:\coding\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\coding\projects\dsex2\DSexperiment2.c -o CMakeFiles\DSexperiment2.dir\DSexperiment2.c.s

# Object files for target DSexperiment2
DSexperiment2_OBJECTS = \
"CMakeFiles/DSexperiment2.dir/testDSexperiment2.c.obj" \
"CMakeFiles/DSexperiment2.dir/DSexperiment2.c.obj"

# External object files for target DSexperiment2
DSexperiment2_EXTERNAL_OBJECTS =

DSexperiment2.exe: CMakeFiles/DSexperiment2.dir/testDSexperiment2.c.obj
DSexperiment2.exe: CMakeFiles/DSexperiment2.dir/DSexperiment2.c.obj
DSexperiment2.exe: CMakeFiles/DSexperiment2.dir/build.make
DSexperiment2.exe: CMakeFiles/DSexperiment2.dir/linklibs.rsp
DSexperiment2.exe: CMakeFiles/DSexperiment2.dir/objects1.rsp
DSexperiment2.exe: CMakeFiles/DSexperiment2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\coding\projects\dsex2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable DSexperiment2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DSexperiment2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DSexperiment2.dir/build: DSexperiment2.exe
.PHONY : CMakeFiles/DSexperiment2.dir/build

CMakeFiles/DSexperiment2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DSexperiment2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DSexperiment2.dir/clean

CMakeFiles/DSexperiment2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\coding\projects\dsex2 E:\coding\projects\dsex2 E:\coding\projects\dsex2\build E:\coding\projects\dsex2\build E:\coding\projects\dsex2\build\CMakeFiles\DSexperiment2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DSexperiment2.dir/depend

