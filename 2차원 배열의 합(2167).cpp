#include<stdio.h>
int main(){
	int saver[301][301];
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j;
	int k;
	scanf("%d", &saver[1][1]);
	for(j=2;j<=m;j++){
		scanf("%d", &k);
		saver[1][j] = saver[1][j-1]+k;
	}
	for(i=2;i<=n;i++){
		scanf("%d", &saver[i][1]);
		saver[i][1]+=saver[i-1][1];
		for(j=2;j<=m;j++){
			scanf("%d", &k);
			saver[i][j] = saver[i][j-1]+saver[i-1][j]-saver[i-1][j-1]+k;
		}
	}
	scanf("%d", &k);
	int x1, y1, x2, y2;
	while(k-->0){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if(x1 > n) x1=n;
		if(x2 > n) x2=n;
		if(y1 > m) y1=m;
		if(y2 > m) y2=m;
		printf("%d\n", saver[x2][y2]-saver[x2][y1-1]-saver[x1-1][y2]+saver[x1-1][y1-1]);
	}
	return 0;
}
