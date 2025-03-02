#版本
cmake_minimum_required(VERSION 3.14)
#项目名
project(BaseComponent LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#语言
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#包含模块
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

#添加宏定义
#add_compile_definitions(QT_NO_DEBUG_ "sig.h"OUTPUT)

#可运行
add_executable(BaseComponent main.cpp "Singleton.cpp" "SimpleFactory.h" "SimpleFactory.cpp" "Factory.h" "Factory.cpp" "AbstractFactory.h" "AbstractFactory.cpp")

#库链接
target_link_libraries(BaseComponent Qt${QT_VERSION_MAJOR}::Core)

