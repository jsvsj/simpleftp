#ifndef _SYS_UTIL_H_
#define _SYS_UTIL_H_

#include "common.h"

int tcp_client(unsigned short port);

//socket  bind  listen
int tcp_server(const char *host, unsigned short port);


//获取本地ip
int getlocalip(char *ip);


//设置描述符非阻塞
void activate_nonblock(int fd);

//阻塞
void deactivate_nonblock(int fd);



int read_timeout(int fd, unsigned int wait_seconds);
int write_timeout(int fd, unsigned int wait_seconds);
int accept_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds);
int connect_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds);


//读取count字节
ssize_t readn(int fd, void *buf, size_t count);

//发送count字节
ssize_t writen(int fd, const void *buf, size_t count);
ssize_t recv_peek(int sockfd, void *buf, size_t len);

//读取一行
ssize_t readline(int sockfd, void *buf, size_t maxline);


//进程之间传递套接字
void send_fd(int sock_fd, int fd);
int recv_fd(const int sock_fd);


const char* statbuf_get_perms(struct stat *sbuf);
const char* statbuf_get_date(struct stat *sbuf);


int lock_file_read(int fd);
int lock_file_write(int fd);
int unlock_file(int fd);

long get_time_sec(void);
long get_time_usec(void);
void nano_sleep(double seconds);


// 开启套接字fd接收带外数据的功能
void activate_oobinline(int fd);


void activate_sigurg(int fd);
#endif /* _SYS_UTIL_H_ */

