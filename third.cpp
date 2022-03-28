#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <cmath>

using namespace std;

struct dot{
    int x;
    int y;

    dot(int _x, int _y){
        x = _x;
        y = _y;
    }
};

void createDots(int sizeX, int sizeY, vector<dot> *plane);
void showDots(int sizeX, int sizeY, vector<dot> plane, dot curr);
bool isParallelogram(dot curr, dot first, dot second, dot third);


int main()
{
    srand(time(0));
    int sizeX, sizeY, counter = 0;
    cin >> sizeX >> sizeY;
    vector<dot> plane;

    createDots(sizeX, sizeY, &plane);
    showDots(sizeX, sizeY, plane, dot(-1, -1));
    int x, y;
    cin >> x >> y;
    dot curr = dot(x, y);
    showDots(sizeX, sizeY, plane, curr);


    for(int ai = 0; ai < plane.size()-2; ai++){
        for(int bi = ai+1; bi < plane.size(); bi++){
            for(int ci = bi+1; ci < plane.size(); ci++){
                if(isParallelogram(plane[ai], plane[bi], plane[ci], curr)){
                    counter++;
                }
                else if(isParallelogram(plane[bi], plane[ai], plane[ci], curr)){
                    counter++;
                }

                
            }
        }
    }
    cout << counter << endl;
    return 0;
}

void createDots(int sizeX, int sizeY, vector<dot> *plane){
    for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++){
            int flag = rand() % 100;
            if(flag > 50){
                plane->push_back(dot(i+1, j+1));
            }
        }
    }
}

void showDots(int sizeX, int sizeY, vector<dot> plane, dot curr){
    cout << "dots: " << endl;
    for(int i = 0; i < sizeX + 1; i++){
        for(int j = 0; j < sizeY + 1; j++){
            if(j == 0){
                cout << " " << i;
                continue;
            }
            if(i == 0){
                cout << " " << j;
                continue;
            }
            bool flag = false;
            if(i == curr.x && j == curr.y){
                cout << " Y";
                flag = true;
            }
            if(!flag){
                for(dot each: plane){
                    if(each.x == i && each.y == j){
                        cout << " X";
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag){
                cout << " *";
            }
        }
        cout << endl;
    }
}

bool isParallelogram(dot a, dot b, dot c, dot d){
    if( abs(a.x - d.x) == abs(b.x - c.x) &&  abs(a.y - d.y) == abs(b.y - c.y)){
        double ad = ((double)(a.y - d.y)) / ((double)(a.x - d.x));
        double bc = ((double)(b.y - c.y)) / ((double)(b.x - c.x));

        double ads = ((double)(a.x*d.y - a.y*d.x)) / ((double)(a.x - d.x));
        double bcs = ((double)(b.x*c.y - b.y*c.x)) / ((double)(b.x - c.x));
        if(ad == bc && ads != bcs){
            return true;
        }
    }
    return false;
}