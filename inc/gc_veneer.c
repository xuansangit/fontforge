/* Veneers for libgc functions.

   Copyright (c) 2014 Free Software Foundation, Inc.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
  
   Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
  
   Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
  
   The name of the author may not be used to endorse or promote products
   derived from this software without specific prior written permission.
  
   THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
   EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
   OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
   OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
   ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#include <fontforge-config.h>

#include <stdlib.h>
#include <string.h>


/* This veneer allows libgc to be used via preprocessor trickery to
   override the standard function names without upsetting system
   headers. In particular, this means we cannot use macros with
   arguments, so as libgc has no calloc function, we must implement it
   as a trivial function. */
void *
fontforge_calloc(size_t n, size_t s)
{
  size_t size = n * s;
  void *p = malloc(size);
  return p ? memset(p, 0, size) : NULL;
}