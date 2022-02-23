#include <iostream>

using namespace std;

int* fillArray(int n);
void showArray(int n, int *array);
int getMaxEvenIter(int n, int *array);
int* insertElement(int n, int target, int *array);
int* deleteElement(int n, int target, int *array);

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int *arr = fillArray(n);
    if(arr == nullptr){
        cout << "Array cannot be size of 0" << endl;
        return 0;
    }
    cout << "Array filled up. Here it is: ";
    showArray(n, arr);

    int max_even_iter = getMaxEvenIter(n, arr);
    cout << "Max even element index: "<< max_even_iter << endl;

    cout << "Enter new element: ";
    arr = insertElement(n, max_even_iter+1, arr);
    
    cout << "The new array looks like: ";
    showArray(n+1, arr);
    
    cout << "Deleting one element...\n";
    arr = deleteElement(n+1, max_even_iter-1, arr);
    
    cout << "The final array looks like: ";
    showArray(n, arr);
    return 0;
}

int* fillArray(int n){
    if(n == 0) { return nullptr; }
    cout << "Fill array with " << n << " elements: ";
    int* array = new int[n];
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    return array;
}

void showArray(int n, int *array){
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int getMaxEvenIter(int n, int *array){
    int max = 0, maxIter = 0;
    for(int i = 0; i < n; i++){
        if(array[i] % 2 == 0){
            if(array[i] > max){
                maxIter = i;
            }
        }
    }
    return maxIter;
}

int* insertElement(int n, int target, int *array){
    array = (int*) realloc(array, (n+1) * sizeof(int));  
    n++;
    for(int i = n-1; i > target; i--){
        array[i] = array[i-1];
    }
    cin >> array[target];
    return array;
}

int* deleteElement(int n, int target, int *array){
    array = (int*) realloc(array, (n+1) * sizeof(int));  
    n++;
    for(int i = target; i < n-1; i++){
        array[i] = array[i+1];
    }
    array = (int*) realloc(array, (n-1) * sizeof(int));
    return array;
}