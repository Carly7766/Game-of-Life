target_sources(
        ${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Constants.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/CellularAutomata/CellularAutomata.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/CellularAutomata/CellularAutomata.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/CellularAutomata/Coordinate.hpp
)
