add_executable(connect main.cpp MainWindow.cpp )
include_directories(../utils)
target_link_libraries(
        connect
        ${AuBo_LIBRARIES}
        ${QT_LIBRARIES}
        aubo
)