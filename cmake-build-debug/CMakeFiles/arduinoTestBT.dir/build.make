# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/mrbueno/dev/CLion-2018.2.5/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/mrbueno/dev/CLion-2018.2.5/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mrbueno/code/arduinoTestBT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mrbueno/code/arduinoTestBT/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/arduinoTestBT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/arduinoTestBT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arduinoTestBT.dir/flags.make

CMakeFiles/arduinoTestBT.dir/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp.o: CMakeFiles/arduinoTestBT.dir/flags.make
CMakeFiles/arduinoTestBT.dir/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp.o: ../lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrbueno/code/arduinoTestBT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/arduinoTestBT.dir/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp.o"
	/home/mrbueno/.platformio/packages/toolchain-atmelavr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arduinoTestBT.dir/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp.o -c /home/mrbueno/code/arduinoTestBT/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp

CMakeFiles/arduinoTestBT.dir/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arduinoTestBT.dir/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp.i"
	/home/mrbueno/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrbueno/code/arduinoTestBT/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp > CMakeFiles/arduinoTestBT.dir/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp.i

CMakeFiles/arduinoTestBT.dir/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arduinoTestBT.dir/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp.s"
	/home/mrbueno/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrbueno/code/arduinoTestBT/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp -o CMakeFiles/arduinoTestBT.dir/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp.s

CMakeFiles/arduinoTestBT.dir/src/Main.cpp.o: CMakeFiles/arduinoTestBT.dir/flags.make
CMakeFiles/arduinoTestBT.dir/src/Main.cpp.o: ../src/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrbueno/code/arduinoTestBT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/arduinoTestBT.dir/src/Main.cpp.o"
	/home/mrbueno/.platformio/packages/toolchain-atmelavr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arduinoTestBT.dir/src/Main.cpp.o -c /home/mrbueno/code/arduinoTestBT/src/Main.cpp

CMakeFiles/arduinoTestBT.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arduinoTestBT.dir/src/Main.cpp.i"
	/home/mrbueno/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrbueno/code/arduinoTestBT/src/Main.cpp > CMakeFiles/arduinoTestBT.dir/src/Main.cpp.i

CMakeFiles/arduinoTestBT.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arduinoTestBT.dir/src/Main.cpp.s"
	/home/mrbueno/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrbueno/code/arduinoTestBT/src/Main.cpp -o CMakeFiles/arduinoTestBT.dir/src/Main.cpp.s

# Object files for target arduinoTestBT
arduinoTestBT_OBJECTS = \
"CMakeFiles/arduinoTestBT.dir/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp.o" \
"CMakeFiles/arduinoTestBT.dir/src/Main.cpp.o"

# External object files for target arduinoTestBT
arduinoTestBT_EXTERNAL_OBJECTS =

arduinoTestBT: CMakeFiles/arduinoTestBT.dir/lib/PinChangeInt/Examples/ByteBuffer/ByteBuffer.cpp.o
arduinoTestBT: CMakeFiles/arduinoTestBT.dir/src/Main.cpp.o
arduinoTestBT: CMakeFiles/arduinoTestBT.dir/build.make
arduinoTestBT: CMakeFiles/arduinoTestBT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mrbueno/code/arduinoTestBT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable arduinoTestBT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arduinoTestBT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arduinoTestBT.dir/build: arduinoTestBT

.PHONY : CMakeFiles/arduinoTestBT.dir/build

CMakeFiles/arduinoTestBT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/arduinoTestBT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/arduinoTestBT.dir/clean

CMakeFiles/arduinoTestBT.dir/depend:
	cd /home/mrbueno/code/arduinoTestBT/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mrbueno/code/arduinoTestBT /home/mrbueno/code/arduinoTestBT /home/mrbueno/code/arduinoTestBT/cmake-build-debug /home/mrbueno/code/arduinoTestBT/cmake-build-debug /home/mrbueno/code/arduinoTestBT/cmake-build-debug/CMakeFiles/arduinoTestBT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arduinoTestBT.dir/depend

