#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
int main()
{
   int sockfd, newsockfd;
   int clilen;
   struct sockaddr_in     cli_addr, serv_addr;
   char op = '\0', c;
   int i, j;
   int sum;
   char s[10];
   char buf[100];
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if(sockfd < 0)
   {
       printf("Can not creat socket\n");
       exit(0);
   }
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(6000);
   bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
   listen(sockfd, 5);
   while(1)
  {
      
   clilen = sizeof(cli_addr);
   newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
   if(newsockfd < 0)
   {
      printf("Accept error\n");
      exit(0);
   }
    recv(newsockfd, buf, 100, 0);
    printf("%s\n", buf);
    if(buf[0] == '-' && buf[1] == '1')
    break;
    
     sum = 0;
     for(j=0; j<10; j++) s[j] = '\0';
    for(i = 0; buf[i] != 0; i++)
   {
      if(buf[i] == '-' || buf[i] == '+' || buf[i] == '*' || buf[i] == '/')
      {
        switch(op)
         {
            case '\0':
            sum = sum + atoi(s);
            op = buf[i];
            for(j=0; j<10; j++) s[j] = '\0';
            break;
            case '+':
            sum = sum + atoi(s);
            op = buf[i];
            for(j=0; j<10; j++) s[j] = '\0';
            break;
            case '-':
            sum = sum - atoi(s);
            op = buf[i];
            for(j=0; j<10; j++) s[j] = '\0';
            break;
            case '*':
            sum = sum * atoi(s);
            op = buf[i];
            for(j=0; j<10; j++) s[j] = '\0';
            break;
            case '/':
            sum = sum / atoi(s);
            op = buf[i];
            for(j=0; j<10; j++) s[j] = '\0';
            break;
          }
      }
          else
         {
            s[strlen(s)] = buf[i]; 
         }
   }
   
   switch(op)
   {
      case '+':
      sum+=atoi(s);
      break;
      case '*':
      sum *= atoi(s);
      break;
      case '-':
      sum-=atoi(s);
      break;
      case '/':
      sum/=atoi(s);
      break;
   }
   send(newsockfd, &sum, sizeof(sum), 0);
    close(newsockfd);
 }
  
   return 0;
}
