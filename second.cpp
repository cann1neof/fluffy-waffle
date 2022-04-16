#include <iostream>
#include <string>

using namespace std;

bool alphabetic(string str);
bool doublechar(string str);

int main(int argc, char const *argv[])
{
    string str, output, word;
    getline(cin, str);
    int start, end = -1;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' ' || str[i] == ','){
            start = end + 1;
            end = i;
            word = str.substr(start, end-start);
            if(alphabetic(word)){
                cout << word << endl;
            }
            if(!doublechar(word)){
                if(start != 0){
                    output.append(" ");
                }
                output.append(word);
            }
        }
    }
    cout << output << endl;
    return 0;
}

int localeLetter(char letter){
    if(letter >= 'A' && letter <= 'Z'){
        return (int)letter + 32;
    }
    return (int)letter;
}

bool alphabetic(string str){
    for(int i = 1; i < str.length(); i++){
        if(localeLetter(str[i]) < localeLetter(str[i-1])){
            return false;
        }
    } 
    return true;
}

bool doublechar(string str){
    int a[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i = 0; i < str.length(); i++){
        a[localeLetter(str[i]) - 96]++;
    }
    for(int i = 0; i < 26; i++){
        if(a[i] < 2 && a[i] != 0){
            return false;
        }
    }
    return true;
}
