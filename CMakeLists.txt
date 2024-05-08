cmake_minimum_required(VERSION 3.26)
project(MusicPlayer)

# Установка стандарта C++17
set(CMAKE_CXX_STANDARD 17)

# Добавление пути к заголовочным файлам SFML
set(SFML_DIR "SFML/lib/cmake/SFML")

# Настройка поиска SFML, используя файл конфигурации, предоставленный в папке SFML
find_package(SFML 2.6 COMPONENTS graphics audio window system REQUIRED)

# Включение директории include для проекта
include_directories(include)

# Указываем исходные файлы и заголовочные файлы
set(SOURCES src/main.cpp)
set(HEADERS)

# Добавляем исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Линковка с библиотеками SFML
target_link_libraries(MusicPlayer sfml-graphics sfml-audio sfml-window sfml-system)

# Убедитесь, что SFML включена в пути поиска при запуске
set_target_properties(MusicPlayer PROPERTIES
                      INSTALL_RPATH "${SFML_DIR}/../lib")
