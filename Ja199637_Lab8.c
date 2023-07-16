#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int arraySize);

void swap(int* itemA, int* itemB)
{

    int temp = *itemA;
    *itemA = *itemB;
    *itemB = temp;


}

void maxheapify(int array[], int arraySize, int index)
{

    int lChildN = 2*index + 1;

    int rChildN = 2*index + 2;

    int largest = index;

    if(lChildN < arraySize && array[lChildN] > array[largest])
        largest = lChildN;
    if(rChildN < arraySize && array[rChildN] > array[largest])
        largest = rChildN;

    if(largest != index)
    {

        swap(&array[index], &array[largest]);

        maxheapify(array,  arraySize, largest);

    }
}

void buildMaxHeap(int array[], int arraySize)
{


    for (int index = arraySize / 2 - 1; index >= 0; index--)

        maxheapify(array, arraySize, index);
        

}

void heapSort(int array[], int arraySize)
{


    buildMaxHeap(array, arraySize);

    printArray(array, arraySize);

    for (int index = arraySize - 1; index >= 0; index--) {

        swap(&array[0], &array[index]);

        // Heapify root element
        // to get highest element at
        // root again
        maxheapify(array, index, 0);
    }


}

void printArray(int array[], int arraySize)
{

    for(int index = 0; index < arraySize; ++index)
    {


        printf("%d ", array[index]);


    }

    printf("\n");

}


int main()
{

    int array[14] = {12, 15, 23, 17, 5, 7, 12, 3, 5, 2, 3, 1, 34, 50};

    size_t arrSize = sizeof(array) / sizeof(array[0]);

    heapSort(array, arrSize);

    printArray(array, arrSize);



}
