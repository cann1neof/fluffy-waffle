#include <iostream>

using namespace std;

void fillArray(int n, int* array);
void showArray(int n, int* array);
int getMaxEvenIter(int n, int* array);
void insertElement(int n, int target, int* array);
bool deleteElement(int n, int target, int* array);

int main()
{
    int n;
    int arr[1000];
    cout << "Enter array size: ";
    cin >> n;
    if(n > 998 || n < 1){
        cout << "Cannot fill array with this number of elements!" << endl;
        return 2; 
    }
    cout << "Fill array with " << n << " elements: ";
    fillArray(n, arr);
    cout << "Array filled up. Here it is: ";
    showArray(n, arr);

    int max_even_iter = getMaxEvenIter(n, arr);
    cout << "Max even element index: "<< max_even_iter << endl;

    cout << "Enter new element: ";
    insertElement(n, max_even_iter + 1, arr);
    n++;

    cout << "The new array looks like: ";
    showArray(n, arr);

    cout << "Deleting one element...\n";
    bool status = deleteElement(n, max_even_iter - 1, arr);
    n += status ? -1 : 0;

    cout << "The final array looks like: ";
    showArray(n, arr);
    return 0;
}

void fillArray(int n, int* array){
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    array[n] = 0;
    array[n+1] = 0;
}

void showArray(int n, int* array){
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int getMaxEvenIter(int n, int* array){
    int max = 0, maxIter = 0;
    for(int i = 0; i < n; i++){
        if(array[i] % 2 == 0){
            if(array[i] > max){
                maxIter = i;
                max = array[i];
            }
        }
    }
    return maxIter;
}

void insertElement(int n, int target, int* array){ 
    for(int i = n+1; i > target; i--){
        array[i] = array[i-1];
    }
    cin >> array[target];
}

bool deleteElement(int n, int target, int* array){
    if(target == -1) { return false; }
    for(int i = target; i < n+1; i++){
        array[i] = array[i+1];
    }
    return true;
}

