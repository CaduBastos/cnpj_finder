cmake_minimum_required(VERSION 3.14)

# Nome do projeto e definição da linguagem
project(CNPJ_Finder VERSION 1.0 LANGUAGES CXX)

# Definir o padrão C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adicionar opção para compilação estática
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

# Adicionar o caminho da instalação do Qt6
set(CMAKE_PREFIX_PATH "/home/cadubastos/Qt")

# Encontrar pacotes Qt necessários
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Incluir as diretivas de compilação estática
add_definitions(-DQT_STATIC_BUILD)

# Adicionar o executável
add_executable(CNPJ_Finder
    main.cpp
    historicwindow.h
    historicwindow.cpp
    historicwindow.ui
)

# Linkar bibliotecas Qt estaticamente
target_link_libraries(CNPJ_Finder PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Network)

# Incluir diretórios do Qt
target_include_directories(CNPJ_Finder PRIVATE ${Qt6_INCLUDE_DIRS})

# Incluir o diretório de headers do projeto
target_include_directories(CNPJ_Finder PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

