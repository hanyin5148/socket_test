/*#include"Header.h"
void CLIENT(SOCKET CLIENT, char RECVBUF[], int RET);
int main()
{
	srand(time(0));
	WORD wVersinRequested;
	WSADATA wsaData;
	int err;
	wVersinRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersinRequested, &wsaData);
	if (err != 0)
	{
		cout << "啟動使用Winsock DLL失敗" << endl;
		return 0;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		WSACleanup();
		cout << "啟動使用Winsock DLL失敗" << endl;
		return 0;
	}
	SOCKADDR_IN addrSrv;//設定伺服器端的IP和埠
	
//	addrSrv.sin_addr.S_un.S_addr = inet_addr("192.168.1.116");//連線地址
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//本地迴路地址
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);//將其第三個引數設為0，讓其自動選擇協議。
	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));//與伺服器建立連線。
	
	//FILE* pFile;
	//pFile = fopen("write.txt", "w");

	bool run = true;
	int ret = 0;
	while (run) {
		char recvbuf[255] = { 0 };
		
		CLIENT(sockClient, recvbuf, ret);
		/*
		char recvbuf[255] = { 0 };

		int nNetTimeout = 5000;//5秒
		//發送時限
		//setsockopt(sockClient, SOL_SOCKET,SO_SNDTIMEO,(char*) & nNetTimeout, sizeof(int));
		//接收時限
		setsockopt(sockClient, SOL_SOCKET,SO_RCVTIMEO,(char*) & nNetTimeout, sizeof(int));
		// 收資料
		ret = recv(sockClient, recvbuf, sizeof(recvbuf) - 1, 0);
		if (ret == -1) {
			exit(-1);
		}
		else if (ret == 0) { // 遠端已關閉連線
			break;
		}

		// 把資料印出來
		printf("\n\nRecieved\t : ");
		for (int i = 0; i < 16; ++i)
		{
			printf(" %d ", (unsigned char)recvbuf[i]);
		}
		printf("\n");

		char buf[16] = { 0 };
		printf("Send some message: ");
		// 取得從console輸入的一行字串

		int range_min = 0;
		int range_max = 256;
		for (int i = 0; i < 16; ++i)
		{
			//			buf[i] = (rand()%255)+125;
						//int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min)
			//				+ range_min;
			int u = 50 + (i * 2);
			//fprintf(pFile, "%d", u);
			printf(" %d ", u);
			buf[i] = u;
		}

		//printf("\nsizeof(buf):%d", sizeof(buf));
		ret = send(sockClient, buf, sizeof(buf), 0);
		if (ret == -1) {
			break;
		}
	
	}
	closesocket(sockClient);
	//fclose(pFile);
	WSACleanup();

}
void CLIENT(SOCKET CLIENT, char RECVBUF[], int RET) {
	char recvbuf[255] = { 0 };

	int nNetTimeout = 5000;//5秒
	//發送時限
	//setsockopt(sockClient, SOL_SOCKET,SO_SNDTIMEO,(char*) & nNetTimeout, sizeof(int));
	//接收時限
	setsockopt(CLIENT, SOL_SOCKET, SO_RCVTIMEO, (char*)&nNetTimeout, sizeof(int));
	// 收資料
	RET = recv(CLIENT, recvbuf, sizeof(recvbuf) - 1, 0);
	if (RET == -1) {
		exit(-1);
	}
	else if (RET == 0) { // 遠端已關閉連線
		exit(0) ;
	}

	// 把資料印出來
	printf("\n\nRecieved\t : ");
	for (int i = 0; i < 16; ++i)
	{
		printf(" %d ", (unsigned char)recvbuf[i]);
	}
	printf("\n");

	char buf[16] = { 0 };
	printf("Send some message: ");
	// 取得從console輸入的一行字串

	int range_min = 0;
	int range_max = 256;
	for (int i = 0; i < 16; ++i)
	{
		//			buf[i] = (rand()%255)+125;
					//int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min)
		//				+ range_min;
		int u = 50 + (i * 2);
		//fprintf(pFile, "%d", u);
		printf(" %d ", u);
		buf[i] = u;
	}

	//printf("\nsizeof(buf):%d", sizeof(buf));
	RET = send(CLIENT, buf, sizeof(buf), 0);
	if (RET == -1) {
		exit(0);
	}
}*/