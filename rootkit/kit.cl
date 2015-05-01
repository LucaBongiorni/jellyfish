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

typedef unsigned char (uchar);

__kernel void log_fopen(__global uchar *input, __global uchar *output){
    size_t global_addr = get_global_id(0);
    input[global_addr] = output[global_addr];
}

__kernel void log_mkdir(__global uchar *input, __global uchar *output){
    size_t global_addr = get_global_id(0);   
    input[global_addr] = output[global_addr];
}

__kernel void log_lstat(__global uchar *input, __global uchar *output){
    size_t global_addr = get_global_id(0);   
    input[global_addr] = output[global_addr];
}

__kernel void log_lstat64(__global uchar *input, __global uchar *output){
    size_t global_addr = get_global_id(0);   
    input[global_addr] = output[global_addr];
}

__kernel void log_creat(__global uchar *input, __global uchar *output){
    size_t global_addr = get_global_id(0);   
    input[global_addr] = output[global_addr];
}

__kernel void log_execve(__global uchar *input, __global uchar *output){
    size_t global_addr = get_global_id(0);   
    input[global_addr] = output[global_addr];
}

__kernel void log_open(__global uchar *input, __global uchar *output){
    size_t global_addr = get_global_id(0);
    input[global_addr] = output[global_addr];
}
