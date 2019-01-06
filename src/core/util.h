/*
* Copyright (c) 2018 Calvin Rose
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#ifndef JANET_UTIL_H_defined
#define JANET_UTIL_H_defined

#include <janet/janet.h>

/* Omit docstrings in some builds */
#ifdef JANET_NO_BOOTSTRAP
#define JDOC(x) NULL
#else
#define JDOC(x) x
#endif

/* Utils */
#define janet_maphash(cap, hash) ((uint32_t)(hash) & (cap - 1))
extern const char janet_base64[65];
int32_t janet_array_calchash(const Janet *array, int32_t len);
int32_t janet_kv_calchash(const JanetKV *kvs, int32_t len);
int32_t janet_string_calchash(const uint8_t *str, int32_t len);
int32_t janet_tablen(int32_t n);
void janet_buffer_push_types(JanetBuffer *buffer, int types);
const JanetKV *janet_dict_find(const JanetKV *buckets, int32_t cap, Janet key);
Janet janet_dict_get(const JanetKV *buckets, int32_t cap, Janet key);
void janet_memempty(JanetKV *mem, int32_t count);
void *janet_memalloc_empty(int32_t count);
const void *janet_strbinsearch(
        const void *tab,
        size_t tabcount,
        size_t itemsize,
        const uint8_t *key);

/* Initialize builtin libraries */
void janet_lib_io(JanetTable *env);
void janet_lib_math(JanetTable *env);
void janet_lib_array(JanetTable *env);
void janet_lib_tuple(JanetTable *env);
void janet_lib_buffer(JanetTable *env);
void janet_lib_table(JanetTable *env);
void janet_lib_fiber(JanetTable *env);
void janet_lib_os(JanetTable *env);
void janet_lib_string(JanetTable *env);
void janet_lib_marsh(JanetTable *env);
void janet_lib_parse(JanetTable *env);
#ifdef JANET_ASSEMBLER
void janet_lib_asm(JanetTable *env);
#endif
void janet_lib_compile(JanetTable *env);
void janet_lib_debug(JanetTable *env);

#endif
