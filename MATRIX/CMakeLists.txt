cmake_minimum_required(VERSION 3.19)
project(MATRIX LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets WebEngineWidgets)

qt_standard_project_setup()

qt_add_resources(RESOURCES resource.qrc)

qt_add_executable(MATRIX
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ${RESOURCES}
)

target_link_libraries(MATRIX
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt6::WebEngineWidgets
)

include(GNUInstallDirs)

install(TARGETS MATRIX
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET MATRIX
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
