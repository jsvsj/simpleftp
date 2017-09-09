#ifndef _SESSION_H_
#define _SESSION_H_

#include "common.h"


//����һ���ͻ��˻Ự�����ݵĽṹ��
typedef struct session
{
	// ��������
	uid_t uid;  //�û�uid

	//�ͻ��˵�������
	int ctrl_fd;


	//��ȡ���Ŀͻ��˷��͵�������
	char cmdline[MAX_COMMAND_LINE];
	char cmd[MAX_COMMAND];
	char arg[MAX_ARG];

	// ��������
	struct sockaddr_in *port_addr;  //portģʽ�±���ͻ���ip �˿�

	int pasv_listen_fd;		//pasvģʽ�� �����׽���
	int data_fd;			//pasv,portģʽ�����������׽���
	int data_process;

	// ����
	unsigned int bw_upload_rate_max;		//����ϴ��ٶ�
	unsigned int bw_download_rate_max;		//��������ٶ�
	long bw_transfer_start_sec;				//��ʼ�������ݵ�ʱ�� ��
	long bw_transfer_start_usec;			//��ʼ�������ݵ�ʱ�� ΢��


	// ���ӽ���ͨ��
	int parent_fd;
	int child_fd;

	// FTPЭ��״̬
	int is_ascii;		//�Ƿ���ASSCIIģʽ
	long long restart_pos;		//�ϵ�λ��
	char *rnfr_name;			//��Ҫ���������ļ���
	int abor_received;			//�Ƿ��յ�abor����

	// ����������
	unsigned int num_clients;
	unsigned int num_this_ip;
} session_t;

void begin_session(session_t *sess);

#endif /* _SESSION_H_ */

