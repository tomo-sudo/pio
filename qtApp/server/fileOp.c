//genernal use
#include "userInfo.h"
int openF(char *name)
{
	int fd = open(name, O_RDWR|O_APPEND);
	if(-1 == fd)
	{
		fd = open(name, O_RDWR|O_APPEND|O_CREAT, 666);

		if(-1 == fd)
		{
			fprintf(stderr, "%s open failed.\n", name);

			close(fd);

			return -1;
		}
		return fd;
	}
		return fd;
}

int openFlash(char *name)
{
	int fd = open(name, O_RDWR);
	if(-1 == fd)
	{
		fd = open(name, O_RDWR|O_CREAT, 666);

		if(-1 == fd)
		{
			fprintf(stderr, "%s open failed.\n", name);

			close(fd);

			return -1;
		}
		return fd;
	}
		return fd;
}






int rdLine(int fd, void *pstr)  //here char *pstr equals to char pstr[]
{
	int length = 0;
	int flag = 0;
	int tmp = 0;
	char info = '0';  // \n is A(10)
	while(info != '\n')  
	{
			if(read(fd, pstr, 1) != 1)
				return -1;

			info = *(char*)pstr;
			pstr++;	
			length++;


	}
	return length;
}

int rdOnceRd(int fd, void *pstr)  
{
	int length = 0;
	int flag = 0;
	int tmp = 0;
	char info = '0';  // \n is A(10)

	while(info != '#') 
	{
			if(read(fd, pstr, 1) != 1)
				return -1;
			info = *(char*)pstr;
			pstr++;	
			length++;


	}
	return length;
}


