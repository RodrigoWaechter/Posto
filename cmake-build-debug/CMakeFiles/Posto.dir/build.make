# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\linguagemC\Projeto01\Posto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\linguagemC\Projeto01\Posto\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Posto.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Posto.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Posto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Posto.dir/flags.make

CMakeFiles/Posto.dir/main.c.obj: CMakeFiles/Posto.dir/flags.make
CMakeFiles/Posto.dir/main.c.obj: C:/linguagemC/Projeto01/Posto/main.c
CMakeFiles/Posto.dir/main.c.obj: CMakeFiles/Posto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\linguagemC\Projeto01\Posto\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Posto.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Posto.dir/main.c.obj -MF CMakeFiles\Posto.dir\main.c.obj.d -o CMakeFiles\Posto.dir\main.c.obj -c C:\linguagemC\Projeto01\Posto\main.c

CMakeFiles/Posto.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Posto.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\linguagemC\Projeto01\Posto\main.c > CMakeFiles\Posto.dir\main.c.i

CMakeFiles/Posto.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Posto.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\linguagemC\Projeto01\Posto\main.c -o CMakeFiles\Posto.dir\main.c.s

# Object files for target Posto
Posto_OBJECTS = \
"CMakeFiles/Posto.dir/main.c.obj"

# External object files for target Posto
Posto_EXTERNAL_OBJECTS =

Posto.exe: CMakeFiles/Posto.dir/main.c.obj
Posto.exe: CMakeFiles/Posto.dir/build.make
Posto.exe: CMakeFiles/Posto.dir/linkLibs.rsp
Posto.exe: CMakeFiles/Posto.dir/objects1.rsp
Posto.exe: CMakeFiles/Posto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\linguagemC\Projeto01\Posto\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Posto.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Posto.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Posto.dir/build: Posto.exe
.PHONY : CMakeFiles/Posto.dir/build

CMakeFiles/Posto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Posto.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Posto.dir/clean

CMakeFiles/Posto.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\linguagemC\Projeto01\Posto C:\linguagemC\Projeto01\Posto C:\linguagemC\Projeto01\Posto\cmake-build-debug C:\linguagemC\Projeto01\Posto\cmake-build-debug C:\linguagemC\Projeto01\Posto\cmake-build-debug\CMakeFiles\Posto.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Posto.dir/depend

