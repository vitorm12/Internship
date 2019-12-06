cmake_minimum_required(VERSION 3.15)
project(TransactionValidation)

set(CMAKE_CXX_STANDARD 14)

add_executable(TransactionValidation main.cpp Sender.cpp Sender.h)