# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ice/workspace/ClionProjects/boost-xp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ice/workspace/ClionProjects/boost-xp/build

# Include any dependencies generated for this target.
include CMakeFiles/boost_xp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/boost_xp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boost_xp.dir/flags.make

CMakeFiles/boost_xp.dir/main.cpp.o: CMakeFiles/boost_xp.dir/flags.make
CMakeFiles/boost_xp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ice/workspace/ClionProjects/boost-xp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/boost_xp.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boost_xp.dir/main.cpp.o -c /Users/ice/workspace/ClionProjects/boost-xp/main.cpp

CMakeFiles/boost_xp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_xp.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ice/workspace/ClionProjects/boost-xp/main.cpp > CMakeFiles/boost_xp.dir/main.cpp.i

CMakeFiles/boost_xp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_xp.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ice/workspace/ClionProjects/boost-xp/main.cpp -o CMakeFiles/boost_xp.dir/main.cpp.s

CMakeFiles/boost_xp.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/boost_xp.dir/main.cpp.o.requires

CMakeFiles/boost_xp.dir/main.cpp.o.provides: CMakeFiles/boost_xp.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/boost_xp.dir/build.make CMakeFiles/boost_xp.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/boost_xp.dir/main.cpp.o.provides

CMakeFiles/boost_xp.dir/main.cpp.o.provides.build: CMakeFiles/boost_xp.dir/main.cpp.o


# Object files for target boost_xp
boost_xp_OBJECTS = \
"CMakeFiles/boost_xp.dir/main.cpp.o"

# External object files for target boost_xp
boost_xp_EXTERNAL_OBJECTS =

boost_xp: CMakeFiles/boost_xp.dir/main.cpp.o
boost_xp: CMakeFiles/boost_xp.dir/build.make
boost_xp: /usr/local/lib/libboost_log.dylib
boost_xp: /usr/local/lib/libboost_system.dylib
boost_xp: /usr/local/lib/libboost_thread.dylib
boost_xp: /usr/local/lib/libboost_filesystem.dylib
boost_xp: /usr/local/lib/libboost_signals.dylib
boost_xp: /usr/local/lib/libboost_date_time.dylib
boost_xp: /usr/local/lib/libboost_log_setup.dylib
boost_xp: /usr/local/lib/libboost_regex.dylib
boost_xp: /usr/local/lib/libboost_chrono.dylib
boost_xp: /usr/local/lib/libboost_atomic.dylib
boost_xp: CMakeFiles/boost_xp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ice/workspace/ClionProjects/boost-xp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable boost_xp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boost_xp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/boost_xp.dir/build: boost_xp

.PHONY : CMakeFiles/boost_xp.dir/build

CMakeFiles/boost_xp.dir/requires: CMakeFiles/boost_xp.dir/main.cpp.o.requires

.PHONY : CMakeFiles/boost_xp.dir/requires

CMakeFiles/boost_xp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/boost_xp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/boost_xp.dir/clean

CMakeFiles/boost_xp.dir/depend:
	cd /Users/ice/workspace/ClionProjects/boost-xp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ice/workspace/ClionProjects/boost-xp /Users/ice/workspace/ClionProjects/boost-xp /Users/ice/workspace/ClionProjects/boost-xp/build /Users/ice/workspace/ClionProjects/boost-xp/build /Users/ice/workspace/ClionProjects/boost-xp/build/CMakeFiles/boost_xp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/boost_xp.dir/depend

