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
	fp = fopen("test.txt", "r");
	while (N--) {
		//���� �ڵ�
		printf("==================================================\n");
		//system("cls");
		vector<s> v; //2*20 
		s gu;
		int num,tmp=2000000,key;
		for (int i = 0; i < 20; i++) { //������ ���� �� ����
			fscanf(fp, "%d %d", &num, &key);
			printf("%d %d\n",tmp+ num, key);
			gu.key = key;
			gu.value = tmp + num;
			v.push_back(gu);
		}
		printf("==================================================\n");
		sort(v.begin(), v.end(), cp);
		for (int i = 0; i < 20; i++) { //���� �ߵǴ��� üũ (�ߵ�)
			printf("%d %d\n", v[i].value, v[i].key);
		}
		//����
		for (int i = 0; i < 16; i++) {
			int cnt = 0;// 111111���� ���̰�(����ġ)
			int num = 0; // ���ڵ��� 6�ڸ� ������ �ٲ۰�
			memset(file_buff, 0, sizeof(file_buff));
			for (int k = 0; k < 6; k++) {
				file_buff[strlen(file_buff)]=48+
			}
			v[i].push_back(cnt); //���̰�
			arr.push_back(num);
			file_buff[strlen(file_buff)] = ' ';
			file_buff[strlen(file_buff)] = 48 + v[i][6];
			file_buff[strlen(file_buff)] = '\n';

			fputs(file_buff, fp);
		}
		//����
	}
	fclose(fp);
	//���� ���� ����
	return 0;
}