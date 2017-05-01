
find_package(Qt5Widgets REQUIRED)

add_executable(aquaassist
                event_view.cpp
                event_view.hpp
                main.cpp
                main_window.cpp
                main_window.hpp
)

target_link_libraries(aquaassist
                        PRIVATE
                            Qt5::Widgets
)
