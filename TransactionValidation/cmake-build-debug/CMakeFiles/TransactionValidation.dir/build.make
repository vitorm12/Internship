# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /private/var/folders/0k/hn75c3fs78zgrst1p71d7t5w0000gn/T/AppTranslocation/C89FB12F-C856-467A-ACC1-4E84AB92E867/d/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /private/var/folders/0k/hn75c3fs78zgrst1p71d7t5w0000gn/T/AppTranslocation/C89FB12F-C856-467A-ACC1-4E84AB92E867/d/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vitormouzinho/CLionProjects/TransactionValidation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vitormouzinho/CLionProjects/TransactionValidation/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TransactionValidation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TransactionValidation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TransactionValidation.dir/flags.make

CMakeFiles/TransactionValidation.dir/main.cpp.o: CMakeFiles/TransactionValidation.dir/flags.make
CMakeFiles/TransactionValidation.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vitormouzinho/CLionProjects/TransactionValidation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TransactionValidation.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TransactionValidation.dir/main.cpp.o -c /Users/vitormouzinho/CLionProjects/TransactionValidation/main.cpp

CMakeFiles/TransactionValidation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TransactionValidation.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vitormouzinho/CLionProjects/TransactionValidation/main.cpp > CMakeFiles/TransactionValidation.dir/main.cpp.i

CMakeFiles/TransactionValidation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TransactionValidation.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vitormouzinho/CLionProjects/TransactionValidation/main.cpp -o CMakeFiles/TransactionValidation.dir/main.cpp.s

CMakeFiles/TransactionValidation.dir/Sender.cpp.o: CMakeFiles/TransactionValidation.dir/flags.make
CMakeFiles/TransactionValidation.dir/Sender.cpp.o: ../Sender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vitormouzinho/CLionProjects/TransactionValidation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TransactionValidation.dir/Sender.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TransactionValidation.dir/Sender.cpp.o -c /Users/vitormouzinho/CLionProjects/TransactionValidation/Sender.cpp

CMakeFiles/TransactionValidation.dir/Sender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TransactionValidation.dir/Sender.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vitormouzinho/CLionProjects/TransactionValidation/Sender.cpp > CMakeFiles/TransactionValidation.dir/Sender.cpp.i

CMakeFiles/TransactionValidation.dir/Sender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TransactionValidation.dir/Sender.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vitormouzinho/CLionProjects/TransactionValidation/Sender.cpp -o CMakeFiles/TransactionValidation.dir/Sender.cpp.s

# Object files for target TransactionValidation
TransactionValidation_OBJECTS = \
"CMakeFiles/TransactionValidation.dir/main.cpp.o" \
"CMakeFiles/TransactionValidation.dir/Sender.cpp.o"

# External object files for target TransactionValidation
TransactionValidation_EXTERNAL_OBJECTS =

TransactionValidation: CMakeFiles/TransactionValidation.dir/main.cpp.o
TransactionValidation: CMakeFiles/TransactionValidation.dir/Sender.cpp.o
TransactionValidation: CMakeFiles/TransactionValidation.dir/build.make
TransactionValidation: CMakeFiles/TransactionValidation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vitormouzinho/CLionProjects/TransactionValidation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TransactionValidation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TransactionValidation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TransactionValidation.dir/build: TransactionValidation

.PHONY : CMakeFiles/TransactionValidation.dir/build

CMakeFiles/TransactionValidation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TransactionValidation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TransactionValidation.dir/clean

CMakeFiles/TransactionValidation.dir/depend:
	cd /Users/vitormouzinho/CLionProjects/TransactionValidation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vitormouzinho/CLionProjects/TransactionValidation /Users/vitormouzinho/CLionProjects/TransactionValidation /Users/vitormouzinho/CLionProjects/TransactionValidation/cmake-build-debug /Users/vitormouzinho/CLionProjects/TransactionValidation/cmake-build-debug /Users/vitormouzinho/CLionProjects/TransactionValidation/cmake-build-debug/CMakeFiles/TransactionValidation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TransactionValidation.dir/depend

