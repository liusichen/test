/*
*   学习socket编程
*   简单的tcpserver程序
*   Usage:./tcpserver port
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define BUFFSIZE 1024

#if 0
/* 
    * Structs exported from in.h
     */

/* Internet address */
struct in_addr {
      unsigned int s_addr; 
};

/* Internet style socket address */
struct sockaddr_in  {
      unsigned short int sin_family; /* Address family */
        unsigned short int sin_port;   /* Port number */
          struct in_addr sin_addr;   /* IP address */
            unsigned char sin_zero[...];   /* Pad to size of 'struct sockaddr' */
};

/*
    * Struct exported from netdb.h
     */

/* Domain name service (DNS) host entry */
struct hostent {
      char    *h_name;        /* official name of host */
        char    **h_aliases;    /* alias list */
          int     h_addrtype;     /* host address type */
            int     h_length;       /* length of address */
              char    **h_addr_list;  /* list of addresses */
}
#endif

/*
    * error - wrapper for perror
     */
void error(char *msg) {
      perror(msg);
        exit(1);
}

int main(int argc, char **argv) {
      int parentfd; /* parent socket */
      int childfd; /* child socket */
      int clientlen; /* byte size of client's address */
      pid_t childpid;
      struct sockaddr_in serveraddr; /* server's addr */
      struct sockaddr_in clientaddr; /* client addr */
      char buf[BUFFSIZE]; /* message buffer */
      int optval; /* flag value for setsockopt */
      int n; /* message byte size */
      parentfd = socket(AF_INET, SOCK_STREAM, 0);
      if (parentfd < 0) 
          error("ERROR opening socket");
      bzero((char *) &serveraddr, sizeof(serveraddr));
      
      serveraddr.sin_family = AF_INET;
      serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
      serveraddr.sin_port = htons(9877);

      if (bind(parentfd, (struct sockaddr *) &serveraddr,
                  sizeof(serveraddr)) < 0) 
          error("ERROR on binding");
      if (listen(parentfd, 5) < 0) /* allow 5 requests to queue up */
          error("ERROR on listen");
                                                    
      while (1) {
          clientlen = sizeof(clientaddr);
          childfd = accept(parentfd, (struct sockaddr *) &clientaddr, &clientlen);
          if (childfd < 0) 
              error("ERROR on accept");
                                                                      
          if((childpid = fork()) == 0){
              close(parentfd);
              while ( (n = read(childfd, buf, BUFFSIZE)) > 0)
                   write(childfd, buf, n);

              if(n < 0) 
                  error("str_echo: read error");
              exit(0);
          }
          close(childfd);
      }
}
