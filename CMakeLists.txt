cmake_minimum_required(VERSION 2.8)
project(beepiano)

set(CMAKE_CXX_STANDARD 11)

add_executable(beepiano main.cpp src/Beepiano.cpp include/Beepiano.h src/Keyboard.cpp include/Keyboard.h src/Recorder.cpp include/Recorder.h src/Recording.cpp include/Recording.h src/Note.cpp include/Note.h src/Menu.cpp include/Menu.h src/Rest.cpp include/Rest.h include/Utilities.h)