cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME Final_Fantasy_SFML)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp SpriteName.h Sprite.cpp Sprite.h Animation.cpp Animation.h Game.cpp Game.h StatesEnum.h States.cpp States.h UserControlEnum.h AnimationTest.cpp AnimationTest.h Player.cpp Player.h Battle.cpp Battle.h Menu.cpp Menu.h Characters.cpp Characters.h CharacterInfo.cpp CharacterInfo.h TurnSystem.cpp TurnSystem.h ActionNames.h TitleScreen.cpp TitleScreen.h World.cpp World.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()