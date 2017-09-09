#ifndef _SESSION_H_
#define _SESSION_H_

#include "common.h"


//保存一个客户端会话的数据的结构体
typedef struct session
{
	// 控制连接
	uid_t uid;  //用户uid

	//客户端的描述符
	int ctrl_fd;


	//读取到的客户端发送的命令行
	char cmdline[MAX_COMMAND_LINE];
	char cmd[MAX_COMMAND];
	char arg[MAX_ARG];

	// 数据连接
	struct sockaddr_in *port_addr;  //port模式下保存客户的ip 端口

	int pasv_listen_fd;		//pasv模式下 被动套接字
	int data_fd;			//pasv,port模式下数据连接套接字
	int data_process;

	// 限速
	unsigned int bw_upload_rate_max;		//最大上传速度
	unsigned int bw_download_rate_max;		//最大下载速度
	long bw_transfer_start_sec;				//开始传输数据的时间 秒
	long bw_transfer_start_usec;			//开始传输数据的时间 微秒


	// 父子进程通道
	int parent_fd;
	int child_fd;

	// FTP协议状态
	int is_ascii;		//是否是ASSCII模式
	long long restart_pos;		//断点位置
	char *rnfr_name;			//需要重命名的文件名
	int abor_received;			//是否收到abor命令

	// 连接数限制
	unsigned int num_clients;
	unsigned int num_this_ip;
} session_t;

void begin_session(session_t *sess);

#endif /* _SESSION_H_ */

