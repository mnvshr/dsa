/* Time complexity
Best case: O(n*log(n))
Average case: O(n*log(n))
Worst case: O(n^2)
*/

/* Space complexity
Best case: O(n*log(n))
*/

// Algorithm

/* 
quicksort(array, low, high)
{
    if(low < high)
    {
        p = partition(array, low, high)
        quicksort(array, low, p - 1)
        quicksort(array, p + 1, high)
    }
}

partition(array, low, high)
{
    pivot = array[high]
    i = low - 1
    for(j = low; j <= high - 1; j++)
    if (array[j] < pivot) {
        i++;
        swap array[i] and array[j]
    }
    swap array[i + 1] and array[high]
    return(i + 1)
}
*/

// Code (using Java)

import java.util.Arrays;
import java.util.Random;

public class Quicksort {

    public void quicksort(int[] a) {
        quicksort(a, 0, a.length - 1);
    }

    private void quicksort(int[] a, int low, int high) {
        if (low < high - 1) {
            int p = partition(a, low, high);
            quicksort(a, low, p - 1);
            quicksort(a, p + 1, high);
        }
    }

    private void swap(int[] a, int index1, int index2) {
        int temp = a[index1];
        a[index1] = a[index2];
        a[index2] = temp;
    }

    private int getPivot(int low, int high) {
        Random rand = new Random();
        return rand.nextInt((high - low) + 1) + low;
    }

    private int partition(int[] a, int low, int high) {
        swap(a, low, getPivot(low, high));
        int border = low + 1;

        for (int i = border; i <= high; i++) {
            if (a[i] < a[low]) {
                swap(a, i, border++);
            }
        }
        swap(a, low, border - 1);
        return border - 1;
    }

    public static void main(String[] args) {
        Quicksort qs = new Quicksort();
        int[] a = { 5, 6, 2, 65, 12, 98, 1, 5, 9 };
        System.out.println(Arrays.toString(a));
        qs.quicksort(a);
        System.out.println(Arrays.toString(a));
    }
}
