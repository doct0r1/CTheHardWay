cmake_minimum_required(VERSION 3.8)
project(devpkg.c)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES devpkg.c
        db.c
        shell.c
        installShell.sh
        apr_thread_proc.h)

add_executable(devpkg.c ${SOURCE_FILES})
add_executable(db db.c)
add_executable(shell shell.c)
add_executable(commands commands.h commands.c)