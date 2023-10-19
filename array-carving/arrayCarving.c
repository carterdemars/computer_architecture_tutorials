#include <stdio.h>
#include <stdlib.h>

int* memoryArray; // Global variable to hold the memory array
int* subArrays[10]; // Array of pointers to track sub-arrays
int subArrayCount = 0; // Variable to keep track of the number of allocated sub-arrays

int* allocateSubArray() {

    if (subArrayCount == 10)
        return NULL;

    int* arrayStart = memoryArray + (subArrayCount*100);
    subArrays[subArrayCount] = arrayStart;
    subArrayCount++;
    
    return arrayStart;
}

int writeValue(int* subArray, int index, int value) {

    if (index < 0 || index > 99)
        return 0;

    subArray[index] = value;
    return 1;
}

int readValue(int* subArray, int index) {

    if (index < 0 || index > 99)
        return subArray[0];
    
    return subArray[index];

}

int main() {
     memoryArray = malloc(1000*sizeof(int));

    // Test the functions
    int* subArray1 = allocateSubArray();
    int* subArray2 = allocateSubArray();
    
    if (subArray1 != NULL && subArray2 != NULL) {
        // Write values to sub-arrays
        writeValue(subArray1, 0, 10);
        writeValue(subArray2, 50, 20);
        
        // Read values from sub-arrays
        int value1 = readValue(subArray1, 0);
        int value2 = readValue(subArray2, 50);
        
        printf("Value in subArray1: %d\n", value1);
        printf("Value in subArray2: %d\n", value2);
    }
    
    free(memoryArray); // Release the allocated memory
    
    return 0;


}