#include"Header.h"
void CLIENT_RECV();
//void CLIENT_SEND();


int main()
{

	// execute thread
	thread mThread(CLIENT_RECV);

	// do somthing
	//��L��J
	while(1){
		printf("Send some message: ");
		char* retBuf = fgets(buf, sizeof(buf), stdin);
		if (retBuf[0] == '\n') {
			printf("Close and exit\n");
			exit(-1);
		}
		printf("\n");
		// ��r���@��ưe�X�h
		ret = send(sockClient, retBuf, strlen(retBuf), 0);
		if (ret == -1) {
			exit(-1);
		}
	}
	// wait the thread stop
	mThread.join();

	return 0;

}
	/*void CLIENT_SEND() {
		WORD wVersinRequested;
		WSADATA wsaData;
		int err;
		wVersinRequested = MAKEWORD(2, 2);
		err = WSAStartup(wVersinRequested, &wsaData);
		if (err != 0)
		{
			cout << "�Ұʨϥ�Winsock DLL����" << endl;
			exit(-1);
		}
		if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
		{
			WSACleanup();
			cout << "�Ұʨϥ�Winsock DLL����" << endl;
			exit(-1);
		}
		SOCKADDR_IN addrSrv;//�]�w���A���ݪ�IP�M��

		addrSrv.sin_addr.S_un.S_addr = inet_addr(ADDRESS);//���a�j���a�}
		addrSrv.sin_family = AF_INET;
		addrSrv.sin_port = htons(PORT);
		SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);//�N��ĤT�Ӥ޼Ƴ]��0�A����۰ʿ�ܨ�ĳ�C
		connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));//�P���A���إ߳s�u�C

		bool run = true;
		int i = 0;
		int ret = 0;
		while (run) {

			int nNetTimeout = 5000;//5��
			//�o�e�ɭ�
			setsockopt(sockClient, SOL_SOCKET,SO_SNDTIMEO,(char*) & nNetTimeout, sizeof(int));
			//�����ɭ�
			setsockopt(sockClient, SOL_SOCKET, SO_RCVTIMEO, (char*)&nNetTimeout, sizeof(int));


			char buf[16] = { 0 };
			printf("Send some message: ");

			/*int range_min = 0;
			int range_max = 256;
			for (int i = 0; i < 16; ++i)
			{
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

			//��L��J
			char* retBuf = fgets(buf, sizeof(buf), stdin);
			if (retBuf[0] == '\n') {
				printf("Close and exit\n");
				break;
			}
			// ��r���@��ưe�X�h
			ret = send(sockClient, retBuf, strlen(retBuf), 0);
			if (ret == -1) {
				break;
			}
			i++;
		}
		closesocket(sockClient);
		//fclose(pFile);
		WSACleanup();
	}*/

void CLIENT_RECV(){
	
	wVersinRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersinRequested, &wsaData);
	if (err != 0)
	{
		cout << "�Ұʨϥ�Winsock DLL����" << endl;
		exit(-1);
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		WSACleanup();
		cout << "�Ұʨϥ�Winsock DLL����" << endl;
		exit(-1);
	}

	addrSrv.sin_addr.S_un.S_addr = inet_addr(ADDRESS);//���a�j���a�}
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(PORT);
	sockClient = socket(AF_INET, SOCK_STREAM, 0);//�N��ĤT�Ӥ޼Ƴ]��0�A����۰ʿ�ܨ�ĳ�C
	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));//�P���A���إ߳s�u�C

	bool run = true;
	int ret = 0;
	while (run) {
		char buf[255] = { 0 };

		// �����
		ret = recv(sockClient, buf, sizeof(buf) - 1, 0);
		if (ret == -1) {
			exit(-1);
		}
		else if (ret == 0) { // ���ݤw�����s�u
			break;
		}

		/*// ���ƦL�X��
		printf("\n\nRecieved\t : ");
		for (int i = 0; i < 16; ++i)
		{
			printf(" %d ", (unsigned char)recvbuf[i]);
		}
		printf("\n");*/

		// ���Ʒ�@�r�� �ۤv�b�̫��0 �L�X��
		buf[ret] = '\0';
		printf("Recieved: %s\n", buf);
	}

	closesocket(sockClient);
	//fclose(pFile);
	WSACleanup();
}
