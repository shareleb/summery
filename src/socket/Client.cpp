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

int main(int argc, char *argv[]) {
  if (argc != 3) {
    perror("usepage: ./main ip port");
  }
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0) {
    perror("create socket error!");
  }
  sockaddr_in addr;
  short port = atoi(argv[2]);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
    std::cout << "inet_pton host :" << argv[1] << " error!!!" << std::endl;
    return -1;
  }

  int ret = connect(fd, (sockaddr *)&addr, sizeof(addr));
  if (ret < 0) {
    perror("connect error");
  }
  char buff[MAX_SIZE];
  memset(buff, MAX_SIZE, 0);
  while (true) {
    std::string message;
    std::cin >> message;

    int size = send(fd, message.c_str(), message.size(), 0);
    if (size < 0) {
      perror("send error");
    }
    std::cout << "send message size:" << size << "[" << message << "]"
              << std::endl;
    memset(buff, MAX_SIZE, 0);
    size = read(fd, buff, MAX_SIZE);
    if (size == 0) {
      perror("service close");
    } else if (size < 0) {
      perror("read error");
    }
    std::cout << "size:" << size << "[" << buff << "]" << std::endl;
  }
  return 0;
}