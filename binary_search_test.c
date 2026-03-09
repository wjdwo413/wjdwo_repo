//떡볶이 떡 만들기
//적절한 높이 찾을 때까지 계속 이진탐색하기...
/*
만약 시작점 0, 끝점 19라면 중간점이 9이다. 이때의 잘린 길이와 필요한 떡의 길이를 비교한 후 
1. 잘린길이>필요 떡길이 이면 중간점의 왼쪽의 시작점 버리고 중간점을 오른쪽으로 이동
2. 잘린 길이<필요 떡길이 이면 오른쪽의 끝점 버리고 중간점을 왼쪽으로 이동 
*/

#include <stdio.h>

int n, m;
int arr[1000001]; //떡 개수

int main() 
{
    //떡 개수랑 원하는 떡 길이 각각 n,m으로 입력 받기
    if (scanf("%d %d", &n, &m)!=2)//제대로 입력 안받았으면 종료
	{
		return 0;
	}

    //떡의 개별 높이 정보 입력 받기
    int max_val=0;
    for (int i=0; i<n; i++) 
	{
        scanf("%d", &arr[i]);
		
        if (arr[i]>max_val) 
		{
			max_val=arr[i]; //끝점 찾으려고 최대값 찾기
		}
    }

    //시작점, 끝점 설정
    int start=0;
    int end=max_val;
    int result=0;

    //이진 탐색 수행. 반복문
    while (start<=end) 
	{
        long long total=0; // 잘린 떡 양이 매우 클 수 있다. long long 사용
        int mid=(start + end)/2;//절단기높이

        // 현재 절단기 높이로 잘랐을 때의 떡의 양 계산
        for (int i=0; i<n; i++) 
		{
            if (arr[i]>mid) 
			{
                total+=arr[i]-mid;
            }
        }

        // 떡의 양이 부족: 더 많이 자르기 (왼쪽으로)
        if (total<m) 
		{
            end=mid-1;
        }
        // 떡의 양이 충분: 덜 자르기 (오른쪽으로)
        else 
		{
            result=mid; // 최대한 덜 잘랐을 때가 정답이니까 일단 result 기록하기
            start=mid+1;
        }
    }

    //출력
    printf("%d\n", result);

    return 0;
}