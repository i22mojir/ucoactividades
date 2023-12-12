add_library(activity activity.cc activity.h)
target_link_libraries(activity PUBLIC user)
target_link_libraries(activity PUBLIC mail)