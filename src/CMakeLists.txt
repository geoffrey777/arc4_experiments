project(${CMAKE_PROJECT_NAME}_lib)

set(HEADER_FILES RC4.h Generator.h EncryptedGroup.h Attack.h)
set(SOURCE_FILES RC4.cpp Generator.cpp Attack.cpp)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC
    ${SOURCE_FILES}
    ${HEADER_FILES}
)