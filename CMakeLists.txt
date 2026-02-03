cmake_minimum_required(VERSION 3.10)
project(CardGuessingGame)

set(CMAKE_CXX_STANDARD 17)

# Include all .cpp files in the CardGuessingGame subfolder
file(GLOB SOURCES "CardGuessingGame/*.cpp")

add_executable(CardGuessingGame ${SOURCES})
