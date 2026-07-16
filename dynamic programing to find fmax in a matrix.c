#include <stdio.h>
void findmax(int fsmax[], int row, int c, int dp[][c])
{
    int fmax = -1, smax = -1;

    for (int j = 0; j < c; j++)
    {
        if (dp[row][j] > fmax)
        {
            smax = fmax;
            fmax = dp[row][j];
        }
        else if (dp[row][j] > smax)
        {
            smax = dp[row][j];
        }
    }

    fsmax[0] = fmax;
    fsmax[1] = smax;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int arr[n][m], dp[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);

            if (i == 0)
                dp[i][j] = arr[i][j];
        }
    }

    int fsmax[2];

    for (int row = 1; row < n; row++)
    {
        findmax(fsmax, row - 1, m, dp);

        for (int col = 0; col < m; col++)
        {
           dp[row][col] = arr[row][col] +
               (dp[row - 1][col] == fsmax[0] ? fsmax[1] : fsmax[0]);
        }
    }

    int ans = dp[n - 1][0];
    for (int j = 1; j < m; j++)
    {
        if (dp[n - 1][j] > ans)
            ans = dp[n - 1][j];
    }

    printf("%d\n", ans);

    return 0;
}