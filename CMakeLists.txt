cmake_minimum_required(VERSION 3.0)

if(DEFINED NO_COLOR AND NO_COLOR EQUAL true)
  message("No color mode enabled.")
  message(${NO_COLOR})
  add_compile_definitions(NO_COLOR)
endif()

project(4.1)
add_executable(4.1 src/4/4.1/main.c)

project(4.2)
add_executable(4.2 src/4/4.2/main.c)

project(5.2)
add_executable(5.2 src/5/5.2/main.c)

project(5.4)
add_executable(5.4 src/5/5.4/main.c)

project(5.5)
add_executable(5.5 src/5/5.5/main.c)

project(5.6)
add_executable(5.6 src/5/5.6/main.c)

project(5.7)
add_executable(5.7 src/5/5.7/main.c)

project(5.8)
add_executable(5.8 src/5/5.8/main.c)
target_link_libraries(5.8 m)

project(5.9)
add_executable(5.9 src/5/5.9/main.c)

project(6.1)
add_executable(6.1 src/6/6.1/main.c)

project(6.2)
add_executable(6.2 src/6/6.2/main.c)

project(6.3)
add_executable(6.3 src/6/6.3/main.c)

project(7.1)
add_executable(7.1 src/7/7.1/main.c)

project(7.2)
add_executable(7.2 src/7/7.2/main.c)

project(7.3)
add_executable(7.3 src/7/7.3/main.c)

project(7.4)
add_executable(7.4 src/7/7.4/main.c)

project(7.5)
add_executable(7.5 src/7/7.5/main.c)

project(7.6)
add_executable(7.6 src/7/7.6/main.c)
target_link_libraries(7.6 m)

project(7.7)
add_executable(7.7 src/7/7.7/main.c)

project(7.8)
add_executable(7.8 src/7/7.8/main.c)

project(9.1)
add_executable(9.1 src/9/9.1/main.c)

project(9.2)
add_executable(9.2 src/9/9.2/main.c)
target_link_libraries(9.2 m)

project(9.3)
add_executable(9.3 src/9/9.3/main.c)

project(9.4)
add_executable(9.4 src/9/9.4/main.c)

project(9.5)
add_executable(9.5 src/9/9.5/main.c)

project(9.6)
add_executable(9.6 src/9/9.6/main.c)

project(10.1)
add_executable(10.1 src/10/10.1/main.c src/10/10.1/change-base.c src/10/10.1/change-base.h)

project(10.2)
add_executable(10.2 src/10/10.2/main.c src/10/10.2/complex.c src/10/10.2/complex.h)
target_link_libraries(10.2 m)

project(11.1)
add_executable(11.1 src/11/11.1/main.c)

project(11.2)
add_executable(11.2 src/11/11.2/main.c src/11/11.2/cswap.c src/11/11.2/cswap.h)

project(11.3)
add_executable(11.3 src/11/11.3/main.c src/11/11.3/quadratic.c src/11/11.3/quadratic.h)
target_link_libraries(11.3 m)

project(11.4)
add_executable(11.4
  src/11/11.4/main.c
  src/11/11.4/p2c.c
  src/11/11.4/p2c.h
)
target_link_libraries(11.4 m)

project(11.6)
add_executable(11.6 src/11/11.6/main.c)

project(12.1)
add_executable(12.1 src/12/12.1/main.c)

project(12.3)
add_executable(12.3 src/12/12.3/main.c)

project(12.4)
add_executable(12.4 src/12/12.4/main.c)

project(12.5)
add_executable(12.5 src/12/12.5/main.c)

project(12.6)
add_executable(12.6 src/12/12.6/main.c)

project(12.7)
add_executable(12.7 src/12/12.7/main.c)

project(12.8)
add_executable(12.8 src/12/12.8/main.c src/12/12.8/bubble-sort.c src/12/12.8/bubble-sort.h)

project(12.9)
add_executable(12.9 src/12/12.9/main.c src/12/12.9/insertion-sort.c src/12/12.9/insertion-sort.h)

project(12.10)
add_executable(12.10 src/12/12.10/main.c)

project(12.11)
add_executable(12.11 src/12/12.11/main.c)

project(12.12)
add_executable(12.12 src/12/12.12/main.c src/12/12.12/query.c src/12/12.12/query.h src/12/12.12/extrema.c src/12/12.12/extrema.h)

project(12.13)
add_executable(12.13 src/12/12.13/main.c)

project(12.14)
add_executable(12.14 src/12/12.14/main.c src/12/12.14/display.c src/12/12.14/display.h)

project(12.15)
add_executable(12.15 src/12/12.15/main.c src/12/12.15/display.c src/12/12.15/display.h)

project(12.16)
add_executable(12.16 src/12/12.16/main.c)

project(13.1)
add_executable(13.1 src/13/13.1/main.c)

project(13.2)
add_executable(13.2 src/13/13.2/main.c)

project(13.3)
add_executable(13.3 src/13/13.3/main.c)

project(13.4)
add_executable(13.4 src/13/13.4/main.c)

project(13.5)
add_executable(13.5 src/13/13.5/main.c src/13/13.5/is_present.c src/13/13.5/is_present.h)

project(13.6)
add_executable(13.6 src/13/13.6/main.c)
