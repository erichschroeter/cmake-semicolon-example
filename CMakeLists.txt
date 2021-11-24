cmake_minimum_required(VERSION 3.12)
project(Example)

list(APPEND PATH_ARGS
    C:/path/to/something/a
    C:/path/to/something/b
    C:/path/to/something/c)

# Tried a whole bunch:
# https://cmake.org/pipermail/cmake/2008-October/024746.html
# https://stackoverflow.com/questions/11593180/cmake-how-to-output-semicolon-as-command-options-in-add-custom-target
# https://cmake.org/cmake/help/v3.0/manual/cmake-language.7.html#syntax

string(REPLACE " " "$<SEMICOLON>" PATH_WITH_SEMICOLON ${PATH_ARGS})
string(REPLACE " " "\;" PATH_WITH_ESCAPE_SEMICOLON ${PATH_ARGS})


add_custom_command(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Debug/a.exe
        --path=${PATH_ARGS}
    OUTPUT 1.txt
    COMMENT "Invoking (without quotes): a.exe with '${PATH_ARGS}'")
add_custom_target(attempt_1
    DEPENDS 1.txt)


add_custom_command(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Debug/a.exe
        --path="${PATH_ARGS}"
    OUTPUT 2.txt
    COMMENT "Invoking (with quotes): a.exe with '${PATH_ARGS}'")
add_custom_target(attempt_2
    DEPENDS 2.txt)


add_custom_command(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Debug/a.exe
        --path="${PATH_WITH_SEMICOLON}"
    OUTPUT 3.txt
    COMMENT "Invoking: (semicolon replace with quotes) a.exe with '${PATH_WITH_SEMICOLON}'")
add_custom_target(attempt_3
    DEPENDS 3.txt)


add_custom_command(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Debug/a.exe
        --path=${PATH_WITH_SEMICOLON}
    OUTPUT 4.txt
    COMMENT "Invoking (semicolon replace without quotes): a.exe with '${PATH_WITH_SEMICOLON}'")
add_custom_target(attempt_4
    DEPENDS 4.txt)


add_custom_command(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Debug/a.exe
    --path="${PATH_WITH_ESCAPE_SEMICOLON}"
    OUTPUT 5.txt
    COMMENT "Invoking: (escaped_semicolon replace with quotes) a.exe with '${PATH_WITH_ESCAPE_SEMICOLON}'")
add_custom_target(attempt_5
    DEPENDS 5.txt)


add_custom_command(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Debug/a.exe
        --path=${PATH_WITH_ESCAPE_SEMICOLON}
    OUTPUT 6.txt
    COMMENT "Invoking (escaped_semicolon replace without quotes): a.exe with '${PATH_WITH_ESCAPE_SEMICOLON}'")
add_custom_target(attempt_6
    DEPENDS 6.txt)


add_custom_command(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Debug/a.exe
        --path=C:/path/to/something/a;C:/path/to/something/b;C:/path/to/something/c
    OUTPUT 7.txt
    COMMENT "Invoking (hard-coded without quotes): a.exe")
add_custom_target(attempt_7
    DEPENDS 7.txt)


add_custom_command(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Debug/a.exe
        --path="C:/path/to/something/a;C:/path/to/something/b;C:/path/to/something/c"
    OUTPUT 8.txt
    COMMENT "Invoking (hard-coded with quotes): a.exe")
add_custom_target(attempt_8
    DEPENDS 8.txt)


add_custom_command(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Debug/a.exe
        --path=\"C:/path/to/something/a;C:/path/to/something/b;C:/path/to/something/c\"
    OUTPUT 9.txt
    COMMENT "Invoking (hard-coded with escaped quotes): a.exe")
add_custom_target(attempt_9
    DEPENDS 9.txt)


add_custom_command(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Debug/a.exe
        --path=\"C:/path/to/something/a;C:/path/to/something/b;C:/path/to/something/c\"
    VERBATIM
    OUTPUT 10.txt
    COMMENT "Invoking (verbatim hard-coded with escaped quotes): a.exe")
add_custom_target(attempt_10
    DEPENDS 10.txt)


add_custom_command(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Debug/a.exe
        --path="C:/path/to/something/a;C:/path/to/something/b;C:/path/to/something/c"
    VERBATIM
    OUTPUT 11.txt
    COMMENT "Invoking (verbatim hard-coded with quotes): a.exe")
add_custom_target(attempt_11
    DEPENDS 11.txt)


add_custom_command(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/Debug/a.exe
        "--path=${PATH_ARGS}"
    OUTPUT 12.txt
    COMMENT "Invoking (quotes around both): a.exe with '${PATH_ARGS}'")
add_custom_target(attempt_12
    DEPENDS 12.txt)


add_executable(a main.cpp) 
# Uncomment below to have each custom target auto run after having built target a
add_dependencies(a
    attempt_1
    attempt_2
    attempt_3
    attempt_4
    attempt_5
    attempt_6
    attempt_7
    attempt_8
    attempt_9
    attempt_10
    attempt_11
    attempt_12)