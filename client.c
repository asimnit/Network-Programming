#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
int main()
{
   int sockfd;
   struct sockaddr_in serv_addr;
   int i;
   char buf[100];
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if(sockfd < 0)
   {
      printf("Unable to create socket\n");
      exit(0);
   }
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr =  INADDR_ANY;
   serv_addr.sin_port = htons(6000);
   connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
   printf("Enter the expression: ");
   gets(buf);
   send(sockfd, buf, strlen(buf) + 1, 0);
  /* if(buf[0] == '-' && buf[1] == '1')
   break;*/
   int ans;
   recv(sockfd, &ans, sizeof(ans), 0);
   printf("\nThe result is: %d\n", ans);
   close(sockfd);
   return 0;
}
