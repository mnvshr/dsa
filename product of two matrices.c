#include <stdio.h>
int arr_a[2][3];
int arr_b[3][3];
int mul[2][3];

void read_arr();
void print_arr();
void product_arr();
void print_product();

void read_arr()
{
    printf("Enter array 1:\n");
    for(int i = 0; i < 2; ++i) {
        printf("\n");
        for(int j = 0; j < 3; ++j) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &arr_a[i][j]);
        }
    }
    printf("\nEnter array 2:\n");
    for(int i = 0; i < 3; ++i) {
        printf("\n");
        for(int j = 0; j < 3; ++j) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &arr_b[i][j]);
        }
    }
}

void print_arr()
{
    printf("\n Array 1:");

    for(int i = 0; i < 2; ++i) {
        printf("\n");
        for(int j = 0; j < 3; ++j) {
            printf("%d \t", arr_a[i][j]);
        }
    }
    
    printf("\n Array 2:");
    for(int i = 0; i < 3; ++i) {
        printf("\n");
        for(int j = 0; j < 3; ++j) {
            printf("%d \t", arr_b[i][j]);
        }
    }
}

void product_arr()
{
    printf("\nThe product of the two arrays is\n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                mul[i][j]+= arr_a[i][k]*arr_b[k][j];
            }
        }
    }
}

void print_product()
{
    printf("\nThe array after multiplication is:");
    for(int i = 0; i < 2; ++i) {
        printf("\n");
        for(int j = 0; j < 3; ++j) {
            printf("%d \t", mul[i][j]);
        }
    }
}

int main() 
{

    read_arr();
    print_arr();
    product_arr();
    print_product();

    return 0;
}
