#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string.h>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;
int N, Ncnt;
struct s {
	int key, value;
};
int cp(s a, s b) {
	return a.key < b.key;
}

int main() {
	printf("�н�Ƚ�� �Է�:");
	scanf("%d", &N);
	srand(time(NULL));
	FILE* fp;
	fp = fopen("test.txt", "w");
	if (fp == NULL) printf("���Ͽ��� ����\n");
	else printf("���Ͽ��� ����\n");
	vector<int> v[21],arr;
	char file_buff[100];
	for (int i = 0; i < 20; i++) { //0��° �н�, 20���� �� ����
		int cnt=0;// 111111���� ���̰�(����ġ)
		int num = 0; // ���ڵ��� 6�ڸ� ������ �ٲ۰�
		memset(file_buff, 0, sizeof(file_buff));
		for (int k = 0; k < 6; k++) {
			v[i].push_back(rand() % 2); //���ڸ� ����(�ʱ⼳���̹Ƿ� �������� �Ѵ�)
			if (v[i][k] == 0) cnt++; //111111���� ���� 
			num = num * 10 + v[i][k]; // num ����
			file_buff[k] = 48 + v[i][k];
		}
		v[i].push_back(cnt); //���̰�
		arr.push_back(num);
		file_buff[strlen(file_buff)] = ' ';
		file_buff[strlen(file_buff)] = 48+v[i][6];
		file_buff[strlen(file_buff)] = '\n';

		fputs(file_buff, fp);
	}
	fclose(fp);
	//for (i = 1; i <= 5; i++) {
	//	printf("���Ͽ� ���� ������ �Է��ϼ��� (%d��° ����)\n", i);
	//	memset(file_buff, 0, sizeof(file_buff));
	//	scanf("%s", file_buff);
	//	file_buff[strlen(file_buff)] = '\n';
	//	fputs(file_buff, fp);
	//}
	//fclose(fp);
	memset(file_buff, 0, sizeof(file_buff));
	fp = fopen("test.txt", "r");
	if (fp == NULL) printf("���Ͽ��� ����\n");
	else printf("���Ͽ��� ����\n");
	while (fgets(file_buff, sizeof(file_buff), fp) != NULL) {
		printf("%s", file_buff);
		memset(file_buff, 0, sizeof(file_buff));
	}
	fclose(fp);
	for(int tt=0;tt<N;tt++) {
		//���� �ڵ�
		//printf("==================================================\n");
		fp = fopen("test.txt", "r");
		//system("cls");
		vector<s> v; //2*20 
		s gu;
		int num,tmp=2000000,key;
		for (int i = 0; i < 20; i++) { //������ ���� �� ����
			fscanf(fp, "%d %d", &num, &key);
			//printf("%d %d\n",tmp+ num, key); 
			gu.key = key;
			gu.value = tmp + num;
			v.push_back(gu);
		}
		fclose(fp);
		printf("======================%d��° �н�����============================\n",tt+1);
		sort(v.begin(), v.end(), cp);
		for (int i = 0; i < 20; i++) { //���� �ߵǴ��� üũ (�ߵ�)
			printf("%d %d\n", v[i].value, v[i].key);
		}
		if (v[0].key == 0) {
			printf("%d��° ������ ����.", tt + 1);
			break;
		}
		//����
		fp = fopen("test.txt", "w");
		char numa[3][10] = { 0, };
		for (int i = 0; i < 3; i++) {
			printf("*%d ", v[i].value);
			int tmp = v[i].value;
			for (int j = 5; j >= 0; j--) {
				numa[i][j] = 48 + tmp % 10;
				tmp /= 10;
			}
		}
		for (int i = 0; i < 16; i++) {
			int cnt = 0;// 111111���� ���̰�(����ġ)
			int num = 0; // ���ڵ��� 6�ڸ� ������ �ٲ۰�
			memset(file_buff, 0, sizeof(file_buff));
			
			for (int k = 0; k < 6; k++) {
				file_buff[k] = numa[rand() % 3][k];
				if (file_buff[k] == '0') cnt++; //111111���� ���� 
				num = num * 10 + (file_buff[k]-48); // num ����
			}
			file_buff[strlen(file_buff)] = ' ';
			file_buff[strlen(file_buff)] = 48 + cnt;
			file_buff[strlen(file_buff)] = '\n';
			printf("%s", file_buff);
			fputs(file_buff, fp);
		}
		//����
		for (int i = 0; i < 4; i++) {
			int cnt = 0;// 111111���� ���̰�(����ġ)
			int num = 0; // ���ڵ��� 6�ڸ� ������ �ٲ۰�
			memset(file_buff, 0, sizeof(file_buff));
			for (int k = 0; k < 6; k++) {
				file_buff[k] = 48+rand()%2;
				if (file_buff[k] == '0') cnt++; //111111���� ���� 
				num = num * 10 + (file_buff[k] - 48); // num ����
			}
			file_buff[strlen(file_buff)] = ' ';
			file_buff[strlen(file_buff)] = 48 + cnt;
			file_buff[strlen(file_buff)] = '\n';
			printf("%s", file_buff);
			fputs(file_buff, fp);
		}
		fclose(fp);
	}
	fclose(fp);
	//���� ���� ����
	return 0;
}