cmake_minimum_required(VERSION 2.8.3)
project(realhw_control)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  hardware_interface
  transmission_interface
  controller_manager
)

catkin_package(
 INCLUDE_DIRS include
#  LIBRARIES trobo_control
  CATKIN_DEPENDS roscpp hardware_interface transmission_interface controller_manager
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
 
add_executable(realhw_control src/realhw_control.cpp src/realhw.cpp) 

target_link_libraries(realhw_control
  ${catkin_LIBRARIES}
)

install(TARGETS realhw_control
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
