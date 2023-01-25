cmake_minimum_required(VERSION 3.16)
project(flexible-iterator LANGUAGES C)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

add_executable(flexible-iterator.out "")

target_sources(flexible-iterator.out
  PRIVATE
  callbackIterator.c
  callbackIterator.h
  cursorIterator.c
  cursorIterator.h
  indexAccess.c
  indexAccess.h
  main.c
  )
