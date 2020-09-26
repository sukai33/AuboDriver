add_executable(fkik main.cpp MainWindow.cpp )
include_directories(../utils)
target_link_libraries(
        fkik
        ${AuBo_LIBRARIES}
        ${QT_LIBRARIES}
        aubo
)