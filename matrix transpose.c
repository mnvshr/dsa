#include <stdio.h>
int arr[3][3];
int t[3][3];

void read_arr();
void print_arr();
void transpose();
void print_transpose();

void read_arr()
{
    printf("Enter array:\n");
    for(int i = 0; i < 3; ++i)
    {
        printf("\n");
        for(int j = 0; j < 3; ++j)
        {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void print_arr()
{
    printf("\nArray is:");

    for(int i = 0; i < 3; ++i)
    {
        printf("\n");
        for(int j = 0; j < 3; ++j)
        {
            printf("%d \t", arr[i][j]);
        }
    }
}

void transpose()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            t[j][i] = arr[i][j];
        } 
    }
}

void print_transpose()
{
    printf("\nThe transpose of the matrix is\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    read_arr();
    print_arr();
    transpose();
    print_transpose();

    return 0;
}
