#ifndef _TUNABLE_H_
#define _TUNABLE_H_



//������
extern int tunable_pasv_enable;  //�Ƿ�������ģʽ
extern int tunable_port_enable;		//�Ƿ�������ģʽ
extern unsigned int tunable_listen_port;		//�˿�
extern unsigned int tunable_max_clients;		//���������
extern unsigned int tunable_max_per_ip;			//ÿ��ip���������
extern unsigned int tunable_accept_timeout;		//accept��ʱʱ��
extern unsigned int tunable_connect_timeout;			//connect��ʱʱ��
extern unsigned int tunable_idle_session_timeout;		//�������ӳ�ʱʱ��
extern unsigned int tunable_data_connection_timeout;	//�������ӳ�ʱʱ��
extern unsigned int tunable_local_umask;				//����
extern unsigned int tunable_upload_max_rate;			//����ϴ��ٶ�
extern unsigned int tunable_download_max_rate;			//��������ٶ�
extern const char *tunable_listen_address;				//ip��ַ


#endif /* _TUNABLE_H_ */

