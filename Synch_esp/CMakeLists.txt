cmake_minimum_required(VERSION 3.16)




add_library( agua_synchEsp_deps INTERFACE ) 



add_library( agua_synchEsp INTERFACE ) 
add_library( AGUA::SynchEsp  ALIAS agua_synchEsp) 
target_include_directories( agua_synchEsp INTERFACE    "${CMAKE_CURRENT_SOURCE_DIR}" ) 

target_link_libraries( agua_synchEsp INTERFACE agua_synchEsp_deps  agua_etl_lib InlineOS  ) 



