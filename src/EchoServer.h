/*****************************
 *Copyright 2020, Li GuoYan.
 *
 *Author: Li GuoYan
 *
 *EchoServer:回显服务器
******************************/

#ifndef _ECHO_SERVER_H_
#define _ECHO_SERVER_H_

#include <string>
#include "TcpServer.h"
#include "EventLoop.h"
#include "TcpConnection.h"

class EchoServer
{
public:
    typedef std::shared_ptr<TcpConnection> spTcpConnection;

    EchoServer(EventLoop* loop, const int port, const int threadnum);
    ~EchoServer();

    //启动服务
    void Start();

private:
    /* data */
    //业务函数
    void HandleNewConnection(const spTcpConnection& sptcpconn);
    void HandleMessage(const spTcpConnection &sptcpconn, std::string &s);
    void HandleSendComplete(const spTcpConnection& sptcpconn);
    void HandleClose(const spTcpConnection& sptcpconn);
    void HandleError(const spTcpConnection& sptcpconn);

    TcpServer tcpserver_;
};

#endif
