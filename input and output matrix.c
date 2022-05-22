#include <stdio.h>
int arr[2][3];
void read_arr();
void print_arr();

void read_arr()
{
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 3; ++j) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void print_arr()
{
    printf("\nThe array is: \n");

    for(int i = 0; i < 2; ++i) {
        printf("\n");
        for(int j = 0; j < 3; ++j) {
            printf("%d \t", arr[i][j]);
        }
    }
}

int main() 
{

    read_arr();
    print_arr();

    return 0;
}
