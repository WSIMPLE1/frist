#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>
#include<ctype.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#define SERV_PORT 9511

void sys_err(const char*str)
{
perror(str);
exit(1);
}
int main( int argc,char*argv[])
{
int lfd=0;
int cfd=0;
int ret;
char buf[BUFSIZ],clit_ip[1024]; 
struct sockaddr_in ser_addr,clit_addr;
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
if(bin==-1)
{sys_err("bind error");
}
listen(lfd,20);
clit_addr_len=sizeof(clit_addr);
cfd=accept(lfd,(struct sockaddr*)&clit_addr,&clit_addr_len);

printf("clint id:%s,port:%d\n",inet_ntop(AF_INET,&clit_addr.sin_addr,clit_ip,sizeof(clit_ip)),ntohs(clit_addr.sin_port));
 printf("hello,world");

if(cfd==-1)
{sys_err("accpect error");
}
while(1)
{
ret=read(cfd,buf,sizeof(buf));

 write(STDOUT_FILENO,buf,ret);
for(int i=0;i<ret;i++)
    buf[i]=toupper(buf[i]);

    write(cfd,buf,ret);
}

close(lfd);
close(cfd);

return 0;
}
