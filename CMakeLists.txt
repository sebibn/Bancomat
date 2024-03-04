cmake_minimum_required(VERSION 3.23)
project(Bancomat)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bancomat main.cpp Collection.cpp Collection.h ATM.cpp ATM.h Tranzactie.cpp Tranzactie.h Collection.cpp Collection.h RepositoryCollection.cpp RepositoryCollection.h ATM.cpp ATM.h VectorDinamic.cpp VectorDinamic.h Node.h List.h TestList.cpp TestList.h)
