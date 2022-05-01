add_subdirectory(utils)

set(EXT_LIBS ${EXT_LIBS} utils)
message(STATUS "depend ext_libs: ${EXT_LIBS}")
message(STATUS "CMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}")

# create executable files
## get file of main.cpp
aux_source_directory(. DIR_SRC)

## get source files from leetcode directory
aux_source_directory(./leetcode/cpp LEETCODE_DIR_SRC)
set(DIR_SRC ${DIR_SRC} ${LEETCODE_DIR_SRC})
#message(STATUS ${LEETCODE_DIR_SRC})

## get files of sword-to-offer problems
aux_source_directory(./sword_to_offer/cpp SWORD_OFFER_DIR_SRC)
set(DIR_SRC ${DIR_SRC} ${SWORD_OFFER_DIR_SRC})

## get files of classical problems and algorithms
aux_source_directory(./classical CLASSICAL_DIR_SRC)
set(DIR_SRC ${DIR_SRC} ${CLASSICAL_DIR_SRC})


## add sprcific source file for testing
#set(DIR_SRC src/e001_100/q0048.cpp)

message(STATUS ${PROJECT_NAME})
message(STATUS ${DIR_SRC})

## create target and link libraries
add_executable(${PROJECT_NAME}_testcase ${DIR_SRC})
target_link_libraries(${PROJECT_NAME}_testcase ${LIBS} ${EXT_LIBS})
add_custom_command(TARGET ${PROJECT_NAME}_testcase
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "deploy to ${CMAKE_BINARY_DIR}/${PROJECT_NAME}"
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_NAME}_testcase ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
)
