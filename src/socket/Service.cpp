#include <arpa/inet.h>
#include <errno.h>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

const int MAX_SIZE = 4096;

std::string run_cmd(const std::string &cmd) {
  char buf[MAX_SIZE];
  std::string res;
  FILE *fp = popen(cmd.c_str(), "r");
  if (fp == NULL) {
    return "打开进程失败";
  } else {
    while (!feof(fp)) {
      if (fgets(buf, MAX_SIZE, fp) != NULL) {
        res += buf;
      }
    }
    pclose(fp);
    return res;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    perror("usepage: ./main port");
  }
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0) {
    perror("create socket error!");
  }
  sockaddr_in addr;
  short port = atoi(argv[1]);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  int ret = bind(fd, (sockaddr *)&addr, sizeof(addr));
  if (ret < 0) {
    perror("bind error");
  }
  ret = listen(fd, 1024);
  if (ret < 0) {
    perror("listen error");
  }

  sockaddr_in client;
  socklen_t len = sizeof(client);
  fd = accept(fd, (sockaddr *)&client, &len);
  std::cout << "client fd :" << fd << std::endl;
  if (fd < 0) {
    perror("accept error");
  }
  char buf[MAX_SIZE];
  for (;;) {
    memset(buf, 0, MAX_SIZE);
    int size = read(fd, buf, MAX_SIZE);
    if (size == 0) {
      perror("client close");
    } else if (size < 0) {
      perror("read error");
    }
    std::cout << "recv message size:" << strlen(buf) << "[" << buf << "]"
              << std::endl;
    std::string response("Hi,");
    response += buf;
    size = send(fd, response.c_str(), response.size(), 0);
    if (size < 0) {
      perror("send error");
    }
    std::cout << "send size:" << size << "[" << response << "]" << std::endl;
  }
  return 0;
}