add_executable(ucoactividades app/app-main.cc app/app.cc)
add_subdirectory(classes)
target_link_libraries(ucoactividades ncurses)