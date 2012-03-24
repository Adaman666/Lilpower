#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <stdlib.h>

/* prototypes */
void command_start();
void command_get(char* buffer);
int command_treat(char* command);
#endif

