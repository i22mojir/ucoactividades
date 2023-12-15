add_library(mail mail.cc mail.h)
target_link_libraries(mail PUBLIC user)
target_link_libraries(mail PUBLIC activity)