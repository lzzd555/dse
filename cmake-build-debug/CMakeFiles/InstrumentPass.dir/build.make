# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/lzzd/clion-2020.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lzzd/clion-2020.3.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lzzd/dse

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lzzd/dse/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/InstrumentPass.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/InstrumentPass.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/InstrumentPass.dir/flags.make

CMakeFiles/InstrumentPass.dir/src/Instrument.cpp.o: CMakeFiles/InstrumentPass.dir/flags.make
CMakeFiles/InstrumentPass.dir/src/Instrument.cpp.o: ../src/Instrument.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lzzd/dse/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/InstrumentPass.dir/src/Instrument.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/InstrumentPass.dir/src/Instrument.cpp.o -c /home/lzzd/dse/src/Instrument.cpp

CMakeFiles/InstrumentPass.dir/src/Instrument.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/InstrumentPass.dir/src/Instrument.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lzzd/dse/src/Instrument.cpp > CMakeFiles/InstrumentPass.dir/src/Instrument.cpp.i

CMakeFiles/InstrumentPass.dir/src/Instrument.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/InstrumentPass.dir/src/Instrument.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lzzd/dse/src/Instrument.cpp -o CMakeFiles/InstrumentPass.dir/src/Instrument.cpp.s

# Object files for target InstrumentPass
InstrumentPass_OBJECTS = \
"CMakeFiles/InstrumentPass.dir/src/Instrument.cpp.o"

# External object files for target InstrumentPass
InstrumentPass_EXTERNAL_OBJECTS =

InstrumentPass.so: CMakeFiles/InstrumentPass.dir/src/Instrument.cpp.o
InstrumentPass.so: CMakeFiles/InstrumentPass.dir/build.make
InstrumentPass.so: CMakeFiles/InstrumentPass.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lzzd/dse/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module InstrumentPass.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/InstrumentPass.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/InstrumentPass.dir/build: InstrumentPass.so

.PHONY : CMakeFiles/InstrumentPass.dir/build

CMakeFiles/InstrumentPass.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/InstrumentPass.dir/cmake_clean.cmake
.PHONY : CMakeFiles/InstrumentPass.dir/clean

CMakeFiles/InstrumentPass.dir/depend:
	cd /home/lzzd/dse/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lzzd/dse /home/lzzd/dse /home/lzzd/dse/cmake-build-debug /home/lzzd/dse/cmake-build-debug /home/lzzd/dse/cmake-build-debug/CMakeFiles/InstrumentPass.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/InstrumentPass.dir/depend

