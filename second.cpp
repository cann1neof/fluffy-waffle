#include <iostream>
#include <ctime>
#include <random>
#define INT_MAX 2147483647

using namespace std;

void showArray(int x, int y, int **matrix);

void fillArray(int x, int y, int **matrix, char state);
void fillMask(int x, int y, int **matrix, int **mask, bool findMax);

int main()
{
    srand(time(0));
    int x, y;
    cin >> x >> y;
    int *matrix[x];
    int *maxes[x];
    int *mines[x];

    for(int i = 0; i < x; i++){
        matrix[i] = new int[y];
        maxes[i] = new int[y];
        mines[i] = new int[y];
    }

    fillArray(x, y, matrix, 'c');
    fillArray(x, y, maxes, 'z');
    fillArray(x, y, mines, 'z');
    cout << endl;
    showArray(x, y, matrix);
    cout << endl;
    fillMask(x, y, matrix, maxes, true);
    fillMask(x, y, matrix, mines, false);

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(maxes[i][j] == 1 && mines[i][j] == 1){
                cout << i << " " << j << ": " << matrix[i][j] << endl;
            }
        }
    }

    return 0;
}

void showArray(int x, int y, int **matrix){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void fillArray(int x, int y, int **matrix, char state){
    /*
        state values:
        c - cin
        r - random
        z - zeros
    */

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(state == 'c')  cin >> matrix[i][j];
            else if (state == 'r') matrix[i][j] = rand() % 10;
            else if (state == 'z') matrix[i][j] = 0;
        }
    }
}

void fillMask(int x, int y, int **matrix, int **mask, bool findMax){
    for(int target = 0; target < (findMax ? x :  y); target++){
        int iter = -1, comp = (findMax ? 0 : INT_MAX);
        for(int i = 0; i < (findMax ? y : x); i++){
            if(findMax){
                if(matrix[target][i] > comp){
                    comp = matrix[target][i];
                    iter = i;
                }
            } else {
                if(matrix[i][target] < comp){
                    comp = matrix[i][target];
                    iter = i;
                }
            }
        }
        mask[(findMax ? target : iter)][(findMax ? iter : target)] = 1;
    }
}