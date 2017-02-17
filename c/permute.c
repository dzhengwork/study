#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permuteR(int *a, int l, int r)
{
    if (l == r) {
        for (int k=0; k<r+1; k++) {
            printf("%d ", a[k]);
        }
        printf("\n");
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            permuteR(a, l+1, r);
            swap((a+l), (a+i)); //backtrack
        }
    }
}

int main()
{
    int nums[3] = {1,2,3};
    permuteR(nums, 0, 3-1);
    return 0;
}

