#ifndef PROXY
#define PROXY

#include "standard.h"
#include "proxy_parse.h"

enum Protocol { PLAIN, HTTP };
enum Direction { IN, OUT };

class ProxySocket {
public:
    int fd;
    struct sockaddr_in servAddr;
    struct hostent *server;

    Protocol protocol;

    int a, b, retval;
    bool connectionBroken, gotHttpHeaders;

    ProxySocket(int, Protocol);
    ProxySocket(char *, int, Protocol);

    int recvFromSocket(std::vector<char> &buffer, int);
    int sendFromSocket(std::vector<char> &buffer, int len, int from);
    void closeSocket();
};

#endif