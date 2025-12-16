cmake_minimum_required(VERSION 3.17)
project(MyApp)

# Find the gtkmm package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

add_executable(
    MyApp 
    main.cpp 
    Vector3.cpp 
    Object.cpp
    Screen.cpp
)

# Link the libraries and includes
target_include_directories(MyApp PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_libraries(MyApp PRIVATE ${GTKMM_LIBRARIES})
target_compile_options(MyApp PRIVATE ${GTKMM_CFLAGS_OTHER})
