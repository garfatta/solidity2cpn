# JSON library
add_library(json INTERFACE)
target_include_directories(json INTERFACE nlohmann/)

# CLI library
add_library(cli11 INTERFACE)
target_include_directories(cli11 INTERFACE cli11/)