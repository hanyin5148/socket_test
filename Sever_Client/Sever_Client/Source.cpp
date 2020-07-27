#include"Header.h"
void SEVER_RECV();
//void SEVER_SEND();
WSADATA wsaData;
SOCKET sockSrv;
SOCKADDR_IN addrSrv;
SOCKADDR_IN addrClient;//用來接受客戶端的地址資訊
int len = sizeof(SOCKADDR);
int err, ret = 0;
WORD wVersionRequested;//用來儲存Winsock庫的版本號
SOCKET sockConn;
char buf[256] = { 0 };

int main()
{
	// execute thread
	thread mThread(SEVER_RECV);

	// do somthing
	while(1){
		printf("Send some message:");
		// 從console輸入一行字
		char* retBuf = fgets(buf, sizeof(buf), stdin);
		if (retBuf[0] == '\n') {
			closesocket(sockConn);
			exit(-1);
		}
		printf("\n");

		
		// 把這行字當作資料送出去
		ret = send(sockConn, retBuf, strlen(retBuf), 0);
		if (ret == -1) {
			closesocket(sockConn);
			exit(-1);
		}
	}
	// wait the thread stop
	mThread.join();

	return 0;
}
/*
void SEVER_SEND() {
	WSADATA wsaData;
	SOCKET sockSrv;
	SOCKADDR_IN addrSrv;
	SOCKADDR_IN addrClient;//用來接受客戶端的地址資訊
	int len = sizeof(SOCKADDR);
	int err;
	WORD wVersionRequested;//用來儲存Winsock庫的版本號

	wVersionRequested = MAKEWORD(2, 2);//建立一個包含了請求版本號的WORD值
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		cout << "啟動使用Winsock DLL失敗" << endl;
		exit(-1);
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		WSACleanup();
		cout << "啟動使用Winsock DLL失敗" << endl;
		exit(-1);
	}
	sockSrv = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//建立套接字
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(PORT);
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));//將套接字繫結到本地址和指定埠號上

	listen(sockSrv, 5);
	SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);

	bool run = true;
	char buf[256] = { 0 };
	int ret = 0;
	int i = 0;

	while (i!=10) {

		printf("\nSend some message: ");
		// 從console輸入一行字
		char* retBuf = fgets(buf, sizeof(buf), stdin);
		if (retBuf[0] == '\n') {
			closesocket(sockConn);
			break;
		}

		// 把這行字當作資料送出去
		ret = send(sockConn, retBuf, strlen(retBuf), 0);
		if (ret == -1) {
			closesocket(sockConn);
			break;
		}
		i++;
	}
	closesocket(sockConn);
}
*/
void SEVER_RECV() {
	

	wVersionRequested = MAKEWORD(2, 2);//建立一個包含了請求版本號的WORD值
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		cout << "啟動使用Winsock DLL失敗" << endl;
		exit(-1);
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		WSACleanup();
		cout << "啟動使用Winsock DLL失敗" << endl;
		exit(-1);
	}
	sockSrv = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//建立套接字
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));//將套接字繫結到本地址和指定埠號上

	listen(sockSrv, 5);
	sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);

	bool run = true;
	
	int ret = 0;

	while (run) {

		// 收資料
		ret = recv(sockConn, buf, sizeof(buf) - 1, 0);
		if (ret == -1) {
			exit(-2);
		}
		else if (ret == 0) { // 遠端已關閉連線
			closesocket(sockConn);
			break;
		}

		// 把收到的資料當作字串 後面補0 並印出
		buf[ret] = '\0';
		printf("Recieved: %s\n", buf);
		/*
		for (int i = 0; i < 16; ++i)
		{
			printf(" %d ", (unsigned char)buf[i]);
		}
		printf("\n ");*/
	}
	closesocket(sockConn);
}