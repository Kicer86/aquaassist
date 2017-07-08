
find_package(Qt5Widgets REQUIRED)

qt5_wrap_ui(wrapped_ui main_window.ui)
#qt5_wrap_cpp(wrapped_cpp events.hpp)

add_executable(aquaassist
                all_events_model.cpp
                all_events_model.hpp
                events.cpp
                events.hpp
                events_model.cpp
                events_model.hpp
                main.cpp
                main_window.cpp
                main_window.hpp
                ${wrapped_ui}
                ${wrapped_cpp}
)

target_link_libraries(aquaassist
                        PRIVATE
                            Qt5::Widgets
)

target_include_directories(aquaassist
                            PRIVATE
                                ${CMAKE_CURRENT_BINARY_DIR}
)
