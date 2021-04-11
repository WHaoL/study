cmake_minimum_required(VERSION 3.0)
project(sylar)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")
# set(CMAKE_C_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")

include_directories(.)
include_directories(/apps/sylar/include)#添加yaml-cpp的include路径
link_directories(/apps/sylar/lib)

find_library(YAMLCPPLIB yaml-cpp)
set(LIB_SRC
    sylar/log.cpp
    sylar/util.cpp
    sylar/config.cpp
    )
add_library(sylar SHARED ${LIB_SRC})#根据上面的文件生成动态库 libsylar.so

# 测试日志模块
# add_executable(test_log "tests/test_log.cpp")
# add_dependencies(test_log sylar)
# target_link_libraries(test_log sylar ${YAMLCPPLIB}) # 依赖动态库sylar

#测试配置系统
add_executable(test_config tests/test_config.cpp)
add_dependencies(test_config sylar)
target_link_libraries(test_config sylar ${YAMLCPPLIB}) # 增加依赖动态库yaml-cpp
# target_link_libraries(test_config sylar yaml-cpp) # 增加依赖动态库yaml-cpp


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
