# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = E:\Environment\cmake-3.25.0-rc3-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = E:\Environment\cmake-3.25.0-rc3-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Data\Work\Job\Cpp\network_protocol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Data\Work\Job\Cpp\network_protocol\build

# Include any dependencies generated for this target.
include CMakeFiles/network_protocol_stack_cpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/network_protocol_stack_cpp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/network_protocol_stack_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/network_protocol_stack_cpp.dir/flags.make

CMakeFiles/network_protocol_stack_cpp.dir/lib/xnet/pcap_device.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/flags.make
CMakeFiles/network_protocol_stack_cpp.dir/lib/xnet/pcap_device.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/includes_CXX.rsp
CMakeFiles/network_protocol_stack_cpp.dir/lib/xnet/pcap_device.cpp.obj: E:/Data/Work/Job/Cpp/network_protocol/lib/xnet/pcap_device.cpp
CMakeFiles/network_protocol_stack_cpp.dir/lib/xnet/pcap_device.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Data\Work\Job\Cpp\network_protocol\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/network_protocol_stack_cpp.dir/lib/xnet/pcap_device.cpp.obj"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/network_protocol_stack_cpp.dir/lib/xnet/pcap_device.cpp.obj -MF CMakeFiles\network_protocol_stack_cpp.dir\lib\xnet\pcap_device.cpp.obj.d -o CMakeFiles\network_protocol_stack_cpp.dir\lib\xnet\pcap_device.cpp.obj -c E:\Data\Work\Job\Cpp\network_protocol\lib\xnet\pcap_device.cpp

CMakeFiles/network_protocol_stack_cpp.dir/lib/xnet/pcap_device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network_protocol_stack_cpp.dir/lib/xnet/pcap_device.cpp.i"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Data\Work\Job\Cpp\network_protocol\lib\xnet\pcap_device.cpp > CMakeFiles\network_protocol_stack_cpp.dir\lib\xnet\pcap_device.cpp.i

CMakeFiles/network_protocol_stack_cpp.dir/lib/xnet/pcap_device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network_protocol_stack_cpp.dir/lib/xnet/pcap_device.cpp.s"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Data\Work\Job\Cpp\network_protocol\lib\xnet\pcap_device.cpp -o CMakeFiles\network_protocol_stack_cpp.dir\lib\xnet\pcap_device.cpp.s

CMakeFiles/network_protocol_stack_cpp.dir/src/app/port_pcap.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/flags.make
CMakeFiles/network_protocol_stack_cpp.dir/src/app/port_pcap.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/includes_CXX.rsp
CMakeFiles/network_protocol_stack_cpp.dir/src/app/port_pcap.cpp.obj: E:/Data/Work/Job/Cpp/network_protocol/src/app/port_pcap.cpp
CMakeFiles/network_protocol_stack_cpp.dir/src/app/port_pcap.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Data\Work\Job\Cpp\network_protocol\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/network_protocol_stack_cpp.dir/src/app/port_pcap.cpp.obj"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/network_protocol_stack_cpp.dir/src/app/port_pcap.cpp.obj -MF CMakeFiles\network_protocol_stack_cpp.dir\src\app\port_pcap.cpp.obj.d -o CMakeFiles\network_protocol_stack_cpp.dir\src\app\port_pcap.cpp.obj -c E:\Data\Work\Job\Cpp\network_protocol\src\app\port_pcap.cpp

CMakeFiles/network_protocol_stack_cpp.dir/src/app/port_pcap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network_protocol_stack_cpp.dir/src/app/port_pcap.cpp.i"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Data\Work\Job\Cpp\network_protocol\src\app\port_pcap.cpp > CMakeFiles\network_protocol_stack_cpp.dir\src\app\port_pcap.cpp.i

CMakeFiles/network_protocol_stack_cpp.dir/src/app/port_pcap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network_protocol_stack_cpp.dir/src/app/port_pcap.cpp.s"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Data\Work\Job\Cpp\network_protocol\src\app\port_pcap.cpp -o CMakeFiles\network_protocol_stack_cpp.dir\src\app\port_pcap.cpp.s

CMakeFiles/network_protocol_stack_cpp.dir/src/network/xnet_tiny.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/flags.make
CMakeFiles/network_protocol_stack_cpp.dir/src/network/xnet_tiny.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/includes_CXX.rsp
CMakeFiles/network_protocol_stack_cpp.dir/src/network/xnet_tiny.cpp.obj: E:/Data/Work/Job/Cpp/network_protocol/src/network/xnet_tiny.cpp
CMakeFiles/network_protocol_stack_cpp.dir/src/network/xnet_tiny.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Data\Work\Job\Cpp\network_protocol\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/network_protocol_stack_cpp.dir/src/network/xnet_tiny.cpp.obj"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/network_protocol_stack_cpp.dir/src/network/xnet_tiny.cpp.obj -MF CMakeFiles\network_protocol_stack_cpp.dir\src\network\xnet_tiny.cpp.obj.d -o CMakeFiles\network_protocol_stack_cpp.dir\src\network\xnet_tiny.cpp.obj -c E:\Data\Work\Job\Cpp\network_protocol\src\network\xnet_tiny.cpp

CMakeFiles/network_protocol_stack_cpp.dir/src/network/xnet_tiny.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network_protocol_stack_cpp.dir/src/network/xnet_tiny.cpp.i"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Data\Work\Job\Cpp\network_protocol\src\network\xnet_tiny.cpp > CMakeFiles\network_protocol_stack_cpp.dir\src\network\xnet_tiny.cpp.i

CMakeFiles/network_protocol_stack_cpp.dir/src/network/xnet_tiny.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network_protocol_stack_cpp.dir/src/network/xnet_tiny.cpp.s"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Data\Work\Job\Cpp\network_protocol\src\network\xnet_tiny.cpp -o CMakeFiles\network_protocol_stack_cpp.dir\src\network\xnet_tiny.cpp.s

CMakeFiles/network_protocol_stack_cpp.dir/src/network/Hello.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/flags.make
CMakeFiles/network_protocol_stack_cpp.dir/src/network/Hello.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/includes_CXX.rsp
CMakeFiles/network_protocol_stack_cpp.dir/src/network/Hello.cpp.obj: E:/Data/Work/Job/Cpp/network_protocol/src/network/Hello.cpp
CMakeFiles/network_protocol_stack_cpp.dir/src/network/Hello.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Data\Work\Job\Cpp\network_protocol\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/network_protocol_stack_cpp.dir/src/network/Hello.cpp.obj"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/network_protocol_stack_cpp.dir/src/network/Hello.cpp.obj -MF CMakeFiles\network_protocol_stack_cpp.dir\src\network\Hello.cpp.obj.d -o CMakeFiles\network_protocol_stack_cpp.dir\src\network\Hello.cpp.obj -c E:\Data\Work\Job\Cpp\network_protocol\src\network\Hello.cpp

CMakeFiles/network_protocol_stack_cpp.dir/src/network/Hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network_protocol_stack_cpp.dir/src/network/Hello.cpp.i"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Data\Work\Job\Cpp\network_protocol\src\network\Hello.cpp > CMakeFiles\network_protocol_stack_cpp.dir\src\network\Hello.cpp.i

CMakeFiles/network_protocol_stack_cpp.dir/src/network/Hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network_protocol_stack_cpp.dir/src/network/Hello.cpp.s"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Data\Work\Job\Cpp\network_protocol\src\network\Hello.cpp -o CMakeFiles\network_protocol_stack_cpp.dir\src\network\Hello.cpp.s

CMakeFiles/network_protocol_stack_cpp.dir/src/main.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/flags.make
CMakeFiles/network_protocol_stack_cpp.dir/src/main.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/includes_CXX.rsp
CMakeFiles/network_protocol_stack_cpp.dir/src/main.cpp.obj: E:/Data/Work/Job/Cpp/network_protocol/src/main.cpp
CMakeFiles/network_protocol_stack_cpp.dir/src/main.cpp.obj: CMakeFiles/network_protocol_stack_cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Data\Work\Job\Cpp\network_protocol\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/network_protocol_stack_cpp.dir/src/main.cpp.obj"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/network_protocol_stack_cpp.dir/src/main.cpp.obj -MF CMakeFiles\network_protocol_stack_cpp.dir\src\main.cpp.obj.d -o CMakeFiles\network_protocol_stack_cpp.dir\src\main.cpp.obj -c E:\Data\Work\Job\Cpp\network_protocol\src\main.cpp

CMakeFiles/network_protocol_stack_cpp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/network_protocol_stack_cpp.dir/src/main.cpp.i"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Data\Work\Job\Cpp\network_protocol\src\main.cpp > CMakeFiles\network_protocol_stack_cpp.dir\src\main.cpp.i

CMakeFiles/network_protocol_stack_cpp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/network_protocol_stack_cpp.dir/src/main.cpp.s"
	E:\Environment\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Data\Work\Job\Cpp\network_protocol\src\main.cpp -o CMakeFiles\network_protocol_stack_cpp.dir\src\main.cpp.s

# Object files for target network_protocol_stack_cpp
network_protocol_stack_cpp_OBJECTS = \
"CMakeFiles/network_protocol_stack_cpp.dir/lib/xnet/pcap_device.cpp.obj" \
"CMakeFiles/network_protocol_stack_cpp.dir/src/app/port_pcap.cpp.obj" \
"CMakeFiles/network_protocol_stack_cpp.dir/src/network/xnet_tiny.cpp.obj" \
"CMakeFiles/network_protocol_stack_cpp.dir/src/network/Hello.cpp.obj" \
"CMakeFiles/network_protocol_stack_cpp.dir/src/main.cpp.obj"

# External object files for target network_protocol_stack_cpp
network_protocol_stack_cpp_EXTERNAL_OBJECTS =

network_protocol_stack_cpp.exe: CMakeFiles/network_protocol_stack_cpp.dir/lib/xnet/pcap_device.cpp.obj
network_protocol_stack_cpp.exe: CMakeFiles/network_protocol_stack_cpp.dir/src/app/port_pcap.cpp.obj
network_protocol_stack_cpp.exe: CMakeFiles/network_protocol_stack_cpp.dir/src/network/xnet_tiny.cpp.obj
network_protocol_stack_cpp.exe: CMakeFiles/network_protocol_stack_cpp.dir/src/network/Hello.cpp.obj
network_protocol_stack_cpp.exe: CMakeFiles/network_protocol_stack_cpp.dir/src/main.cpp.obj
network_protocol_stack_cpp.exe: CMakeFiles/network_protocol_stack_cpp.dir/build.make
network_protocol_stack_cpp.exe: E:/Data/Work/Job/Cpp/network_protocol/lib/libws2_32.a
network_protocol_stack_cpp.exe: E:/Data/Work/Job/Cpp/network_protocol/lib/npcap/Lib/x64/Packet.lib
network_protocol_stack_cpp.exe: E:/Data/Work/Job/Cpp/network_protocol/lib/npcap/Lib/x64/wpcap.lib
network_protocol_stack_cpp.exe: CMakeFiles/network_protocol_stack_cpp.dir/linkLibs.rsp
network_protocol_stack_cpp.exe: CMakeFiles/network_protocol_stack_cpp.dir/objects1
network_protocol_stack_cpp.exe: CMakeFiles/network_protocol_stack_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Data\Work\Job\Cpp\network_protocol\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable network_protocol_stack_cpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\network_protocol_stack_cpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/network_protocol_stack_cpp.dir/build: network_protocol_stack_cpp.exe
.PHONY : CMakeFiles/network_protocol_stack_cpp.dir/build

CMakeFiles/network_protocol_stack_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\network_protocol_stack_cpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/network_protocol_stack_cpp.dir/clean

CMakeFiles/network_protocol_stack_cpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Data\Work\Job\Cpp\network_protocol E:\Data\Work\Job\Cpp\network_protocol E:\Data\Work\Job\Cpp\network_protocol\build E:\Data\Work\Job\Cpp\network_protocol\build E:\Data\Work\Job\Cpp\network_protocol\build\CMakeFiles\network_protocol_stack_cpp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/network_protocol_stack_cpp.dir/depend
