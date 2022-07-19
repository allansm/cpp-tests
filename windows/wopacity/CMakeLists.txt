PROJECT(wopacity)

SET(CMAKE_CXX_COMPILER "g++")

ADD_EXECUTABLE(opacity wopacity.cpp)
ADD_EXECUTABLE(fopacity wfocusopacity.cpp)
ADD_EXECUTABLE(ropacity wropacity.cpp)

TARGET_LINK_LIBRARIES(opacity mswindow)
TARGET_LINK_LIBRARIES(fopacity win time file)
TARGET_LINK_LIBRARIES(ropacity win)
