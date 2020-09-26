add_executable(movel main.cpp MainWindow.cpp
        ../utils/Robot.cpp
        ../utils/util.cpp)

#add_executable(main main.cpp example_0.h example_0.cpp)
target_link_libraries(
        movel
        ${AuBo_LIBRARIES}
        ${QT_LIBRARIES}
)