#include <iostream>
#include <sstream>
using namespace std;

void q_sort (int *mas, int left, int right ) {
    int c_left = left;
    int c_right = right;
    int p = c_left;
    while (c_left <= c_right) {
        while (mas[c_right] > mas [p] && c_right >= left ){
          right--;
        }
        while ( (mas[c_left] < mas [p]) && (c_left <= right) ){
            left++;
        }
        if (c_left <=c_right){
            swap(mas[c_left], mas [c_right]);
            c_left++;
            c_right--;
        }
    }
        if (c_left < right) q_sort(mas, c_left, right);
        if (c_right > left) q_sort(mas, left, c_right);
}

int main() {
    int size;
    int *mas = new int [size];
    if (cin >> size){
        if (size < 0){
        cout << "An error has occured while reading input data.";
        return -1;
        }
        mas = new int [size];
    }
    else {
        cout<<"error"<<endl;
        return -1;
    }
    cin.get();
    string stroka;
    getline (cin, stroka);
    istringstream stream (stroka);
    for (int i=0; i<size;i++) {
        if (!(stream >> mas[i])) {
            cout << "An error has occured while reading input data." << endl;
            delete[]mas;
            return -1;
        }
    }
    int left = mas[0];
    int right = mas [size-1];
    q_sort (mas, left, right);
    for(int i=0; i<size; i++){
        cout << mas[i] << " ";
    }
    delete[]mas;
    return 0;
}
