file(GLOB subdirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} */CMakeLists.txt)

foreach(cmakefile ${subdirs})                               # 遍历所有子目录
    get_filename_component(subdir ${cmakefile} DIRECTORY)   # 获取子目录名
    add_subdirectory(${subdir})                             # 添加子目录
endforeach()