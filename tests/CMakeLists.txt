add_executable(user-test user-test.cc)
add_executable(mail-test mail-test.cc)
add_executable(activity-test activity-test.cc)

target_link_libraries(mail-test PUBLIC mail)
target_link_libraries(user-test PUBLIC user)
target_link_libraries(activity-test PUBLIC activity)