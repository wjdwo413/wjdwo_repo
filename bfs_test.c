//미로탈출

#include <stdio.h>

//***큐 구현(c언어는 큐없음)
typedef struct
{
	int x, y;
}
Node;//노드란? x, y 따로 적기 귀찮으니 걍 뭉쳐둔것

int n,m;
int graph[201][201];

//방향정의
//상 하 좌 우 순
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

//큐 선언
//큐는 줄서기와 같다 머리랑 꼬리도 선언해서 맨앞 데이터랑 마지막 데이터 들어갈 곳
Node queue[40001];//200*200이라서
int head=0;
int tail=0;

//push로 큐에 넣기
void push(int x, int y)//새로운 거 꼬리에 세우고, 꼬리 한칸 뒤로 옮기기
{
	queue[tail].x=x;
	queue[tail].y=y;
	tail++;
}

//pop으로 큐에서 빼기
Node pop()//맨앞에거 불러내고 머리 한칸 뒤로 옮기기
{
	return queue[head++];
}

//큐 빈거 확인하기
int is_empty()
{
	return head==tail;
}

int bfs(int start_x, int start_y)
{
	//시작 위치 큐에 넣기
	push(start_x, start_y);
	
	//큐 빌때까지 반복하기
	while(!is_empty())
	{
		Node current = pop();
		int x=current.x;
		int y=current.y;
		
		//현재 위치에서 상하좌우 위치 확인
		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			//만약 미로찾기 공간을 넘어간다면 무시하기
			if(nx<0 || nx>=n || ny<0 || ny>=m)
			{
				continue;
			}
			//벽이어도 무시하기
			//0을 벽으로 한다
			if(graph[nx][ny]==0)
			{
				continue;
			}
			
			//노드를 처음 방문할때만 기록(중복 막기)
			if(graph[nx][ny]==1)//어차피 한번 간 곳이면 2,3,4... 등을 넣을테니 1이면 처음간 곳
			{
				graph[nx][ny]=graph[x][y]+1;
				push(nx, ny);
			}
		}
	}
	//가장 오른쪽 아래(n,m)까지의 최단거리 반환
	return graph[n-1][m-1];
}

int main()
{
	//n.m입력받기(공백으로 구분)
	//만약 올바르지않으면 종료
	if(scanf("%d %d", &n, &m)!=2)
	{
		return 0;
	}
	
	//2차원 맵 정보받기
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%1d", &graph[i][j]);
		}
	}
	
	//bfs 수행 결과 출력(시작은 (0,0))
	printf("%d\n", bfs(0,0));
	
	return 0;
}