add_executable(io main.cpp MainWindow.cpp )
include_directories(../utils)
target_link_libraries(
        io
        ${AuBo_LIBRARIES}
        ${QT_LIBRARIES}
        aubo
)