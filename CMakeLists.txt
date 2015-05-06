cmake_minimum_required(VERSION 3.1)
project(ParkingLot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(GTEST_FILES lib/gtest/gtest.h)
set(GMOCK_FILES lib/gmock/gmock.h lib/gmock-gtest-all.cc)
set(TEST_FILES test/TestParkingLotSpec.h test/TestParkingLotSpec.cpp test/TestParkingBoySpec.cpp test/TestParkingBoySpec.h)

set(SOURCE_FILES src/main.cpp)
add_executable(ParkingLot ${SOURCE_FILES} ${TEST_FILES} ${GTEST_FILES} ${GMOCK_FILES} src/ParkingLot.cpp src/ParkingLot.h src/Car.cpp src/Car.h src/ParkingBoy.cpp src/ParkingBoy.h test/TestSmartParkingBoySpec.cpp test/TestSmartParkingBoySpec.h src/SmartParkingBoy.cpp src/SmartParkingBoy.h test/TestSuperParkingBoySpec.cpp test/TestSuperParkingBoySpec.h src/SuperParkingBoy.cpp src/SuperParkingBoy.h test/TestParkingManagerSpec.cpp test/TestParkingManagerSpec.h src/ParkingManager.cpp src/ParkingManager.h test/TestParkingDirectSpec.cpp test/TestParkingDirectSpec.h src/ParkingDirect.cpp src/ParkingDirect.h)