#include<stdio.h>
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    
int rd[] = {-1,-1,-1,0,0,1,1,1};
int cd[] = {-1,0,1,-1,1,-1,0,1};

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        int sum = 0;

        for (int k = 0; k < 8; k++)
        {
            int nr = i + rd[k];
            int nc = j + cd[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m)
            {
                sum += arr[nr][nc];
            }
        }

        printf("%d ", sum);
    }
    printf("\n");
}
}