
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>
#include<ctype.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<strings.h>
#define SERV_PORT 9511

void sys_err(const char*str)
{
perror(str);
exit(1);
}
int main( int argc,char*argv[])
{
pid_t=pid;
int lfd=0;
int cfd=0;
int ret;
char buf[BUFSIZ],clit_ip[1024]; 
struct sockaddr_in ser_addr,clit_addr;
socket_len clit_addr_len;
bzero(&ser_addr,sizeof(ser_addr))
socklen_t clit_addr_len;
lfd=socket(AF_INET,SOCK_STREAM,0);
  if(lfd==-1)
  {
  sys_err("socket error");
  
}
int bin;
ser_addr.sin_family=AF_INET;
ser_addr.sin_port=htons(SERV_PORT);
ser_addr.sin_addr.s_addr=htonl(INADDR_ANY);
bin=bind(lfd,(struct sockaddr*)&ser_addr,sizeof(ser_addr));
listen(lfd,20);
clit_addr_len=sizeof(clit_addr)
while(1)
{
	cfd=accept(lfd,(struct sockaddr*)&clit_addr,&clit_addr_len);
	pid=fork();
	if(pid<0)

	{
		sys_err("pid error");
	}else if(pid==0){
		break;
	}else{
	}

	
}
if(pid==0)
{
	ret=read(
}





