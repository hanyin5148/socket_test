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
		cout << "�Ұʨϥ�Winsock DLL����" << endl;
		return 0;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		WSACleanup();
		cout << "�Ұʨϥ�Winsock DLL����" << endl;
		return 0;
	}
	SOCKADDR_IN addrSrv;//�]�w���A���ݪ�IP�M��
	
//	addrSrv.sin_addr.S_un.S_addr = inet_addr("192.168.1.116");//�s�u�a�}
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//���a�j���a�}
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);//�N��ĤT�Ӥ޼Ƴ]��0�A����۰ʿ�ܨ�ĳ�C
	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));//�P���A���إ߳s�u�C
	
	//FILE* pFile;
	//pFile = fopen("write.txt", "w");

	bool run = true;
	int ret = 0;
	while (run) {
		char recvbuf[255] = { 0 };
		
		CLIENT(sockClient, recvbuf, ret);
		/*
		char recvbuf[255] = { 0 };

		int nNetTimeout = 5000;//5��
		//�o�e�ɭ�
		//setsockopt(sockClient, SOL_SOCKET,SO_SNDTIMEO,(char*) & nNetTimeout, sizeof(int));
		//�����ɭ�
		setsockopt(sockClient, SOL_SOCKET,SO_RCVTIMEO,(char*) & nNetTimeout, sizeof(int));
		// �����
		ret = recv(sockClient, recvbuf, sizeof(recvbuf) - 1, 0);
		if (ret == -1) {
			exit(-1);
		}
		else if (ret == 0) { // ���ݤw�����s�u
			break;
		}

		// ���ƦL�X��
		printf("\n\nRecieved\t : ");
		for (int i = 0; i < 16; ++i)
		{
			printf(" %d ", (unsigned char)recvbuf[i]);
		}
		printf("\n");

		char buf[16] = { 0 };
		printf("Send some message: ");
		// ���o�qconsole��J���@��r��

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

	int nNetTimeout = 5000;//5��
	//�o�e�ɭ�
	//setsockopt(sockClient, SOL_SOCKET,SO_SNDTIMEO,(char*) & nNetTimeout, sizeof(int));
	//�����ɭ�
	setsockopt(CLIENT, SOL_SOCKET, SO_RCVTIMEO, (char*)&nNetTimeout, sizeof(int));
	// �����
	RET = recv(CLIENT, recvbuf, sizeof(recvbuf) - 1, 0);
	if (RET == -1) {
		exit(-1);
	}
	else if (RET == 0) { // ���ݤw�����s�u
		exit(0) ;
	}

	// ���ƦL�X��
	printf("\n\nRecieved\t : ");
	for (int i = 0; i < 16; ++i)
	{
		printf(" %d ", (unsigned char)recvbuf[i]);
	}
	printf("\n");

	char buf[16] = { 0 };
	printf("Send some message: ");
	// ���o�qconsole��J���@��r��

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