# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kusneid\Documents\MusicPlayer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kusneid\Documents\MusicPlayer\build

# Include any dependencies generated for this target.
include CMakeFiles/MusicPlayer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MusicPlayer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MusicPlayer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MusicPlayer.dir/flags.make

CMakeFiles/MusicPlayer.dir/src/decoding/album.cpp.obj: CMakeFiles/MusicPlayer.dir/flags.make
CMakeFiles/MusicPlayer.dir/src/decoding/album.cpp.obj: CMakeFiles/MusicPlayer.dir/includes_CXX.rsp
CMakeFiles/MusicPlayer.dir/src/decoding/album.cpp.obj: C:/Users/kusneid/Documents/MusicPlayer/src/decoding/album.cpp
CMakeFiles/MusicPlayer.dir/src/decoding/album.cpp.obj: CMakeFiles/MusicPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\kusneid\Documents\MusicPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MusicPlayer.dir/src/decoding/album.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MusicPlayer.dir/src/decoding/album.cpp.obj -MF CMakeFiles\MusicPlayer.dir\src\decoding\album.cpp.obj.d -o CMakeFiles\MusicPlayer.dir\src\decoding\album.cpp.obj -c C:\Users\kusneid\Documents\MusicPlayer\src\decoding\album.cpp

CMakeFiles/MusicPlayer.dir/src/decoding/album.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MusicPlayer.dir/src/decoding/album.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kusneid\Documents\MusicPlayer\src\decoding\album.cpp > CMakeFiles\MusicPlayer.dir\src\decoding\album.cpp.i

CMakeFiles/MusicPlayer.dir/src/decoding/album.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MusicPlayer.dir/src/decoding/album.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kusneid\Documents\MusicPlayer\src\decoding\album.cpp -o CMakeFiles\MusicPlayer.dir\src\decoding\album.cpp.s

CMakeFiles/MusicPlayer.dir/src/decoding/artist.cpp.obj: CMakeFiles/MusicPlayer.dir/flags.make
CMakeFiles/MusicPlayer.dir/src/decoding/artist.cpp.obj: CMakeFiles/MusicPlayer.dir/includes_CXX.rsp
CMakeFiles/MusicPlayer.dir/src/decoding/artist.cpp.obj: C:/Users/kusneid/Documents/MusicPlayer/src/decoding/artist.cpp
CMakeFiles/MusicPlayer.dir/src/decoding/artist.cpp.obj: CMakeFiles/MusicPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\kusneid\Documents\MusicPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MusicPlayer.dir/src/decoding/artist.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MusicPlayer.dir/src/decoding/artist.cpp.obj -MF CMakeFiles\MusicPlayer.dir\src\decoding\artist.cpp.obj.d -o CMakeFiles\MusicPlayer.dir\src\decoding\artist.cpp.obj -c C:\Users\kusneid\Documents\MusicPlayer\src\decoding\artist.cpp

CMakeFiles/MusicPlayer.dir/src/decoding/artist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MusicPlayer.dir/src/decoding/artist.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kusneid\Documents\MusicPlayer\src\decoding\artist.cpp > CMakeFiles\MusicPlayer.dir\src\decoding\artist.cpp.i

CMakeFiles/MusicPlayer.dir/src/decoding/artist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MusicPlayer.dir/src/decoding/artist.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kusneid\Documents\MusicPlayer\src\decoding\artist.cpp -o CMakeFiles\MusicPlayer.dir\src\decoding\artist.cpp.s

CMakeFiles/MusicPlayer.dir/src/decoding/decoding.cpp.obj: CMakeFiles/MusicPlayer.dir/flags.make
CMakeFiles/MusicPlayer.dir/src/decoding/decoding.cpp.obj: CMakeFiles/MusicPlayer.dir/includes_CXX.rsp
CMakeFiles/MusicPlayer.dir/src/decoding/decoding.cpp.obj: C:/Users/kusneid/Documents/MusicPlayer/src/decoding/decoding.cpp
CMakeFiles/MusicPlayer.dir/src/decoding/decoding.cpp.obj: CMakeFiles/MusicPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\kusneid\Documents\MusicPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MusicPlayer.dir/src/decoding/decoding.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MusicPlayer.dir/src/decoding/decoding.cpp.obj -MF CMakeFiles\MusicPlayer.dir\src\decoding\decoding.cpp.obj.d -o CMakeFiles\MusicPlayer.dir\src\decoding\decoding.cpp.obj -c C:\Users\kusneid\Documents\MusicPlayer\src\decoding\decoding.cpp

CMakeFiles/MusicPlayer.dir/src/decoding/decoding.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MusicPlayer.dir/src/decoding/decoding.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kusneid\Documents\MusicPlayer\src\decoding\decoding.cpp > CMakeFiles\MusicPlayer.dir\src\decoding\decoding.cpp.i

CMakeFiles/MusicPlayer.dir/src/decoding/decoding.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MusicPlayer.dir/src/decoding/decoding.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kusneid\Documents\MusicPlayer\src\decoding\decoding.cpp -o CMakeFiles\MusicPlayer.dir\src\decoding\decoding.cpp.s

CMakeFiles/MusicPlayer.dir/src/decoding/song.cpp.obj: CMakeFiles/MusicPlayer.dir/flags.make
CMakeFiles/MusicPlayer.dir/src/decoding/song.cpp.obj: CMakeFiles/MusicPlayer.dir/includes_CXX.rsp
CMakeFiles/MusicPlayer.dir/src/decoding/song.cpp.obj: C:/Users/kusneid/Documents/MusicPlayer/src/decoding/song.cpp
CMakeFiles/MusicPlayer.dir/src/decoding/song.cpp.obj: CMakeFiles/MusicPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\kusneid\Documents\MusicPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MusicPlayer.dir/src/decoding/song.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MusicPlayer.dir/src/decoding/song.cpp.obj -MF CMakeFiles\MusicPlayer.dir\src\decoding\song.cpp.obj.d -o CMakeFiles\MusicPlayer.dir\src\decoding\song.cpp.obj -c C:\Users\kusneid\Documents\MusicPlayer\src\decoding\song.cpp

CMakeFiles/MusicPlayer.dir/src/decoding/song.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MusicPlayer.dir/src/decoding/song.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kusneid\Documents\MusicPlayer\src\decoding\song.cpp > CMakeFiles\MusicPlayer.dir\src\decoding\song.cpp.i

CMakeFiles/MusicPlayer.dir/src/decoding/song.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MusicPlayer.dir/src/decoding/song.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kusneid\Documents\MusicPlayer\src\decoding\song.cpp -o CMakeFiles\MusicPlayer.dir\src\decoding\song.cpp.s

CMakeFiles/MusicPlayer.dir/src/main.cpp.obj: CMakeFiles/MusicPlayer.dir/flags.make
CMakeFiles/MusicPlayer.dir/src/main.cpp.obj: CMakeFiles/MusicPlayer.dir/includes_CXX.rsp
CMakeFiles/MusicPlayer.dir/src/main.cpp.obj: C:/Users/kusneid/Documents/MusicPlayer/src/main.cpp
CMakeFiles/MusicPlayer.dir/src/main.cpp.obj: CMakeFiles/MusicPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\kusneid\Documents\MusicPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MusicPlayer.dir/src/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MusicPlayer.dir/src/main.cpp.obj -MF CMakeFiles\MusicPlayer.dir\src\main.cpp.obj.d -o CMakeFiles\MusicPlayer.dir\src\main.cpp.obj -c C:\Users\kusneid\Documents\MusicPlayer\src\main.cpp

CMakeFiles/MusicPlayer.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MusicPlayer.dir/src/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kusneid\Documents\MusicPlayer\src\main.cpp > CMakeFiles\MusicPlayer.dir\src\main.cpp.i

CMakeFiles/MusicPlayer.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MusicPlayer.dir/src/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kusneid\Documents\MusicPlayer\src\main.cpp -o CMakeFiles\MusicPlayer.dir\src\main.cpp.s

CMakeFiles/MusicPlayer.dir/src/org/playlist.cpp.obj: CMakeFiles/MusicPlayer.dir/flags.make
CMakeFiles/MusicPlayer.dir/src/org/playlist.cpp.obj: CMakeFiles/MusicPlayer.dir/includes_CXX.rsp
CMakeFiles/MusicPlayer.dir/src/org/playlist.cpp.obj: C:/Users/kusneid/Documents/MusicPlayer/src/org/playlist.cpp
CMakeFiles/MusicPlayer.dir/src/org/playlist.cpp.obj: CMakeFiles/MusicPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\kusneid\Documents\MusicPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MusicPlayer.dir/src/org/playlist.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MusicPlayer.dir/src/org/playlist.cpp.obj -MF CMakeFiles\MusicPlayer.dir\src\org\playlist.cpp.obj.d -o CMakeFiles\MusicPlayer.dir\src\org\playlist.cpp.obj -c C:\Users\kusneid\Documents\MusicPlayer\src\org\playlist.cpp

CMakeFiles/MusicPlayer.dir/src/org/playlist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MusicPlayer.dir/src/org/playlist.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kusneid\Documents\MusicPlayer\src\org\playlist.cpp > CMakeFiles\MusicPlayer.dir\src\org\playlist.cpp.i

CMakeFiles/MusicPlayer.dir/src/org/playlist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MusicPlayer.dir/src/org/playlist.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kusneid\Documents\MusicPlayer\src\org\playlist.cpp -o CMakeFiles\MusicPlayer.dir\src\org\playlist.cpp.s

CMakeFiles/MusicPlayer.dir/src/org/queue.cpp.obj: CMakeFiles/MusicPlayer.dir/flags.make
CMakeFiles/MusicPlayer.dir/src/org/queue.cpp.obj: CMakeFiles/MusicPlayer.dir/includes_CXX.rsp
CMakeFiles/MusicPlayer.dir/src/org/queue.cpp.obj: C:/Users/kusneid/Documents/MusicPlayer/src/org/queue.cpp
CMakeFiles/MusicPlayer.dir/src/org/queue.cpp.obj: CMakeFiles/MusicPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\kusneid\Documents\MusicPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/MusicPlayer.dir/src/org/queue.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MusicPlayer.dir/src/org/queue.cpp.obj -MF CMakeFiles\MusicPlayer.dir\src\org\queue.cpp.obj.d -o CMakeFiles\MusicPlayer.dir\src\org\queue.cpp.obj -c C:\Users\kusneid\Documents\MusicPlayer\src\org\queue.cpp

CMakeFiles/MusicPlayer.dir/src/org/queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MusicPlayer.dir/src/org/queue.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kusneid\Documents\MusicPlayer\src\org\queue.cpp > CMakeFiles\MusicPlayer.dir\src\org\queue.cpp.i

CMakeFiles/MusicPlayer.dir/src/org/queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MusicPlayer.dir/src/org/queue.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kusneid\Documents\MusicPlayer\src\org\queue.cpp -o CMakeFiles\MusicPlayer.dir\src\org\queue.cpp.s

CMakeFiles/MusicPlayer.dir/src/ui/ui.cpp.obj: CMakeFiles/MusicPlayer.dir/flags.make
CMakeFiles/MusicPlayer.dir/src/ui/ui.cpp.obj: CMakeFiles/MusicPlayer.dir/includes_CXX.rsp
CMakeFiles/MusicPlayer.dir/src/ui/ui.cpp.obj: C:/Users/kusneid/Documents/MusicPlayer/src/ui/ui.cpp
CMakeFiles/MusicPlayer.dir/src/ui/ui.cpp.obj: CMakeFiles/MusicPlayer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\kusneid\Documents\MusicPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/MusicPlayer.dir/src/ui/ui.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MusicPlayer.dir/src/ui/ui.cpp.obj -MF CMakeFiles\MusicPlayer.dir\src\ui\ui.cpp.obj.d -o CMakeFiles\MusicPlayer.dir\src\ui\ui.cpp.obj -c C:\Users\kusneid\Documents\MusicPlayer\src\ui\ui.cpp

CMakeFiles/MusicPlayer.dir/src/ui/ui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MusicPlayer.dir/src/ui/ui.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kusneid\Documents\MusicPlayer\src\ui\ui.cpp > CMakeFiles\MusicPlayer.dir\src\ui\ui.cpp.i

CMakeFiles/MusicPlayer.dir/src/ui/ui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MusicPlayer.dir/src/ui/ui.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kusneid\Documents\MusicPlayer\src\ui\ui.cpp -o CMakeFiles\MusicPlayer.dir\src\ui\ui.cpp.s

# Object files for target MusicPlayer
MusicPlayer_OBJECTS = \
"CMakeFiles/MusicPlayer.dir/src/decoding/album.cpp.obj" \
"CMakeFiles/MusicPlayer.dir/src/decoding/artist.cpp.obj" \
"CMakeFiles/MusicPlayer.dir/src/decoding/decoding.cpp.obj" \
"CMakeFiles/MusicPlayer.dir/src/decoding/song.cpp.obj" \
"CMakeFiles/MusicPlayer.dir/src/main.cpp.obj" \
"CMakeFiles/MusicPlayer.dir/src/org/playlist.cpp.obj" \
"CMakeFiles/MusicPlayer.dir/src/org/queue.cpp.obj" \
"CMakeFiles/MusicPlayer.dir/src/ui/ui.cpp.obj"

# External object files for target MusicPlayer
MusicPlayer_EXTERNAL_OBJECTS =

bin/MusicPlayer.exe: CMakeFiles/MusicPlayer.dir/src/decoding/album.cpp.obj
bin/MusicPlayer.exe: CMakeFiles/MusicPlayer.dir/src/decoding/artist.cpp.obj
bin/MusicPlayer.exe: CMakeFiles/MusicPlayer.dir/src/decoding/decoding.cpp.obj
bin/MusicPlayer.exe: CMakeFiles/MusicPlayer.dir/src/decoding/song.cpp.obj
bin/MusicPlayer.exe: CMakeFiles/MusicPlayer.dir/src/main.cpp.obj
bin/MusicPlayer.exe: CMakeFiles/MusicPlayer.dir/src/org/playlist.cpp.obj
bin/MusicPlayer.exe: CMakeFiles/MusicPlayer.dir/src/org/queue.cpp.obj
bin/MusicPlayer.exe: CMakeFiles/MusicPlayer.dir/src/ui/ui.cpp.obj
bin/MusicPlayer.exe: CMakeFiles/MusicPlayer.dir/build.make
bin/MusicPlayer.exe: _deps/sfml-build/lib/libsfml-graphics-s-d.a
bin/MusicPlayer.exe: _deps/sfml-build/lib/libsfml-window-s-d.a
bin/MusicPlayer.exe: _deps/sfml-build/lib/libsfml-system-s-d.a
bin/MusicPlayer.exe: _deps/sfml-src/extlibs/libs-mingw/x64/libfreetype.a
bin/MusicPlayer.exe: CMakeFiles/MusicPlayer.dir/linkLibs.rsp
bin/MusicPlayer.exe: CMakeFiles/MusicPlayer.dir/objects1.rsp
bin/MusicPlayer.exe: CMakeFiles/MusicPlayer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\kusneid\Documents\MusicPlayer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable bin\MusicPlayer.exe"
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Copy OpenAL DLL"
	"C:\Program Files\CMake\bin\cmake.exe" -E copy C:/Users/kusneid/Documents/MusicPlayer/build/_deps/sfml-src/extlibs/bin/x64/openal32.dll C:/Users/kusneid/Documents/MusicPlayer/build/bin
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MusicPlayer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MusicPlayer.dir/build: bin/MusicPlayer.exe
.PHONY : CMakeFiles/MusicPlayer.dir/build

CMakeFiles/MusicPlayer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MusicPlayer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MusicPlayer.dir/clean

CMakeFiles/MusicPlayer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\kusneid\Documents\MusicPlayer C:\Users\kusneid\Documents\MusicPlayer C:\Users\kusneid\Documents\MusicPlayer\build C:\Users\kusneid\Documents\MusicPlayer\build C:\Users\kusneid\Documents\MusicPlayer\build\CMakeFiles\MusicPlayer.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MusicPlayer.dir/depend

