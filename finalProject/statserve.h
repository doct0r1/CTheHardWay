//
// Created by Mu$t4f△ J4m4L on 7/29/17.
//

#ifndef _statserve_h
#define _statserve_h

#include "../ex41/bstrlib.h"
#include "../ex44/ringbuffer.h"
//#include <lcthw/stats.h>
#include "../ex43/stats.h"

struct Command;

typedef int (*handler_cb)(struct Command *cmd, RingBuffer *send_rb, bstring path);

typedef struct Command {
	bstring command;
	bstring name;
	struct bstrList *path;
	bstring number;
	handler_cb handler;
} Command;


typedef struct Record {
	bstring name;
	Stats *stat;
} Record;

struct tagbstring OK;

int setup_data_store();

struct bstrList *parse_name(bstring name);

int scan_paths(Command *cmd, RingBuffer *send_rb);

int parse_line(bstring data, RingBuffer *send_rb);

int echo_server(const char *host, const char *port);

#endif