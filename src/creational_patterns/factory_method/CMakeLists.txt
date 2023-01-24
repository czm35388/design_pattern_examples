set(TARGET_NAME factory_method)

add_executable(${TARGET_NAME} 
        ${TARGET_NAME}.cpp
        ../../../3rdparty/pugixml/src/pugixml.cpp
    )

target_include_directories(${TARGET_NAME}
    PRIVATE
        ../../../3rdparty/pugixml/src/
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    )

