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
	printf("학습횟수 입력:");
	scanf("%d", &N);
	srand(time(NULL));
	FILE* fp;
	fp = fopen("test.txt", "w");
	if (fp == NULL) printf("파일열기 실패\n");
	else printf("파일열기 성공\n");
	vector<int> v[21],arr;
	char file_buff[100];
	for (int i = 0; i < 20; i++) { //0번째 학습, 20개의 모델 생성
		int cnt=0;// 111111과의 차이값(가중치)
		int num = 0; // 숫자들을 6자리 정수로 바꾼거
		memset(file_buff, 0, sizeof(file_buff));
		for (int k = 0; k < 6; k++) {
			v[i].push_back(rand() % 2); //각자리 설정(초기설정이므로 랜덤으로 한다)
			if (v[i][k] == 0) cnt++; //111111과의 차이 
			num = num * 10 + v[i][k]; // num 갱신
			file_buff[k] = 48 + v[i][k];
		}
		v[i].push_back(cnt); //차이값
		arr.push_back(num);
		file_buff[strlen(file_buff)] = ' ';
		file_buff[strlen(file_buff)] = 48+v[i][6];
		file_buff[strlen(file_buff)] = '\n';

		fputs(file_buff, fp);
	}
	fclose(fp);
	//for (i = 1; i <= 5; i++) {
	//	printf("파일에 적을 내용을 입력하세요 (%d번째 라인)\n", i);
	//	memset(file_buff, 0, sizeof(file_buff));
	//	scanf("%s", file_buff);
	//	file_buff[strlen(file_buff)] = '\n';
	//	fputs(file_buff, fp);
	//}
	//fclose(fp);
	memset(file_buff, 0, sizeof(file_buff));
	fp = fopen("test.txt", "r");
	if (fp == NULL) printf("파일열기 실패\n");
	else printf("파일열기 성공\n");
	while (fgets(file_buff, sizeof(file_buff), fp) != NULL) {
		printf("%s", file_buff);
		memset(file_buff, 0, sizeof(file_buff));
	}
	fclose(fp);
	fp = fopen("test.txt", "r");
	while (N--) {
		//선택 코드
		printf("==================================================\n");
		//system("cls");
		vector<s> v; //2*20 
		s gu;
		int num,tmp=2000000,key;
		for (int i = 0; i < 20; i++) { //선택을 위한 값 정렬
			fscanf(fp, "%d %d", &num, &key);
			printf("%d %d\n",tmp+ num, key);
			gu.key = key;
			gu.value = tmp + num;
			v.push_back(gu);
		}
		printf("==================================================\n");
		sort(v.begin(), v.end(), cp);
		for (int i = 0; i < 20; i++) { //정렬 잘되는지 체크 (잘됨)
			printf("%d %d\n", v[i].value, v[i].key);
		}
		//교차
		for (int i = 0; i < 16; i++) {
			int cnt = 0;// 111111과의 차이값(가중치)
			int num = 0; // 숫자들을 6자리 정수로 바꾼거
			memset(file_buff, 0, sizeof(file_buff));
			for (int k = 0; k < 6; k++) {
				file_buff[strlen(file_buff)]=48+
			}
			v[i].push_back(cnt); //차이값
			arr.push_back(num);
			file_buff[strlen(file_buff)] = ' ';
			file_buff[strlen(file_buff)] = 48 + v[i][6];
			file_buff[strlen(file_buff)] = '\n';

			fputs(file_buff, fp);
		}
		//변이
	}
	fclose(fp);
	//선택 교차 변이
	return 0;
}