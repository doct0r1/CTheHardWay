//
// Created by Mu$t4f△ J4m4L on 7/25/17.
//

#ifndef _queue_h
#define _queue_h

#include "list.h"   // there is some error exist in this file :3

#define Queue_create List_create
#define Queue_destroy List_destroy
#define Queue_clear List_clear
#define Queue_clear_destroy List_clear_destroy

#define Queue_send List_unshift
#define Queue_recv List_pop

#define Queue_peek List_last
#define Queue_count List_count

#define QUEUE_FOREACH(S, V) LIST_FOREACH(S, last, prev, V)

#endif //_queue_h
