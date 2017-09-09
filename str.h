#ifndef _STR_H_
#define _STR_H_

//去除 \r\n
void str_trim_crlf(char *str);


//分割字符串
void str_split(const char *str , char *left, char *right, char c);


//判断字符串是否都是空格
int str_all_space(const char *str);


//转成大写
void str_upper(char *str);

//得到long long
long long str_to_longlong(const char *str);


//将8进制字符串转换为无符号整数
unsigned int str_octal_to_uint(const char *str);


#endif /* _STR_H_ */

