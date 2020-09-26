add_executable(movej main.cpp MainWindow.cpp)
include_directories(../utils)

#add_executable(main main.cpp example_0.h example_0.cpp)
target_link_libraries(
        movej
        aubo
        ${AuBo_LIBRARIES}
        ${QT_LIBRARIES}
)