/**********************************************************************
* Author：jaron.ho
* Date：2009-9-23 19:00
* Brief：字节流类(网络协议序列化)
**********************************************************************/
#ifndef _BYTE_ARRAY_H_
#define _BYTE_ARRAY_H_

#include <string>

class ByteArray {
public:
	ByteArray();
	virtual ~ByteArray();

public:
	static short swab16(short x);											// 大小端转换(短整型数字转为短整型数字)
	static short swab16_array(char* pBuf);									// 大小端转换(字节流转为短整型数字)

	static int swab32(int x);												// 大小端转换(整型数字转为整型数字)
	static int swab32_array(char* pBuf);									// 大小端转换(字节流转为整型数字)

	static int max_size(void);												// 网络消息最大长度

public:
	void print(void);														// 打印当前内容
	void reuse(void);														// 清空,重新使用当前字节流
	int getCurLength(void);													// 获取字节流当前长度
	const char* getContent(void);											// 获取字节流内容
	bool setContent(const char* content, int len);							// 设置字节流内容
	int space(void);														// 剩余可写空间
	bool copy(const char* buf, int n);										// 拷贝
	
public:
	short read_int16(void);													// 从字节流读取16位整型
	bool write_int16(short value);											// 向字节流写16位整型
	
	unsigned short read_uint16(void);										// 从字节流读取16位无符号整型
	bool write_uint16(unsigned short value);								// 向字节流写16位无符号整型
	
	int read_int(void);														// 从字节流读取32位整型
	bool write_int(int value);												// 向字节流写32位整型
	
	unsigned int read_uint(void);											// 从字节流读取32位整型
	bool write_uint(unsigned int value);									// 向字节流写32位无符号整型

	long read_long(void);													// 从字节流读取长整型
	bool write_long(long value);											// 向字节流写长整型
	
	unsigned long read_ulong(void);											// 从字节流读取无符号长整型
	bool write_ulong(unsigned long value);									// 向字节流写无符号长整型

	long long read_int64(void);												// 从字节流读取64位整型
	bool write_int64(long long value);										// 向字节流写64位整型
	
	unsigned long long read_uint64(void);									// 从字节流读取64位无符号整型
	bool write_uint64(unsigned long long value);							// 向字节流写64位无符号整型

	float read_float(void);													// 从字节流读取浮点数
	bool write_float(float value);											// 向字节流写浮点数
	
	double read_double(void);												// 从字节流读取双精度数
	bool write_double(double value);										// 向字节流写双精度数

	bool read_bool(void);													// 从字节流读取Bool值
	bool write_bool(bool value);											// 向字节流写布尔型

	char read_char(void);													// 从字节流读取字符
	bool write_char(char value);											// 向字节流写字符型
	
	unsigned char read_uchar(void);											// 从字节流读取无符号字符整数
	bool write_uchar(unsigned char value);									// 向字节流写无符号字符型整数

	unsigned char* read_string(unsigned char* info, unsigned int len);		// 从字节流读取字符串
	bool write_string(const char* str);										// 向字节流写字符串
	
	std::string read_string(void);											// 从字节流读取字符串
	bool write_string(const std::string& str);								// 向字节流写字符串

private:
	char* rd_ptr(void);
	char* wr_ptr(void);
	
	bool rd_ptr(int n);
	bool wr_ptr(int n);

private:
	char* m_pContent;			// 字节流内容指针
	int m_nTotalSize;			// 字节流允许大小
	int m_nRdptr;				// 读取位置
	int m_nWrPtr;				// 写入位置
};

#endif	// _BYTE_ARRAY_H_