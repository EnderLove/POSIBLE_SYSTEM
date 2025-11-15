cmake_minimum_required(VERSION 3.16)

project(POSIBLE_SYSTEM VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(POSIBLE_SYSTEM
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        documentation/notes_documentation.md
        documentation/notes_software.md
        src/controller/logincontroller.h src/controller/logincontroller.cpp
        src/controller/maincontroller.h src/controller/maincontroller.cpp
        src/controller/productcontroller.h src/controller/productcontroller.cpp
        src/model/dbmanagermodel.h src/model/dbmanagermodel.cpp
        src/model/productmodel.h src/model/productmodel.cpp
        src/model/salemodel.h src/model/salemodel.cpp
        src/model/usermodel.h src/model/usermodel.cpp
        src/view/mainwindow.h src/view/mainwindow.cpp src/view/mainwindow.ui
        src/view/loginwindow.h src/view/loginwindow.cpp src/view/loginwindow.ui
        src/view/productwindow.h src/view/productwindow.cpp src/view/productwindow.ui
        src/widgets/productitemwidget.h src/widgets/productitemwidget.cpp src/widgets/productitemwidget.ui
        resources/styles/styles.qss

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET POSIBLE_SYSTEM APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(POSIBLE_SYSTEM SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(POSIBLE_SYSTEM
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(POSIBLE_SYSTEM PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.POSIBLE_SYSTEM)
endif()
set_target_properties(POSIBLE_SYSTEM PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS POSIBLE_SYSTEM
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(POSIBLE_SYSTEM)
endif()
