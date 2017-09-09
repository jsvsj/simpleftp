#include "common.h"
#include "session.h"
#include "ftpproto.h"
#include "privparent.h"
#include "privsock.h"
#include "sysutil.h"


//开始会话
void begin_session(session_t *sess)
{
	activate_oobinline(sess->ctrl_fd);

	//调用socketpair建立进程间通信的通道
	priv_sock_init(sess);

	pid_t pid;

	//创建进程
	pid = fork();
	if (pid < 0)
		ERR_EXIT("fork");


	//子进程
	if (pid == 0) {

		// ftp服务进程，用于控制连接
		
		//关闭一个用于通信的描述符
		priv_sock_set_child_context(sess);


		handle_child(sess);
	} else {
		// nobody进程
		
		//关闭一个用于通信的描述符
		priv_sock_set_parent_context(sess);


		handle_parent(sess);
	}
}

