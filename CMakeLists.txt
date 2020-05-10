# CMakeList.txt: проект CMake для CourseWork_Final; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CourseWork_Final "main.c" "application.h" "application.c" "userinterface.h" "userinterface.c" "settings.h" "settings.c")
target_sources (CourseWork_Final PUBLIC "animals.h" PUBLIC "animalsmap.h" PUBLIC "animalsmap.c" PUBLIC "utils.h" PUBLIC "utils.c")
target_sources (CourseWork_Final PUBLIC "turn.h" PUBLIC "turn.c")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
