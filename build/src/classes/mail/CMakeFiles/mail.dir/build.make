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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/rafae/uni/ucoactividades

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/rafae/uni/ucoactividades/build

# Include any dependencies generated for this target.
include src/classes/mail/CMakeFiles/mail.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/classes/mail/CMakeFiles/mail.dir/compiler_depend.make

# Include the progress variables for this target.
include src/classes/mail/CMakeFiles/mail.dir/progress.make

# Include the compile flags for this target's objects.
include src/classes/mail/CMakeFiles/mail.dir/flags.make

src/classes/mail/CMakeFiles/mail.dir/mail.cc.o: src/classes/mail/CMakeFiles/mail.dir/flags.make
src/classes/mail/CMakeFiles/mail.dir/mail.cc.o: ../src/classes/mail/mail.cc
src/classes/mail/CMakeFiles/mail.dir/mail.cc.o: src/classes/mail/CMakeFiles/mail.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/rafae/uni/ucoactividades/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/classes/mail/CMakeFiles/mail.dir/mail.cc.o"
	cd /mnt/c/Users/rafae/uni/ucoactividades/build/src/classes/mail && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/classes/mail/CMakeFiles/mail.dir/mail.cc.o -MF CMakeFiles/mail.dir/mail.cc.o.d -o CMakeFiles/mail.dir/mail.cc.o -c /mnt/c/Users/rafae/uni/ucoactividades/src/classes/mail/mail.cc

src/classes/mail/CMakeFiles/mail.dir/mail.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mail.dir/mail.cc.i"
	cd /mnt/c/Users/rafae/uni/ucoactividades/build/src/classes/mail && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/rafae/uni/ucoactividades/src/classes/mail/mail.cc > CMakeFiles/mail.dir/mail.cc.i

src/classes/mail/CMakeFiles/mail.dir/mail.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mail.dir/mail.cc.s"
	cd /mnt/c/Users/rafae/uni/ucoactividades/build/src/classes/mail && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/rafae/uni/ucoactividades/src/classes/mail/mail.cc -o CMakeFiles/mail.dir/mail.cc.s

# Object files for target mail
mail_OBJECTS = \
"CMakeFiles/mail.dir/mail.cc.o"

# External object files for target mail
mail_EXTERNAL_OBJECTS =

src/classes/mail/libmail.a: src/classes/mail/CMakeFiles/mail.dir/mail.cc.o
src/classes/mail/libmail.a: src/classes/mail/CMakeFiles/mail.dir/build.make
src/classes/mail/libmail.a: src/classes/mail/CMakeFiles/mail.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/rafae/uni/ucoactividades/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmail.a"
	cd /mnt/c/Users/rafae/uni/ucoactividades/build/src/classes/mail && $(CMAKE_COMMAND) -P CMakeFiles/mail.dir/cmake_clean_target.cmake
	cd /mnt/c/Users/rafae/uni/ucoactividades/build/src/classes/mail && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mail.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/classes/mail/CMakeFiles/mail.dir/build: src/classes/mail/libmail.a
.PHONY : src/classes/mail/CMakeFiles/mail.dir/build

src/classes/mail/CMakeFiles/mail.dir/clean:
	cd /mnt/c/Users/rafae/uni/ucoactividades/build/src/classes/mail && $(CMAKE_COMMAND) -P CMakeFiles/mail.dir/cmake_clean.cmake
.PHONY : src/classes/mail/CMakeFiles/mail.dir/clean

src/classes/mail/CMakeFiles/mail.dir/depend:
	cd /mnt/c/Users/rafae/uni/ucoactividades/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/rafae/uni/ucoactividades /mnt/c/Users/rafae/uni/ucoactividades/src/classes/mail /mnt/c/Users/rafae/uni/ucoactividades/build /mnt/c/Users/rafae/uni/ucoactividades/build/src/classes/mail /mnt/c/Users/rafae/uni/ucoactividades/build/src/classes/mail/CMakeFiles/mail.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/classes/mail/CMakeFiles/mail.dir/depend
