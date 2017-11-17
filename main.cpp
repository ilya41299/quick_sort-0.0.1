#include <iostream>
#include <sstream>
#include <utility>
using namespace std;

bool read (istream & stream, int *mas, int &size) {
    bool res = true;
    for (int i=0; i < size; i++) {
        if (!(stream >> mas[i])) {
            res = false;
            break;
        }
    }
    return res;
}

void q_sort (int *mas, int left, int right ) {
    int c_left = left;
    int c_right = right;
    int p = c_left;
    while (c_left <= c_right) {
        while (mas[c_right] > mas[p] && c_right > left )
            c_right--;
        
        while ( (mas[c_left] < mas[p]) && (c_left < right) )
            c_left++;
        
        if (c_left <=c_right){
            swap(mas[c_left], mas [c_right]);
            c_left++;
            c_right--;
        }
    }
    if (left < c_right) {
        q_sort(mas, left, c_right);
    }
    if (c_left < right) {
        q_sort(mas, c_left, right);
    }
}

int main() {
    int size;


    if(!(cin >> size)) {
        cout << "An error has occured while reading numbers from line";
        return 1;
    }
    int *mas;

    cin.get();
    string string;
    getline(cin, string);
    istringstream stream(string);
    mas = new int [size];

    if(read(stream, mas, size)){

        q_sort (mas, 0, size-1);
        for(int i=0; i<size; i++){
            cout << mas[i] << " ";
        }
        delete[]mas;
    }
    else {
        cout << "An error has occured while reading numbers from line";
    }
    delete[]mas;
    return 0;
}
