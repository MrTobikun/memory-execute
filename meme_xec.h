#ifndef MEME_XEC_H
#define MEME_XEC_H

#include <sys/mman.h>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define getpagesize() 4096 // getpagesize() is exist in standart C11

#define MEM_EXEC_RETURN _mem_exec_ret

#define MEM_CREATE_FUNC_PTR char* (*_func_ptr)(char*, long, char*, long)

#define MEM_EXEC(child_func, func, func_params ...)                                                         \
  void* _mem_func = aligned_alloc(getpagesize(), getpagesize());                                            \
  if (mprotect(_mem_func, getpagesize(), PROT_READ | PROT_EXEC | PROT_WRITE) == -1) { perror("mprotect"); } \
  memcpy(_mem_func, (const void*)&func, &child_func - &func);                                               \
  _func_ptr = _mem_func;                                                                                    \
  char* _mem_exec_ret = (*_func_ptr)(func_params);                                                          \
  free(_mem_func);

#endif // MEME_XEC_H
