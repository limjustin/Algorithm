#include <stdio.h>
#include <string.h>

int main(void) {

	// 0. 입력
	char str[1000000]; // 문자열 배열 준비
	scanf("%s", str);
	int max = 0;
	int max_index = -1;
	char res;

	// 1. 알파벳의 개수 세기
	char apb[26] = {0, }; // 알파벳 배열 준비 (A to Z)
	for (int i = 0; str[i] != '\0'; i++) {
		// 일단 대문자로 모두 변환하는 과정 거치기
		if (str[i] >= 'a' && str[i] <= 'z') // 소문자일 경우
			str[i] = str[i] - 32; // 대문자로 변환
		
		apb[str[i] - 65]++; // 해당하는 알파벳의 배열 카운트 증가
	}

	// 2. 알파벳 개수에 대한 처리
	for (int i = 0; i < sizeof(apb); i++) {
		// 가장 처음의 인덱스를 max로 잡고
		if (apb[i] == max) {
			res = '?';
		}
		else if (apb[i] > max) {
			max = apb[i]; // 최대값 갱신
			max_index = i; // 그 인덱스 저장
			res = i + 65;
		}
 	}
	// 3. 출력
	printf("%c", res);
	return 0;
}
