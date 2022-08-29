
#include <stdio.h>

/* K - customer kto tk dice
  C - kto tk diye kinlam dokan theke
  N - kto coin baki ace
*/

void coin_chng(int K, int C, int N)
{
    int i, rem, sum = 0;
    int coin[N], res[N], di[N]; // n = coin
    int change = K - C;         //সব কেনা জিনিসের দাম

    for (i = 0; i < N; i++)
    { // scan krbo available coin gula
        scanf("%d", &coin[i]);
        //array value gula 0 diya initilise krbo
        res[i] = 0;
        di[i] = 0;
    }

    for (i = 0; change > 0; i++)
    {
        for (i = N - 1; i >= 0; i--)
        {
            rem = change % coin[i]; //remainder calculate krbo
            if (rem == 0)
            {
                change = change - coin[i]; // cahnge r  vaue decrease krbo
                res[i] = coin[i];          // পরে ব্যবহার করার জন্য একটি বিশেষ মুদ্রা store করা
                di[i] += 1;                // coin gula count kre array te store krbo
                break;
            }
        }
    }

    for (i = 0; i < N; i++)
    {
        sum = sum + di[i]; // total num of coin calculate krbo
    }
    printf("\n%d\n", sum); //printing number of coin required

    for (i = N - 1; i >= 0; i--)
    {
        if (res[i] != 0)
        { // payment krar jnno 0 gulo filter krbe
            printf("%d coins of %d\n", di[i], res[i]);
        }
    }
}

int main()
{
    int K, C, N;

    scanf("%d", &K);

    scanf("%d", &C);

    scanf("%d", &N);

    coin_chng(K, C, N);

    return 0;
}