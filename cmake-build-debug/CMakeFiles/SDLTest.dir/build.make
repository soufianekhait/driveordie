# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\soufi\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\soufi\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\soufi\CLionProjects\driveordie

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\soufi\CLionProjects\driveordie\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SDLTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SDLTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDLTest.dir/flags.make

CMakeFiles/SDLTest.dir/main.c.obj: CMakeFiles/SDLTest.dir/flags.make
CMakeFiles/SDLTest.dir/main.c.obj: CMakeFiles/SDLTest.dir/includes_C.rsp
CMakeFiles/SDLTest.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\soufi\CLionProjects\driveordie\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SDLTest.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\SDLTest.dir\main.c.obj   -c C:\Users\soufi\CLionProjects\driveordie\main.c

CMakeFiles/SDLTest.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SDLTest.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\soufi\CLionProjects\driveordie\main.c > CMakeFiles\SDLTest.dir\main.c.i

CMakeFiles/SDLTest.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SDLTest.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\soufi\CLionProjects\driveordie\main.c -o CMakeFiles\SDLTest.dir\main.c.s

# Object files for target SDLTest
SDLTest_OBJECTS = \
"CMakeFiles/SDLTest.dir/main.c.obj"

# External object files for target SDLTest
SDLTest_EXTERNAL_OBJECTS =

SDLTest.exe: CMakeFiles/SDLTest.dir/main.c.obj
SDLTest.exe: CMakeFiles/SDLTest.dir/build.make
SDLTest.exe: C:/MinGW/lib/libSDL2.dll.a
SDLTest.exe: C:/MinGW/lib/libSDL2main.a
SDLTest.exe: CMakeFiles/SDLTest.dir/linklibs.rsp
SDLTest.exe: CMakeFiles/SDLTest.dir/objects1.rsp
SDLTest.exe: CMakeFiles/SDLTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\soufi\CLionProjects\driveordie\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SDLTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SDLTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDLTest.dir/build: SDLTest.exe

.PHONY : CMakeFiles/SDLTest.dir/build

CMakeFiles/SDLTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SDLTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SDLTest.dir/clean

CMakeFiles/SDLTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\soufi\CLionProjects\driveordie C:\Users\soufi\CLionProjects\driveordie C:\Users\soufi\CLionProjects\driveordie\cmake-build-debug C:\Users\soufi\CLionProjects\driveordie\cmake-build-debug C:\Users\soufi\CLionProjects\driveordie\cmake-build-debug\CMakeFiles\SDLTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SDLTest.dir/depend
