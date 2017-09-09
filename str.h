#ifndef _STR_H_
#define _STR_H_

//ȥ�� \r\n
void str_trim_crlf(char *str);


//�ָ��ַ���
void str_split(const char *str , char *left, char *right, char c);


//�ж��ַ����Ƿ��ǿո�
int str_all_space(const char *str);


//ת�ɴ�д
void str_upper(char *str);

//�õ�long long
long long str_to_longlong(const char *str);


//��8�����ַ���ת��Ϊ�޷�������
unsigned int str_octal_to_uint(const char *str);


#endif /* _STR_H_ */

