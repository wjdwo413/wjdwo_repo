//상하좌우문제
#include <stdio.h>
#include <string.h>

int n;
char plans[1001];//이동계획
int x=1, y=1;//시작좌표가 1,1

int dx[]={0,0,-1,1,0,0,-1,1};
int dy[]={-1,1,0,0,-1,1,0,0};
char moveTypes[]={'L', 'R', 'U', 'D', 'l', 'r', 'u', 'd'};

int main() 
{
    //n 입력 받기
    if (scanf("%d", &n)!= 1) return 0;
    
    //N 입력 후 남은 엔터 키 제거
    while (getchar()!= '\n');

    //이동 계획을 한 줄로 입력 받기
    fgets(plans, sizeof(plans), stdin);

    //이동 계획을 하나씩 확인하기
    int len=strlen(plans);
    for (int i=0; i<len; i++) 
	{
        char plan=plans[i];
        int nx=-1, ny=-1;

        // 이동 후 좌표 구하기
        for (int j=0; j<8; j++) 
		{
            if (plan==moveTypes[j]) 
			{
                nx=x+dx[j];
                ny=y+dy[j];
            }
        }

        //공간 크기 N 이내인지 확인
        if (nx<1 || ny<1 || nx>n || ny>n) continue;

        //이동하기
        if (nx!=-1 && ny!=-1) 
		{
            x=nx;
            y=ny;
        }
    }

    // 최종 좌표 출력
    printf("%d %d\n", x, y);

    return 0;
}