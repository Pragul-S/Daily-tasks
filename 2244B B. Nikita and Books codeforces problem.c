#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int stk=1;stk<=n;stk++)
	scanf("%d",&arr[stk]);
	long long int bal=0;
	int ok=1;
	for(int stk=1;stk<=n;stk++){
		if(arr[stk]>=stk)
		bal+=arr[stk]-stk;
		else{
			int need =stk-arr[stk];
			if(bal>=need){
				bal-=need;
			}else{
				ok =0;
				break;
			}
		}
	}if(ok)
	printf("Yes");
	else
	printf("No");
}