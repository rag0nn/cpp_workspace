cmake_minimum_required(VERSION 3.10)
project(LibraryAutomation)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
find_package(OpenSSL REQUIRED)

set(SOURCES
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

add_executable(ra_library ${SOURCES})

# data klasörünü build içine kopyala
add_custom_command(TARGET ra_library POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/data $<TARGET_FILE_DIR:ra_library>/data)

target_link_libraries(ra_library PRIVATE OpenSSL::SSL OpenSSL::Crypto)