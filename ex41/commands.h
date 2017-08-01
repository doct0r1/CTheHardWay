//
// Created by Mu$t4f△ J4m4L on 7/24/17.
//

#ifndef _command_h
#define _command_h

#include "apr_pools.h"

#define DEPENDS_PATH "/tmp/DEPENDS"
#define TAR_GZ_SRC "tmp/pkg-src.tar.gz"
#define TAR_BZ2_SRC "tmp/pkg-src.tar.gz2"
#define BUILD_DIR "/tmp/pkg-build"
#define GIT_PAT "*.git"
#define DEPEND_PAT "*DEPENDS"
#define TAR_GZ_PAT "*.tar.gz"
#define TAR_GZ2_PAT "*.tar.gz2"
#define CONFIG_SCRIPT "/tmp/pkg-build/conifgure"

enum CommandType {
	COMMAND_NONE, COMMAND_INSTALL, COMMAND_LIST, COMMAND_FETCH, COMMAND_INIT, COMMAND_BUILD
};

int Command_fetch(apr_pool_t *p, const char *url, int fetch_only);

int Command_install(apr_pool_t *p, const char *url, const char *configure_opts, const char *make_opts, const char *install_opts);

int Command_depend(apr_pool_t *p, const char *path);

int Command_build(apr_pool_t *p, const char *url, const char *configure_opts, const char *make_opts, const char *install_opts);


#endif //_command_h
