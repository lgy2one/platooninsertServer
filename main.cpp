/******************************************************
 *Copyright 2020, Li GuoYan.
 *
 *Author: Li GuoYan
******************************************************/
#include <signal.h>
#include "EventLoop.h"
#include "EchoServer.h"

EventLoop *lp;

static void sighandler1( int sig_no )
{
    exit(0);
}
static void sighandler2( int sig_no )
{
    lp->Quit();
}

int main(int argc, char *argv[])
{
    signal(SIGUSR1, sighandler1);
    signal(SIGUSR2, sighandler2);
    signal(SIGINT, sighandler2);
    signal(SIGPIPE, SIG_IGN);   //SIG_IGN,系统函数，忽略信号的处理程序,
                                //客户端发送RST包后，服务器还调用write会触发

    int port = 8080;
    int ioThreadNum = 4;

    if(argc == 3)
    {
        port = atoi(argv[1]);
        ioThreadNum = atoi(argv[2]);
    }

    EventLoop loop;
    lp = &loop;

    /*EchoServer is used to test tcpServer*/
    EchoServer echoServer(&loop, port, ioThreadNum);
    echoServer.Start();

    try
    {
        loop.loop();
    }
    catch (std::bad_alloc& ba)   //cerr：输出错误信息   bad_alloc：内存分配错误类
    {
        std::cerr << "bad_alloc caught in ThreadPool::ThreadFunc task: " << ba.what() << '\n';
    }
}
