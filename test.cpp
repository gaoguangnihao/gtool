#include <stdio.h>

#include<unistd.h>/*#包含<unistd.h>*/
#include<sys/types.h>/*#包含<sys/types.h>*/
#include <sys/wait.h>

#include "headers.h"

class A {
public:
	A(){
		pStr = new char[10];
		printf("constructor!\n");
	};
	~A(){
		pStr = NULL;
		printf("destructor!!\n");
	};
	
	void f1(){
		printf("A f1 be called %d\n", pStr[3]);
	}

	bool mParam = false;
private:
	char* pStr;
};

extern "C" int do_main (char **token, int len) {
  int fd[2];
  pid_t pid = -1;
  char str[1024] = "Hello pipe~~~";
  char buf[1024] = {'\0'};

  if (pipe(fd) < 0) {
    perror("pipe");
    exit(1);
  }

  if (( pid = fork()) == 0) {   // child
    close(fd[1]);
    int len = 0;
    printf("read \n");
    printf("read len %d, buf %s\n", len, buf);
    len = read(fd[0], buf, 1024);
    printf("read %s, len %d\n", buf, len);

    write(STDOUT_FILENO, buf, len);
    exit(0);
  }
  else {                   // parent
    close(fd[0]);
    sleep(10);
    printf("write %s, %d\n", str, sizeof(str));
    write(fd[1], str, sizeof(str));
    printf("write done\n");
    wait(NULL);
    printf("wait done, exit\n");
  }
  return 0;
}