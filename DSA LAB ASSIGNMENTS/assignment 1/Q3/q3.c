#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int binaryIntSearch(int k, int * arr, int n){ //function for binary search of integer in an array of given length
    int leftindex = 0;
    int rightindex = n-1;

    if(k < arr[leftindex] || k > arr[rightindex]){ //check if the given value is out of range 
        return -1; 
    } else if (k == arr[leftindex]) { //check if the given value is the terminal terms of array
        return leftindex;
    } else if (k == arr[rightindex]){
        return rightindex;
    }

    int midindex = (leftindex+rightindex)/2;

    do
    {
       if(k == arr[midindex]){
           return midindex;
       } else if (k > arr[midindex]) {
           leftindex = midindex; // eliminate half of the array
       } else {
           rightindex = midindex; //eliminate half of the array
       }

       midindex = (leftindex+rightindex)/2; //diving the array in to two subparts
    } while (midindex != leftindex);

    return -1;   
}


int linearIntSearch(int k, int * arr, int n) { // Linear search function for integer
    int i;
    for (i = 0; i < n; i++)
    {
        if(k == arr[i]) {
            return i;
        }
    }
    
    return -1;
}



int binaryFloatSearch(float k, float * arr, int n){ //function for binary search of integer in an array of given length
    int leftindex = 0;
    int rightindex = n-1;

    if(k < arr[leftindex] || k > arr[rightindex]){ //check if the given value is out of range 
        return -1; 
    } else if (k == arr[leftindex]) { //check if the given value is the terminal terms of array
        return leftindex;
    } else if (k == arr[rightindex]){
        return rightindex;
    }

    int midindex = (leftindex+rightindex)/2;

    do
    {
       if(k == arr[midindex]){
           return midindex;
       } else if (k > arr[midindex]) {
           leftindex = midindex; // eliminate half of the array
       } else {
           rightindex = midindex; //eliminate half of the array
       }

       midindex = (leftindex+rightindex)/2; //diving the array in to two subparts
    } while (midindex != leftindex);

    return -1;   
}


int linearFloatSearch(float k, float * arr, int n) { // Function for linear search of floating point numbers
    int i;
    for (i = 0; i < n; i++)
    {
        if(k == arr[i]) {
            return i;
        }
    }
    
    return -1;
}

int binaryStringSearch(char * str, char arr[][40], int n) { // Binary search of string
    int leftindex = 0;
    int rightindex = n-1;

    if(strcmp(str, arr[leftindex]) < 0 || strcmp(str, arr[rightindex]) > 0){ //check if the given value is out of range 
        return -1; 
    } else if (strcmp(str, arr[leftindex]) == 0) { //check if the given value is the terminal terms of array
        return leftindex;
    } else if (strcmp(str, arr[rightindex]) == 0){
        return rightindex;
    }

    int midindex = (leftindex+rightindex)/2;

    do
    {
       if(strcmp(str, arr[midindex]) == 0){
           return midindex;
       } else if (strcmp(str, arr[midindex]) > 0) {
           leftindex = midindex; // eliminate half of the array
       } else {
           rightindex = midindex; //eliminate half of the array
       }

       midindex = (leftindex+rightindex)/2; //diving the array in to two subparts
    } while (midindex != leftindex);

    return -1;  
}

int linearStringSearch(char * str, char arr[][40], int n) { // Linear search of string
     int i;
    for (i = 0; i < n; i++)
    {
        if(strcmp(str, arr[i]) == 0) {
            return i;
        }
    }
    
    return -1;
}


int takeArrayLength() {  // Taking the length of array;
    printf("\n\nEnter the length of the array: ");
    int n;
    scanf("%d", &n);
    return n;
}

void takeIntArrayElements(int * arr, int n){ // For taking the integer array elements
    int i;
    printf("\nEnter the elements of integer array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }   
}


void takeFloatArrayElements(float * arr, int n) { // For taking the float array elements
    int i;
    printf("\nEnter the elements of float array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%f", arr+i);
    }   
}

void takeStringArrayElements(char arr[][40], int n) { // Taking the string array elements
    printf("\nEnter the strings one per line: ");
    int i;
    for (i = 0; i < n; i++)
    {
       scanf("%s", arr[i]);
    }
    
}


void found(int statement){ //prints found with index or not found
    if(statement >= 0){
        printf("\nElement found successfully at index %d..", statement);
    } else {
        printf("\nElement not found..");
    }
}


int main() {
    int i, n; // variables to be use in every search .. i for index and n for array length
   

    // Binary search of integer
    printf("\n\n-----------Binary Search of Integer-----------------");
    n = takeArrayLength();
    int arr1[n];
    takeIntArrayElements(arr1, n);
    int k1;
    printf("\nEnter The value of integer k1 to search: ");
    scanf("%d", &k1);
    found(binaryIntSearch(k1, arr1, n));
    

    // Linear search of integer
    printf("\n\n-----------Linear Search of integer-----------------");
    n = takeArrayLength();
    int arr2[n];
    takeIntArrayElements(arr2, n);
    int k2;
    printf("\nEnter The value of integer k2 to search: ");
    scanf("%d", &k2);
    found(linearIntSearch(k2, arr2, n));


    // Binary search of floating point number
    printf("\n\n-----------Binary Search of float-----------------");
    n = takeArrayLength();
    float arr3[n];
    takeFloatArrayElements(arr3, n);
    float k3;
    printf("\nEnter The value of float k3 to search: ");
    scanf("%f", &k3);
    found(binaryFloatSearch(k3, arr3, n));

    // Linear search of floating point number
    printf("\n\n-----------Linear Search of float-----------------");
    n = takeArrayLength();
    float arr4[n];
    takeFloatArrayElements(arr4, n);
    float k4;
    printf("\nEnter The value of float k4 to search: ");
    scanf("%f", &k4);
    found(linearFloatSearch(k4, arr4, n));


    // Binary search for string 
    printf("\n\n-----------Binary Search of string-----------------");
    n = takeArrayLength();
    char arr5[n][40];
    takeStringArrayElements(arr5, n);
    char str[40];
    printf("\nEnter the value of string to search: ");
    scanf("%s", str);
    found(binaryStringSearch(str, arr5, n));

    // Linear search for string
    printf("\n\n-----------Linear Search of string-----------------");
    n = takeArrayLength();
    char arr6[n][40];
    takeStringArrayElements(arr6, n);
    char str2[40];
    printf("\nEnter the value of string to search: ");
    scanf("%s", str2);
    found(linearStringSearch(str2, arr6, n));

    
    return 0;
}