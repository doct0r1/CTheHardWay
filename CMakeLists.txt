cmake_minimum_required(VERSION 3.7)
project(C_HardWay)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ex1.c
        ex3.c
        ex7.c
        ex8.c
        ex9.c
        ex10.c
        ex11.c
        ex12.c
        ex13.c
        ex14.c
        ex15.c
        ex16.c
        ex17.c
        ex18.c
        ex19.c
        ex22_main.c
        ex23.c
        ex24.c
        ex25.c
        ex26/ex26_mine.c
        ex26/ex26.c
        ex27.c
        /ex35/darray_algos.c
        /ex35/ex35.c
        /ex35/radixmap.c
        /ex35/radixmap_tests.c
        ex36.c
        /ex38/hashmap_algos_tests.c
        #onceInATram.c
        /ex45/netClient.c
        /ex46/tstree_tests.c
        /ex47/urlor.c)

#add_executable(C_HardWay ${SOURCE_FILES})
add_executable(ex16 ex16.c)
add_executable(ex17 ex17.c)
add_executable(ex18 ex18.c)
add_executable(ex19 ex19.c)
add_executable(ex22_main ex22_main.c ex22.c ex22.h)
add_executable(ex23 ex23.c)
add_executable(ex24 ex24.c)
add_executable(ex25 ex25.c)
add_executable(ex26_mine ex26/ex26_mine.c)
add_executable(Makefile ex26/ex26.c ex26/.ex26)
add_executable(ex27 ex27.c)
add_executable(exprob exprob.c)
add_executable(darray_algos ex35/darray_algos.c)
add_executable(ex35 ex35/ex35.c)
add_executable(radixmap ex35/radixmap.c)
add_executable(radixmap_test ex35/radixmap_tests.c)
add_executable(ex36 ex36.c)
add_executable(hashmap_algos_tests ex38/hashmap_algos_tests.c)
#add_executable(twoChars twoChars.c)
add_executable(oneeInATram onceInATram.c)
#add_executable(maximumGcdAndSum maximumGcdAndSum.c)
add_executable(netClient ex45/netClient.c)
add_executable(tstree ex46/tstree.c ex46/tstree.h ex46/tstree_tests.c)
add_executable(urlor ex47/urlor.c)