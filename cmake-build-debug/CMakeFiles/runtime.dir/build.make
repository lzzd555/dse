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
include CMakeFiles/runtime.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/runtime.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runtime.dir/flags.make

CMakeFiles/runtime.dir/src/SymbolicInterpreter.cpp.o: CMakeFiles/runtime.dir/flags.make
CMakeFiles/runtime.dir/src/SymbolicInterpreter.cpp.o: ../src/SymbolicInterpreter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lzzd/dse/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runtime.dir/src/SymbolicInterpreter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runtime.dir/src/SymbolicInterpreter.cpp.o -c /home/lzzd/dse/src/SymbolicInterpreter.cpp

CMakeFiles/runtime.dir/src/SymbolicInterpreter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runtime.dir/src/SymbolicInterpreter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lzzd/dse/src/SymbolicInterpreter.cpp > CMakeFiles/runtime.dir/src/SymbolicInterpreter.cpp.i

CMakeFiles/runtime.dir/src/SymbolicInterpreter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runtime.dir/src/SymbolicInterpreter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lzzd/dse/src/SymbolicInterpreter.cpp -o CMakeFiles/runtime.dir/src/SymbolicInterpreter.cpp.s

CMakeFiles/runtime.dir/src/Runtime.cpp.o: CMakeFiles/runtime.dir/flags.make
CMakeFiles/runtime.dir/src/Runtime.cpp.o: ../src/Runtime.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lzzd/dse/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/runtime.dir/src/Runtime.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runtime.dir/src/Runtime.cpp.o -c /home/lzzd/dse/src/Runtime.cpp

CMakeFiles/runtime.dir/src/Runtime.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runtime.dir/src/Runtime.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lzzd/dse/src/Runtime.cpp > CMakeFiles/runtime.dir/src/Runtime.cpp.i

CMakeFiles/runtime.dir/src/Runtime.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runtime.dir/src/Runtime.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lzzd/dse/src/Runtime.cpp -o CMakeFiles/runtime.dir/src/Runtime.cpp.s

# Object files for target runtime
runtime_OBJECTS = \
"CMakeFiles/runtime.dir/src/SymbolicInterpreter.cpp.o" \
"CMakeFiles/runtime.dir/src/Runtime.cpp.o"

# External object files for target runtime
runtime_EXTERNAL_OBJECTS =

libruntime.so: CMakeFiles/runtime.dir/src/SymbolicInterpreter.cpp.o
libruntime.so: CMakeFiles/runtime.dir/src/Runtime.cpp.o
libruntime.so: CMakeFiles/runtime.dir/build.make
libruntime.so: /usr/local/lib/libLLVMSupport.a
libruntime.so: /usr/local/lib/libLLVMCore.a
libruntime.so: /usr/local/lib/libLLVMIRReader.a
libruntime.so: /usr/lib/libz3.so
libruntime.so: /usr/local/lib/libLLVMAsmParser.a
libruntime.so: /usr/local/lib/libLLVMBitReader.a
libruntime.so: /usr/local/lib/libLLVMCore.a
libruntime.so: /usr/local/lib/libLLVMBinaryFormat.a
libruntime.so: /usr/local/lib/libLLVMSupport.a
libruntime.so: /usr/local/lib/libLLVMDemangle.a
libruntime.so: CMakeFiles/runtime.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lzzd/dse/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared module libruntime.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runtime.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runtime.dir/build: libruntime.so

.PHONY : CMakeFiles/runtime.dir/build

CMakeFiles/runtime.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runtime.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runtime.dir/clean

CMakeFiles/runtime.dir/depend:
	cd /home/lzzd/dse/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lzzd/dse /home/lzzd/dse /home/lzzd/dse/cmake-build-debug /home/lzzd/dse/cmake-build-debug /home/lzzd/dse/cmake-build-debug/CMakeFiles/runtime.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runtime.dir/depend
