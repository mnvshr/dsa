#include<stdio.h>

void read_array(int array[], int length);
void display_array(int array[], int lenght);
void swap(int *x, int *y);
void quicksort(int array[], int low, int high);
int partition(int array[], int low, int high);

int main()
{
       int length;

       printf("Enter the length of the array: ");
       scanf("%d", &length);

       int array[length];

       read_array(array, length);
       quicksort(array, 0, length - 1);
       display_array(array, length);

       return 0;
}

void read_array(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &array[i]);
    }
    
}

void display_array(int array[], int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        printf("%d \t", array[i]);
    }
    
}

void swap(int *x, int *y)
{
       int temp = *x;
       *x = *y;
       *y = temp;
}

void quicksort(int array[], int low, int high)
{
       if (low > high)
       {
              return;
       }

       int pivot_index = partition(array, low, high);
       quicksort(array, low, pivot_index - 1);
       quicksort(array, pivot_index + 1, high);
}

int partition(int array[], int low, int high)
{
       int pivot_value = array[high];

       int i = low;

       for (int j = low; j < high; j++)
       {
              if (array[j] <= pivot_value)
              {
                     swap(&array[i], &array[j]);
                     i++;
              }             
       }
       swap(&array[i], &array[high]);

       return i;
}
