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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Alex\Desktop\ENAC\S7\Langage C\driveordie"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Alex\Desktop\ENAC\S7\Langage C\driveordie\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/driveordie.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/driveordie.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/driveordie.dir/flags.make

CMakeFiles/driveordie.dir/main.c.obj: CMakeFiles/driveordie.dir/flags.make
CMakeFiles/driveordie.dir/main.c.obj: CMakeFiles/driveordie.dir/includes_C.rsp
CMakeFiles/driveordie.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Alex\Desktop\ENAC\S7\Langage C\driveordie\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/driveordie.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\driveordie.dir\main.c.obj   -c "C:\Users\Alex\Desktop\ENAC\S7\Langage C\driveordie\main.c"

CMakeFiles/driveordie.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/driveordie.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Alex\Desktop\ENAC\S7\Langage C\driveordie\main.c" > CMakeFiles\driveordie.dir\main.c.i

CMakeFiles/driveordie.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/driveordie.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Alex\Desktop\ENAC\S7\Langage C\driveordie\main.c" -o CMakeFiles\driveordie.dir\main.c.s

# Object files for target driveordie
driveordie_OBJECTS = \
"CMakeFiles/driveordie.dir/main.c.obj"

# External object files for target driveordie
driveordie_EXTERNAL_OBJECTS =

driveordie.exe: CMakeFiles/driveordie.dir/main.c.obj
driveordie.exe: CMakeFiles/driveordie.dir/build.make
driveordie.exe: C:/MinGW/lib/libSDL2.dll.a
driveordie.exe: C:/MinGW/lib/libSDL2main.a
driveordie.exe: CMakeFiles/driveordie.dir/linklibs.rsp
driveordie.exe: CMakeFiles/driveordie.dir/objects1.rsp
driveordie.exe: CMakeFiles/driveordie.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Alex\Desktop\ENAC\S7\Langage C\driveordie\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable driveordie.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\driveordie.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/driveordie.dir/build: driveordie.exe

.PHONY : CMakeFiles/driveordie.dir/build

CMakeFiles/driveordie.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\driveordie.dir\cmake_clean.cmake
.PHONY : CMakeFiles/driveordie.dir/clean

CMakeFiles/driveordie.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Alex\Desktop\ENAC\S7\Langage C\driveordie" "C:\Users\Alex\Desktop\ENAC\S7\Langage C\driveordie" "C:\Users\Alex\Desktop\ENAC\S7\Langage C\driveordie\cmake-build-debug" "C:\Users\Alex\Desktop\ENAC\S7\Langage C\driveordie\cmake-build-debug" "C:\Users\Alex\Desktop\ENAC\S7\Langage C\driveordie\cmake-build-debug\CMakeFiles\driveordie.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/driveordie.dir/depend

