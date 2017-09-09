#include "common.h"
#include "session.h"
#include "ftpproto.h"
#include "privparent.h"
#include "privsock.h"
#include "sysutil.h"


//��ʼ�Ự
void begin_session(session_t *sess)
{
	activate_oobinline(sess->ctrl_fd);

	//����socketpair�������̼�ͨ�ŵ�ͨ��
	priv_sock_init(sess);

	pid_t pid;

	//��������
	pid = fork();
	if (pid < 0)
		ERR_EXIT("fork");


	//�ӽ���
	if (pid == 0) {

		// ftp������̣����ڿ�������
		
		//�ر�һ������ͨ�ŵ�������
		priv_sock_set_child_context(sess);


		handle_child(sess);
	} else {
		// nobody����
		
		//�ر�һ������ͨ�ŵ�������
		priv_sock_set_parent_context(sess);


		handle_parent(sess);
	}
}

