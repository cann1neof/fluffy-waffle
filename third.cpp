#include <iostream>
#include <vector>

using namespace std;

void fillArray(vector<int> *array);
void showArray(vector<int> *array);
int getMaxEvenIter(vector<int> *array);
void insertElement(int target, vector<int> *array);
void deleteElement(int target, vector<int> *array);

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> *arr = new vector<int>(n, 0);
    cout << "Fill array with " << n << " elements: ";
    fillArray(arr);
    cout << "Array filled up. Here it is: ";
    showArray(arr);

    int max_even_iter = getMaxEvenIter(arr);
    cout << "Max even element index: "<< max_even_iter << endl;

    cout << "Enter new element: ";
    insertElement(max_even_iter, arr);
    
    cout << "The new array looks like: ";
    showArray(arr);
    
    cout << "Deleting one element...\n";
    deleteElement(max_even_iter, arr);
    
    cout << "The final array looks like: ";
    showArray(arr);
    return 0;
}

void fillArray(vector<int> *array){
    for(int i = 0; i < array->size(); i++){
        cin >> (*array)[i];
    }
}

void showArray(vector<int> *array){
    for(int i = 0; i < array->size(); i++){
        cout << (*array)[i] << " ";
    }
    cout << endl;
}

int getMaxEvenIter(vector<int> *array){
    int max = 0, maxIter = 0;
    for(int i = 0; i < array->size(); i++){
        if((*array)[i] % 2 == 0){
            if((*array)[i] > max){
                maxIter = i;
            }
        }
    }
    return maxIter;
}

void insertElement(int target, vector<int> *array){
    int a;
    cin >> a;
    array->insert(array->begin() + target + 1, a);
}

void deleteElement(int target, vector<int> *array){
    array->erase(array->begin() + target - 1);
}
