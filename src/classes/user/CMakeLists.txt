add_library(user user.cc user.h)
target_link_libraries(user PUBLIC mail)
target_link_libraries(user PUBLIC activity)