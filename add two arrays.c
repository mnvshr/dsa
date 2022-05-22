#include <stdio.h>
int arr_a[3][2];
int arr_b[3][2];
int sum[3][2];

void read_arr();
void print_arr();
void sum_arr();
void print_sum();

void read_arr()
{
    printf("Enter array 1:\n");
    for(int i = 0; i < 3; ++i) {
        printf("\n");
        for(int j = 0; j < 2; ++j) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &arr_a[i][j]);
        }
    }
    printf("\nEnter array 2:\n");
    for(int i = 0; i < 3; ++i) {
        printf("\n");
        for(int j = 0; j < 2; ++j) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &arr_b[i][j]);
        }
    }
}

void print_arr()
{
    printf("\nArray 1:");

    for(int i = 0; i < 2; ++i) {
        printf("\n");
        for(int j = 0; j < 3; ++j) {
            printf("%d \t", arr_a[i][j]);
        }
    }
    
    printf("\nArray 2:");
    for(int i = 0; i < 2; ++i) {
        printf("\n");
        for(int j = 0; j < 3; ++j) {
            printf("%d \t", arr_b[i][j]);
        }
    }
}

void sum_arr()
{
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 3; ++j) {
            sum[i][j] = arr_a[i][j] + arr_b[i][j];
        }
    }
}

void print_sum()
{
    printf("\n The sum is:");
    for(int i = 0; i < 2; ++i) {
        printf("\n");
        for(int j = 0; j < 3; ++j) {
            printf("%d \t", sum[i][j]);
        }
    }
}

int main() 
{

    read_arr();
    print_arr();
    sum_arr();
    print_sum();

    return 0;
}
