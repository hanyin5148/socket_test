#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include <Winsock2.h>
#include<stdlib.h>
#include <thread>
#include <time.h>

using namespace std;

#pragma comment(lib, "ws2_32.lib")


//#define ADDRESS "192.168.1.116"
#define ADDRESS "127.0.0.1"
#define PORT 6000
WORD wVersinRequested;
WSADATA wsaData;
int err, ret = 0;
SOCKADDR_IN addrSrv;//設定伺服器端的IP和埠
SOCKET sockClient;
char buf[255] = { 0 };