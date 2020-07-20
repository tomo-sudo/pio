#pragma once
#include <fcntl.h>
#include "common.h"

//genernal use
int openF(char *name);
int openFlash(char *name);


int rdLine(int fd, void *pstr);  //here char *pstr equals to char pstr[]
int rdOnceRd(int fd, void *pstr);  //here char *pstr equals to char pstr[]
