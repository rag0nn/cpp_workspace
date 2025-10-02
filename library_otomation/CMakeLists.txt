cmake_minimum_required(VERSION 3.10)
project(LibraryAutomation)

set(CMAKE_CXX_STANDARD 17)

# OpenSSL, OpenCV ve Qt5
find_package(OpenSSL REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# include dizinleri
include_directories(include)
include_directories(${OpenCV_INCLUDE_DIRS})

# -----------------------------
# 1. Terminal uygulaması (ra_library)
set(TERMINAL_SOURCES
    src/main.cpp
    src/basicModels/Book.cpp
    src/basicModels/User.cpp
    src/basicModels/Transaction.cpp
    src/basicModels/DateTime.cpp
    src/dataManagerModels/DataManager.cpp
    src/dataManagerModels/Users.cpp
    src/dataManagerModels/Books.cpp
    src/dataManagerModels/Transactions.cpp
    src/utils/Tools.cpp
    src/utils/Encryption.cpp
)

add_executable(ra_library ${TERMINAL_SOURCES})

# data klasörünü kopyala
add_custom_command(TARGET ra_library POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/data $<TARGET_FILE_DIR:ra_library>/data)

target_link_libraries(ra_library
    PRIVATE
        OpenSSL::SSL
        OpenSSL::Crypto
        ${OpenCV_LIBS}
)

# -----------------------------
# 2. GUI uygulaması (ra_gui)
set(GUI_SOURCES
    src/gui.cpp
    src/basicModels/Book.cpp
    src/basicModels/User.cpp
    src/basicModels/Transaction.cpp
    src/basicModels/DateTime.cpp
    src/dataManagerModels/DataManager.cpp
    src/dataManagerModels/Users.cpp
    src/dataManagerModels/Books.cpp
    src/dataManagerModels/Transactions.cpp
    src/utils/Tools.cpp
    src/utils/Encryption.cpp
)

add_executable(ra_gui ${GUI_SOURCES})

# data klasörünü kopyala
add_custom_command(TARGET ra_gui POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/data $<TARGET_FILE_DIR:ra_gui>/data)

target_link_libraries(ra_gui
    PRIVATE
        Qt5::Widgets
        OpenSSL::SSL
        OpenSSL::Crypto
        ${OpenCV_LIBS}
)
