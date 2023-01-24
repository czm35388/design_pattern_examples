set(TARGET_NAME factory_method)

add_executable(${TARGET_NAME} 
        ${TARGET_NAME}.cpp
        parser_intf.h
        json_parser.cpp
        json_parser.h
        map_parser.cpp
        map_parser.h
        par_parser.cpp
        par_parser.h
        ../../../3rdparty/pugixml/src/pugixml.cpp
    )

target_link_libraries(${TARGET_NAME}
        PUBLIC $<BUILD_INTERFACE:nlohmann_json>
    )

target_include_directories(${TARGET_NAME}
    PRIVATE
        ../../../3rdparty/pugixml/src/
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    )

