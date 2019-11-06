#include<stdio.h>
#include<string.h>
int main(){
	char subject[100];
	char retake[100][100];
	char grade[5];
	char grade_re[100][5];
	int time, times=0;
	int num;
	int num_re=0;
	double mean=0;
	char means[10];
	scanf("%d", &num);
	for(int i=0;i<num;i++){
		scanf("%s", &subject);
		scanf("%s", &grade);
		scanf("%d", &time);
		times+=time;
		if(!strcmp(grade, "A+")||!strcmp(grade, "Pass"))
			mean+=time*4.3;
		else if(!strcmp(grade, "A0"))
			mean+=time*4.0;
		else if(!strcmp(grade, "A-"))
			mean+=time*3.7;
		else if(!strcmp(grade, "B+"))
			mean+=time*3.3;
		else if(!strcmp(grade, "B0"))
			mean+=time*3.0;
		else if(!strcmp(grade, "B-"))
			mean+=time*2.7;
		else if(!strcmp(grade, "C+"))
			mean+=time*2.3;
		else if(!strcmp(grade, "C0"))
			mean+=time*2.0;
		else if(!strcmp(grade, "C-"))
			mean+=time*1.7;
		else if(!strcmp(grade, "D+"))
			mean+=time*1.3;
		else if(!strcmp(grade, "D0"))
			mean+=time*1.0;
		else if(!strcmp(grade, "D-"))
			mean+=time*0.7;
		else if(!strcmp(grade, "F")||!strcmp(grade, "Fail"))
			mean+=time*0;
		if(grade[0]=='C'||grade[0]=='D'||grade[0]=='F'||!strcmp(grade, "Fail")){
			strcpy(retake[num_re],subject);
			strcpy(grade_re[num_re], grade);
			num_re++;
		}
	}
	mean=(float)mean/times;
	if(mean>=4.3)
		strcpy(means, "A+");
	else if(mean>4.00)
		strcpy(means, "A0");
	else if(mean>3.70)
		strcpy(means, "A-");
	else if(mean>3.30)
		strcpy(means, "B+");
	else if(mean>3.00)
		strcpy(means, "B0");
	else if(mean>2.70)
		strcpy(means, "B-");
	else if(mean>2.30)
		strcpy(means, "C+");
	else if(mean>2.00)
		strcpy(means, "C0");
	else if(mean>1.70)
		strcpy(means, "C-");
	else if(mean>1.30)
		strcpy(means, "D+");
	else if(mean>1.00)
		strcpy(means, "D0");
	else if(mean>0.70)
		strcpy(means, "D-");
	else
		strcpy(means, "F");
	
	
	printf("Average : %.2f (%s)\n\n", mean, means);
	printf("RETAKE NEEDED (%d)\n", num_re);
	for(int i=0;i<num_re;i++)
		printf(" %s (%s)\n", retake[i], grade_re[i]);
	
}
