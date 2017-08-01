#include <stdio.h>
#include "../dbg.h"
#include <dlfcn.h>

// function pointer
typedef int (*lib_function) (const char *data);

int main(int argc, char *argv[])
{
    int rc = 0;
    check(argc == 4, "USAGE: ./ex29 libex29.so function data");

    char *lib_file = argv[1];
    char *func_to_run = argv[2];
    char *data = argv[3];

    void *lib = dlopen(lib_file, RTLD_NOW);
    check(lib != NULL,"Failed to open the library %s: %s", lib_file, dlerror());    // dlerror() to find out what the library-related error was.

    lib_function func = dlsym(lib, func_to_run);    // dlsym to get function out of the lib by its string name in func_to_run.
    check(func != NULL, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror());

    rc = func(data);    // call the func function that was returned, and check its return value.
    check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);

    rc = dlclose(lib);  // close the library. Usually, you keep those open the whole time the program is running, so closing it at the end isn't as useful, but that for demonstration purposes.
    check(rc == 0, "Failed t close %s", lib_file);

    return 0;

error:
    return 1;
}
