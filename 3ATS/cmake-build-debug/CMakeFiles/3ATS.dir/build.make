# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /cygdrive/c/Users/Povilas/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Povilas/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/3ATS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3ATS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3ATS.dir/flags.make

CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o: CMakeFiles/3ATS.dir/flags.make
CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o: ../ADS_pirmas1.1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o   -c "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/ADS_pirmas1.1.c"

CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/ADS_pirmas1.1.c" > CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.i

CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/ADS_pirmas1.1.c" -o CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.s

CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o.requires:

.PHONY : CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o.requires

CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o.provides: CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o.requires
	$(MAKE) -f CMakeFiles/3ATS.dir/build.make CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o.provides.build
.PHONY : CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o.provides

CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o.provides.build: CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o


CMakeFiles/3ATS.dir/BigInt.c.o: CMakeFiles/3ATS.dir/flags.make
CMakeFiles/3ATS.dir/BigInt.c.o: ../BigInt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/3ATS.dir/BigInt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/3ATS.dir/BigInt.c.o   -c "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/BigInt.c"

CMakeFiles/3ATS.dir/BigInt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/3ATS.dir/BigInt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/BigInt.c" > CMakeFiles/3ATS.dir/BigInt.c.i

CMakeFiles/3ATS.dir/BigInt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/3ATS.dir/BigInt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/BigInt.c" -o CMakeFiles/3ATS.dir/BigInt.c.s

CMakeFiles/3ATS.dir/BigInt.c.o.requires:

.PHONY : CMakeFiles/3ATS.dir/BigInt.c.o.requires

CMakeFiles/3ATS.dir/BigInt.c.o.provides: CMakeFiles/3ATS.dir/BigInt.c.o.requires
	$(MAKE) -f CMakeFiles/3ATS.dir/build.make CMakeFiles/3ATS.dir/BigInt.c.o.provides.build
.PHONY : CMakeFiles/3ATS.dir/BigInt.c.o.provides

CMakeFiles/3ATS.dir/BigInt.c.o.provides.build: CMakeFiles/3ATS.dir/BigInt.c.o


CMakeFiles/3ATS.dir/main.c.o: CMakeFiles/3ATS.dir/flags.make
CMakeFiles/3ATS.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/3ATS.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/3ATS.dir/main.c.o   -c "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/main.c"

CMakeFiles/3ATS.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/3ATS.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/main.c" > CMakeFiles/3ATS.dir/main.c.i

CMakeFiles/3ATS.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/3ATS.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/main.c" -o CMakeFiles/3ATS.dir/main.c.s

CMakeFiles/3ATS.dir/main.c.o.requires:

.PHONY : CMakeFiles/3ATS.dir/main.c.o.requires

CMakeFiles/3ATS.dir/main.c.o.provides: CMakeFiles/3ATS.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/3ATS.dir/build.make CMakeFiles/3ATS.dir/main.c.o.provides.build
.PHONY : CMakeFiles/3ATS.dir/main.c.o.provides

CMakeFiles/3ATS.dir/main.c.o.provides.build: CMakeFiles/3ATS.dir/main.c.o


# Object files for target 3ATS
3ATS_OBJECTS = \
"CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o" \
"CMakeFiles/3ATS.dir/BigInt.c.o" \
"CMakeFiles/3ATS.dir/main.c.o"

# External object files for target 3ATS
3ATS_EXTERNAL_OBJECTS =

3ATS.exe: CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o
3ATS.exe: CMakeFiles/3ATS.dir/BigInt.c.o
3ATS.exe: CMakeFiles/3ATS.dir/main.c.o
3ATS.exe: CMakeFiles/3ATS.dir/build.make
3ATS.exe: CMakeFiles/3ATS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable 3ATS.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/3ATS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3ATS.dir/build: 3ATS.exe

.PHONY : CMakeFiles/3ATS.dir/build

CMakeFiles/3ATS.dir/requires: CMakeFiles/3ATS.dir/ADS_pirmas1.1.c.o.requires
CMakeFiles/3ATS.dir/requires: CMakeFiles/3ATS.dir/BigInt.c.o.requires
CMakeFiles/3ATS.dir/requires: CMakeFiles/3ATS.dir/main.c.o.requires

.PHONY : CMakeFiles/3ATS.dir/requires

CMakeFiles/3ATS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/3ATS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/3ATS.dir/clean

CMakeFiles/3ATS.dir/depend:
	cd "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS" "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS" "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/cmake-build-debug" "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/cmake-build-debug" "/cygdrive/c/Users/Povilas/Documents/VU/1 KURSAS/2 SEMESTRAS/ADS/PRAKTIKA/3ATS/cmake-build-debug/CMakeFiles/3ATS.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/3ATS.dir/depend

