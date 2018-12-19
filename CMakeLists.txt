cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(BOOST_ROOT "/usr/local/include/boost")

#添加头文件搜索路径
include_directories(/usr/local/include)

#添加库文件搜索路径
link_directories(/usr/local/lib)

# 查找boost的功能模块
find_package(Boost 1.65.1 COMPONENTS log thread system regex date_time REQUIRED)

add_executable(untitled main.cpp)
add_executable(11_ContainerWithMostWater Array/11_ContainerWithMostWater.cpp)
target_link_libraries(untitled ${Boost_LIBRARIES})

add_executable(16_3SumClosest Array/16_3SumClosest.cpp)
add_executable(multi_thread multi_thread.cpp)
add_executable(905_SortArrayByParity Array/905_SortArrayByParity.cpp)
add_executable(832_FlippingAnImage Array/832_FlippingAnImage.cpp)
add_executable(561_ArrayPartitionI Array/561_ArrayPartitionI.cpp)
add_executable(922_SortArrayByParityII Array/922_SortArrayByParityII.cpp)
add_executable(867_TransposeMatrix Array/867_TransposeMatrix.cpp)
add_executable(766_ToeplitzMatrix Array/766_ToeplitzMatrix.cpp)