//미래도시
//최단 경로 구하기
//다익스트라 또는 플로이드워셜->노드 개수가 그래도 좀 적기도하고 경유지k를 거쳐가야할때는? 구현이 간단한 플로이드워셜이 좋다..
//nm 입력받은 후 m개의 도시연결을 입력받음

#include <stdio.h>

#define INF 1e9 //무한대를 의미..?/ 상수선언

int n, m;
int city[101][101]; //도시 지도

int main() {
    //도시 개수랑 도로 수 n,m으로 입력받기
    if (scanf("%d %d", &n, &m)!=2)//만약 제대로 안받았으면 종료 
	{
		return 0;
	}

    //지도 설정(자기 자신은 0, 나머지는 무한대)
    for (int i=1; i<=n; i++)//도시들끼리의
	{
        for (int j=1; j<=n; j++) 
		{
            if (i==j) 
			{
				city[i][j]=0;
			}
            else 
			{
				city[i][j]=INF;
			}
        }
    }

    //도로 정보 입력 (이동 시간은 모두 1)
    for (int i=0; i<m; i++) 
	{
        int u, v;
        scanf("%d %d", &u, &v);
        city[u][v] = 1;
        city[v][u] = 1; // 양방향 도로이므로
    }

    // 최종 목적지 X와 거쳐갈 지점 K 입력
    int x, k;
    scanf("%d %d", &x, &k);/////마지막에 적을때 꼭 순서 주의할것


    for (int via = 1; via <= n; via++) 
	{         // 경유지
        for (int a = 1; a <= n; a++) 
		{          // 출발지
            for (int b=1; b<=n; b++) 
			{      // 목적지
                // a에서 b로 바로 가는 것보다 via를 거쳐가는 게 더 짧으면(작으면) 경유하는거로 바꾸기
                if (city[a][via]+city[via][b]<city[a][b]) 
				{
                    city[a][b]=city[a][via]+city[via][b];
                }
            }
        }
    }

    //결과 계산 (출발지->경유지 K)+(경유지 K->목적지 X)
    int total_time=city[1][k]+city[k][x];

    //출력 (출발지에서 경유지로가는 길이 없거나 경유지에서 도착지로 가는 길이 없으면 -1 출력)
    if (total_time >= INF) 
	{
        printf("-1\n");
    } 
	else 
	{
        printf("%d\n", total_time);
    }

    return 0;
}