//음료수 얼려먹기

#include <stdio.h>
#include <stdbool.h>

//가로, 세로랑 그래프 선언
int row, col;//N,M
int graph[1001][1001];

//dfs 함수
bool dfs(int x, int y)//참거짓 대답하는 자료형
{
	if(x<=-1 || x>=row || y<=-1 || y>=col)//주어진 범위 벗어나면 종료
	{
		return false;
	}
	
	if(graph[x][y]==0)
	{
		graph[x][y]=1;//0인부분 방문하면 1로 바꿔서 이미 방문함을 표시
		
		//상하좌우도 0이면 방문하기
		//수학적 좌표 그래프와 달리 행렬이라 표기가 다름
		dfs(x-1, y);//상
		dfs(x+1, y);//하
		dfs(x, y-1);//좌
		dfs(x, y+1);//우
		
		return true;//묶음 하나 찾았다.
	}
	
	return false;//벽(1)이거나 이미 방문(1)
}

int main()
{
	//가로세로 공백 기준으로 입력받기
	if(scanf("%d %d", &row, &col)!=2)//제대로 입력안받았으면 걍 끄기
	{
		return 0;
	}
	
	//맵 정보 입력받기
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			scanf("%1d", &graph[i][j]);
		}
	}
	
	
	//음료수 수 세기
	int result=0;
	for (int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(dfs(i, j))
			{
				result+=1;//새로운 묶음 발견 시 결과값 증가
			}
		}
		
	}
	
	printf("%d\n", result);
	
	return 0;
}