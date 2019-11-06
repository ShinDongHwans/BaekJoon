#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
    char *s1 = malloc(sizeof(char) * 10);

    printf("문자열을 입력하세요: ");
    scanf("%s", s1);
	scanf("%d %d", &a, &b);
	for(int i=a-1;i<b;i++){
		printf("%c", *s1+i);
	}
	

    free(s1);

    return 0;
}
