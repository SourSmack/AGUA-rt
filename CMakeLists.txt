cmake_minimum_required(VERSION 3.16)
project(aguart) 



include(FetchContent)
FetchContent_Declare(
    etl
    GIT_REPOSITORY https://github.com/etlcpp/etl.git
    GIT_TAG 20.38.2
    SOURCE_SUBDIR skip_cmake 
)
FetchContent_Declare(
    InlineOS
    GIT_REPOSITORY https://github.com/SourSmack/InlineOS.git
    GIT_TAG main
)
add_library( agua_etl_lib INTERFACE ) 
target_include_directories( agua_etl_lib INTERFACE "${etl_SOURCE_DIR}/include")

FetchContent_MakeAvailable(etl InlineOS)

add_library( agua_headers INTERFACE )
add_library( AGUA::Headers ALIAS agua_headers ) 
target_include_directories( agua_headers INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")




add_subdirectory( Synch_esp/ ) 
