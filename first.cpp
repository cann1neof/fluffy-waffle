#include <iostream>
#include <string.h>

using namespace std;

bool alphabetic(char str[]);
bool doublechar(char str[]);

int main() {
    char str[1024] = "", str2[1024] = "";
    int counter = 0;
    do{
        counter++;
        cin >> str2;
        if(strcmp(str2, "CC") != 0 && !(doublechar(str2))){
            if(counter > 1){
                strcat(str, " ");
            }
            strcat(str, str2);
            if(alphabetic(str2)){
                puts(str2);
            }
        }
    }while(strcmp(str2, "CC") != 0);
    puts(str);
}

int localeLetter(char letter){
    if(letter >= 'A' && letter <= 'Z'){
        return (int)letter + 32;
    }
    return (int)letter;
}

bool alphabetic(char str[]){
    for(int i = 1; i < strlen(str); i++){
        if(localeLetter(str[i]) < localeLetter(str[i-1])){
            return false;
        }
    } 
    return true;
}

bool doublechar(char str[]){
    int a[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i = 0; i < strlen(str); i++){
        a[localeLetter(str[i]) - 96]++;
    }
    for(int i = 0; i < 26; i++){
        if(a[i] < 2 && a[i] != 0){
            return false;
        }
    }
    return true;
}