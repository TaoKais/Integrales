/* Condition type.  Generic version.
   Copyright (C) 2000-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library;  if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _BITS_TYPES_STRUCT___PTHREAD_COND_H
#define _BITS_TYPES_STRUCT___PTHREAD_COND_H	1

#include <C:\Workspace\Workspace_A\includes\__pthread_spinlock_t.h>

/* User visible part of a condition variable.  */
struct __pthread_cond
{
  __pthread_spinlock_t __lock;
  struct __pthread *__queue;
  struct __pthread_condattr *__attr;
  struct __pthread_condimpl *__impl;
  void *__data;
};

/* Initializer for a condition variable.  */
#define __PTHREAD_COND_INITIALIZER \
  { __PTHREAD_SPIN_LOCK_INITIALIZER, NULL, NULL, NULL, NULL }

#endif /* bits/types/struct___pthread_cond.h */
