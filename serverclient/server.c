/******* 服务器程序  (server.c) ************/
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
        int sockfd,new_fd;
        struct sockaddr_in server_addr;
        struct sockaddr_in client_addr;
        int sin_size,portnumber;
        char hello[]="Hello! Are You Fine?\n";

        if(argc!=2)
        {
                fprintf(stderr,"Usage:%s portnumber\a\n",argv[0]);
                exit(1);
        }

        if((portnumber=atoi(argv[1]))<0)
        {
                fprintf(stderr,"Usage:%s portnumber\a\n",argv[0]);
                exit(1);
        }
		printf("portnumber:%d\n",portnumber);

        /* 服务器端开始建立socket描述符 */
        if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)  
        {
                fprintf(stderr,"Socket error:%s\n\a",strerror(errno));
                exit(1);
        }
		printf("sockfd:%d\n",sockfd);

        /* 服务器端填充 sockaddr结构  */ 
        bzero(&server_addr,sizeof(struct sockaddr_in));
        server_addr.sin_family=AF_INET;
        server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
        server_addr.sin_port=htons(portnumber);
		printf("info list=======================\n");
		printf("server:sin_family:%d\n",server_addr.sin_family);
		printf("server:s_addr:%d\n",server_addr.sin_addr.s_addr);
		printf("server:port:%d\n",server_addr.sin_port);

        /* 捆绑sockfd描述符  */ 
        if(bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
        {
                fprintf(stderr,"Bind error:%s\n\a",strerror(errno));
                exit(1);
        }

        /* 监听sockfd描述符  */
        if(listen(sockfd,5)==-1)
        {
                fprintf(stderr,"Listen error:%s\n\a",strerror(errno));
                exit(1);
        }

        while(1)
        {
                /* 服务器阻塞,直到客户程序建立连接  */
                sin_size=sizeof(struct sockaddr_in);
				printf("sin_size:%d\n",sin_size);
                if((new_fd=accept(sockfd,(struct sockaddr *)(&client_addr),&sin_size))==-1)
                {
                        fprintf(stderr,"Accept error:%s\n\a",strerror(errno));
                        exit(1);
                }
				printf("new fd:%d\n",new_fd);
			
                fprintf(stderr,"Server get connection from %s\n",
                inet_ntoa(client_addr.sin_addr));
                if(write(new_fd,hello,strlen(hello))==-1)
                {
                        fprintf(stderr,"Write Error:%s\n",strerror(errno));
                        exit(1);
                }
                /* 这个通讯已经结束     */
                close(new_fd);
                /* 循环下一个     */  
        }
        close(sockfd);
        exit(0);
}
