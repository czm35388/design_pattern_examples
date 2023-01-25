
# integration of pugixml
add_library(pugixml STATIC pugixml/src/pugixml.cpp)
target_include_directories(pugixml PUBLIC pugixml/src)
set_target_properties(pugixml PROPERTIES POSITION_INDEPENDENT_CODE ON)

# add additional libs
add_subdirectory(nlohmann_json)