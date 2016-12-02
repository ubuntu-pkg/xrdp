/**
 * xrdp: A Remote Desktop Protocol server.
 *
 * Copyright (C) Jay Sorg 2004-2014
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * generic operating system calls
 */

#if !defined(OS_CALLS_H)
#define OS_CALLS_H

#ifndef NULL
#define NULL 0
#endif

#include <stdlib.h>
#include "arch.h"

#define g_tcp_can_recv g_sck_can_recv
#define g_tcp_can_send g_sck_can_send
#define g_tcp_recv g_sck_recv
#define g_tcp_send g_sck_send
#define g_tcp_close g_sck_close
#define g_tcp_last_error_would_block g_sck_last_error_would_block
#define g_tcp_set_non_blocking g_sck_set_non_blocking
#define g_tcp_local_socket g_sck_local_socket
#define g_tcp_local_connect g_sck_local_connect
#define g_tcp_listen g_sck_listen
#define g_tcp_local_bind g_sck_local_bind
#define g_tcp_select g_sck_select
#define g_close_wait_obj g_delete_wait_obj

int APP_CC      g_rm_temp_dir(void);
int APP_CC      g_mk_temp_dir(const char* app_name);
void APP_CC     g_init(const char* app_name);
void APP_CC     g_deinit(void);
void* APP_CC    g_malloc(int size, int zero);
void APP_CC     g_free(void* ptr);
void DEFAULT_CC g_printf(const char *format, ...) printflike(1, 2);
void DEFAULT_CC g_sprintf(char* dest, const char* format, ...) \
                  printflike(2, 3);
int DEFAULT_CC  g_snprintf(char* dest, int len, const char* format, ...) \
                  printflike(3, 4);
void DEFAULT_CC g_writeln(const char* format, ...) printflike(1, 2);
void DEFAULT_CC g_write(const char* format, ...) printflike(1, 2);
void APP_CC     g_hexdump(const char *p, int len);
void APP_CC     g_memset(void* ptr, int val, int size);
void APP_CC     g_memcpy(void* d_ptr, const void* s_ptr, int size);
int APP_CC      g_getchar(void);
int APP_CC      g_tcp_set_no_delay(int sck);
int APP_CC      g_tcp_set_keepalive(int sck);
int APP_CC      g_tcp_socket(void);
int APP_CC      g_sck_set_send_buffer_bytes(int sck, int bytes);
int APP_CC      g_sck_get_send_buffer_bytes(int sck, int *bytes);
int APP_CC      g_sck_set_recv_buffer_bytes(int sck, int bytes);
int APP_CC      g_sck_get_recv_buffer_bytes(int sck, int *bytes);
int APP_CC      g_sck_local_socket(void);
int APP_CC      g_sck_get_peer_cred(int sck, int *pid, int *uid, int *gid);
void APP_CC     g_sck_close(int sck);
int APP_CC      g_tcp_connect(int sck, const char* address, const char* port);
int APP_CC      g_sck_local_connect(int sck, const char* port);
int APP_CC      g_sck_set_non_blocking(int sck);
int APP_CC      g_tcp_bind(int sck, const char *port);
int APP_CC      g_sck_local_bind(int sck, const char* port);
int APP_CC      g_tcp_bind_address(int sck, const char* port, const char* address);
int APP_CC      g_sck_listen(int sck);
int APP_CC      g_tcp_accept(int sck);
int APP_CC      g_sck_accept(int sck, char *addr, int addr_bytes,
                             char *port, int port_bytes);
int APP_CC      g_sck_recv(int sck, void* ptr, int len, int flags);
int APP_CC      g_sck_send(int sck, const void* ptr, int len, int flags);
int APP_CC      g_sck_last_error_would_block(int sck);
int APP_CC      g_sck_socket_ok(int sck);
int APP_CC      g_sck_can_send(int sck, int millis);
int APP_CC      g_sck_can_recv(int sck, int millis);
int APP_CC      g_sck_select(int sck1, int sck2);
void APP_CC     g_write_ip_address(int rcv_sck, char* ip_address, int bytes);
void APP_CC     g_sleep(int msecs);
tintptr APP_CC  g_create_wait_obj(const char *name);
tintptr APP_CC  g_create_wait_obj_from_socket(tintptr socket, int write);
void APP_CC     g_delete_wait_obj_from_socket(tintptr wait_obj);
int APP_CC      g_set_wait_obj(tintptr obj);
int APP_CC      g_reset_wait_obj(tintptr obj);
int APP_CC      g_is_wait_obj_set(tintptr obj);
int APP_CC      g_delete_wait_obj(tintptr obj);
int APP_CC      g_obj_wait(tintptr* read_objs, int rcount, tintptr* write_objs,
                           int wcount,int mstimeout);
void APP_CC     g_random(char* data, int len);
int APP_CC      g_abs(int i);
int APP_CC      g_memcmp(const void* s1, const void* s2, int len);
int APP_CC      g_file_open(const char* file_name);
int APP_CC      g_file_open_ex(const char *file_name, int aread, int awrite,
                               int acreate, int atrunc);
int APP_CC      g_file_close(int fd);
int APP_CC      g_file_read(int fd, char* ptr, int len);
int APP_CC      g_file_write(int fd, const char *ptr, int len);
int APP_CC      g_file_seek(int fd, int offset);
int APP_CC      g_file_lock(int fd, int start, int len);
int APP_CC      g_chmod_hex(const char* filename, int flags);
int APP_CC      g_chown(const char* name, int uid, int gid);
int APP_CC      g_mkdir(const char* dirname);
char* APP_CC    g_get_current_dir(char* dirname, int maxlen);
int APP_CC      g_set_current_dir(const char *dirname);
int APP_CC      g_file_exist(const char* filename);
int APP_CC      g_directory_exist(const char* dirname);
int APP_CC      g_create_dir(const char* dirname);
int APP_CC      g_create_path(const char* path);
int APP_CC      g_remove_dir(const char* dirname);
int APP_CC      g_file_delete(const char* filename);
int APP_CC      g_file_get_size(const char* filename);
int APP_CC      g_strlen(const char* text);
const char *APP_CC g_strchr(const char *text, int c);
char* APP_CC    g_strcpy(char* dest, const char* src);
char* APP_CC    g_strncpy(char* dest, const char* src, int len);
char* APP_CC    g_strcat(char* dest, const char* src);
char* APP_CC    g_strdup(const char* in);
char* APP_CC    g_strndup(const char* in, const unsigned int maxlen);
int APP_CC      g_strcmp(const char* c1, const char* c2);
int APP_CC      g_strncmp(const char* c1, const char* c2, int len);
int APP_CC      g_strncmp_d(const char* c1, const char* c2, const char delim, int len);
int APP_CC      g_strcasecmp(const char* c1, const char* c2);
int APP_CC      g_strncasecmp(const char* c1, const char* c2, int len);
int APP_CC      g_atoi(const char* str);
int APP_CC      g_htoi(char* str);
int APP_CC      g_pos(const char* str, const char* to_find);
int APP_CC      g_mbstowcs(twchar* dest, const char* src, int n);
int APP_CC      g_wcstombs(char* dest, const twchar* src, int n);
int APP_CC      g_strtrim(char* str, int trim_flags);
long APP_CC     g_load_library(char* in);
int APP_CC      g_free_library(long lib);
void* APP_CC    g_get_proc_address(long lib, const char* name);
int APP_CC      g_system(char* aexec);
char* APP_CC    g_get_strerror(void);
int APP_CC      g_get_errno(void);
int APP_CC      g_execvp(const char* p1, char* args[]);
int APP_CC      g_execlp3(const char* a1, const char* a2, const char* a3);
void APP_CC     g_signal_child_stop(void (*func)(int));
void APP_CC     g_signal_segfault(void (*func)(int));
void APP_CC     g_signal_hang_up(void (*func)(int));
void APP_CC     g_signal_user_interrupt(void (*func)(int));
void APP_CC     g_signal_terminate(void (*func)(int));
void APP_CC     g_signal_pipe(void (*func)(int));
void APP_CC     g_signal_usr1(void (*func)(int));
int APP_CC      g_fork(void);
int APP_CC      g_setgid(int pid);
int APP_CC      g_initgroups(const char* user, int gid);
int APP_CC      g_getuid(void);
int APP_CC      g_getgid(void);
int APP_CC      g_setuid(int pid);
int APP_CC      g_setsid(void);
int APP_CC      g_setlogin(const char *name);
int APP_CC      g_waitchild(void);
int APP_CC      g_waitpid(int pid);
void APP_CC     g_clearenv(void);
int APP_CC      g_setenv(const char* name, const char* value, int rewrite);
char* APP_CC    g_getenv(const char* name);
int APP_CC      g_exit(int exit_code);
int APP_CC      g_getpid(void);
int APP_CC      g_sigterm(int pid);
int APP_CC      g_getuser_info(const char* username, int* gid, int* uid, char** shell,
                               char** dir, char** gecos);
int APP_CC      g_getgroup_info(const char* groupname, int* gid);
int APP_CC      g_check_user_in_group(const char* username, int gid, int* ok);
int APP_CC      g_time1(void);
int APP_CC      g_time2(void);
int APP_CC      g_time3(void);
int APP_CC      g_save_to_bmp(const char* filename, char* data, int stride_bytes,
                              int width, int height, int depth, int bits_per_pixel);
int APP_CC      g_text2bool(const char *s);
void * APP_CC   g_shmat(int shmid);
int APP_CC      g_shmdt(const void *shmaddr);
int APP_CC      g_gethostname(char *name, int len);
int APP_CC      g_mirror_memcpy(void *dst, const void *src, int len);

/* glib-style wrappers */
#define g_new(struct_type, n_structs) \
    (struct_type *) malloc(sizeof(struct_type) * (n_structs))
#define g_new0(struct_type, n_structs) \
    (struct_type *) calloc((n_structs), sizeof(struct_type))

#endif
