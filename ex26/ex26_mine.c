//
// Created by Mu$t4f△ J4m4L on 7/1/17.
// logfind tool
//

/**
 * so This will be the func that i'll gonna use :3
 */

#include "../dbg.h"
#include <glob.h>

glob_t glob_buffer;
const char * pattern = "/tmp/*";
int i;
int match_count;


glob( pattern , 0 , NULL , &glob_buffer );
match_count = glob_buffer.gl_pathc;
printf("Number of mathces: %d\n", match_count);

for (i=0; i < match_count; i++)
printf("match[%d] = %s \n",i,glob_buffer.gl_pathv[i]);

globfree( &glob_buffer );