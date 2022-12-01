#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

int main() {
    FILE *file;
    file = fopen("gistfile1.txt", "r+");
    char* word = new char[25];
    cout << "Введите слово: ";
    gets(word);
    fseek(file, 0, SEEK_SET);
    while(true){
        if ((char*)fgetc(file) == " "){
            fseek(file, -1, SEEK_CUR);
            if (word[-1] == (char)fgetc(file)){
                fseek(file, -1, SEEK_CUR);
                if (word[-2] == (char)fgetc(file)){
                    for (int i = -10; i <= 2; i++){
                        fseek(file, i, SEEK_CUR);
                        char s = fgetc(file);
                        cout << s;
                    }
                    fputs("\n", file);
                    cout << "\n";
                }
            }
        } else fseek(file, 1, SEEK_CUR);
        if (feof(file) == 0) continue;
        else break;
    }
    delete[] word;
        
    //ifstream f;
    //f.open("gistfile1.txt");
    //f.get(str, 199);
    //f.close();
}
