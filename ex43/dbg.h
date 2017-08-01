//
// Created by Mu$t4f△ J4m4L on 6/26/17.
// This was before ex19.
//

#ifndef __dbg_h__

#define __dbg_h__



#include <stdio.h>

#include <errno.h>

#include <string.h>



#ifdef NDEBUG

#define debug(M, ...)

#else

#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n",__FILE__, __LINE__, ##__VA_ARGS__)

#endif



#define clean_errno() (errno == 0 ? "None" : strerror(errno))



#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__,clean_errno(), ##__VA_ARGS__)



#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)



#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)



#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }



#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }



#define check_mem(A) check((A), "Out of memory.")



#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }



#endif //C_HARDWAY_DBG_H