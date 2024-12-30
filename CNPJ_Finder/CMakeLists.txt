cmake_minimum_required(VERSION 3.14)

# Nome do projeto e definição da linguagem
project(CNPJ_Finder VERSION 1.0 LANGUAGES CXX)

# Definir o padrão C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Diretório onde as bibliotecas estáticas do Qt estão localizadas
set(Qt6_DIR "D:/Qt/build-static/lib/cmake/Qt6")

set(CMAKE_AUTOMOC ON)  # Garante que os arquivos .moc sejam gerados automaticamente
set(CMAKE_AUTOUIC ON)  # Processa arquivos .ui automaticamente
set(CMAKE_AUTORCC ON)  # Processa arquivos .qrc automaticamente

# Configuração para compilação estática
set(BUIILD_SHARED_LIBS OFF)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

# Encontrar pacotes Qt necessários
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

# Listar os arquivos de interface (.ui)
set(UI_FILES
    mainwindow.ui
    historicwindow.ui
)

# Listar os arquivos de origem e cabeçalhos
set(SOURCES
    main.cpp
    mainwindow.cpp
    historicwindow.cpp
)

set(HEADERS
    mainwindow.h
    historicwindow.h
)

# Adicionar o executável
add_executable(CNPJ_Finder WIN32
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
)

# Linkar o projeto com o Qt
target_link_libraries(CNPJ_Finder
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
)

# Configurar o diretório de instalação do executável
set_target_properties(CNPJ_Finder PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
