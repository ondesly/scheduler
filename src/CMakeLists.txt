#
#  CMakeLists.txt
#  scheduler
#
#  Created by Dmitrii Torkhov <dmitriitorkhov@gmail.com> on 09.08.2024.
#  Copyright © 2024 Dmitrii Torkhov. All rights reserved.
#

add_library(scheduler STATIC
        scheduler/scheduler.cpp
        scheduler/scheduler.hpp
        scheduler/schedule_handler.cpp
        scheduler/schedule_handler.hpp
)
add_library(dtor::scheduler ALIAS scheduler)

target_include_directories(scheduler
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>)

set_target_properties(scheduler PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)
