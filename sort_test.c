//두 배열의 원소 교체
/*
배열 둘 다 크기순으로 정렬한 후
배열 A에서 가장 작은 원소를 고르고, B에서 가장 큰 원소를 골라서 바꿔치기하기. 

*/

#include <stdio.h>

int n, k;
int a[100001], b[100001];

int main() 
{
    //N과 K 입력 받기
    if (scanf("%d %d", &n, &k)!=2)//제대로 입력 안받았으면 종료
	{
		return 0;
	}

    //배열 A와 B 입력 받기
    for (int i=0; i<n; i++) 
	{
		scanf("%d", &a[i]);
	}
    for (int i=0; i<n; i++) 
	{
		scanf("%d", &b[i]);
	}

    //A를 작은순(오름차순)으로 정렬
    for (int i=0; i<n-1; i++) 
	{
        for (int j=i+1; j<n; j++) 
		{
            if (a[i]>a[j]) 
			{ // 앞에 있는 게 더 크면 뒤랑 바꾸기
                int cup=a[i];
                a[i]=a[j];
                a[j]=cup;
            }
        }
    }

    //B는 반대로 큰것부터(내립차순)으로 정렬
    for (int i=0; i<n-1; i++) 
	{
        for (int j=i+1; j<n; j++) 
		{
            if (b[i]<b[j]) 
			{ // 앞에 있는 게 더 작으면 뒤랑 바꾸기
                int cup=b[i];
                b[i]=b[j];
                b[j]=cup;
            }
        }
    }

    //두 배열의 원소를 최대 K번 교체
    for (int i=0; i<k; i++) 
	{
        if (a[i]<b[i]) 
		{ // A의 작은 값보다 B의 큰 값이 더 클 때 바꾸기
            int cup=a[i];
            a[i]=b[i];
            b[i]=cup;
        } 
		else //더이상 교체할 것 없을 때
		{
            break; 
        }
    }

    //A의 합 계산하고 출력하기
    long long result=0;
    for (int i=0; i<n; i++) 
	{
		result+=a[i];
	}

    printf("%lld\n", result);
    return 0;
}