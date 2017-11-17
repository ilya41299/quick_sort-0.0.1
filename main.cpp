#include <iostream>
#include <sstream>
using namespace std;

void q_sort (int *mas, int left, int right ) {
    int p = mas [left];
    int c_left = left;
    int c_right = right;
    while (left < right) {
        while ((mas[right] >= p) && (left < right)){
          right--;
            if(left != right){
                mas [left] = mas [right];
                left++;
            }
        }
        while ( (mas[left] <= p) && (left < right) ){
            left++;
            if(left != right){
                mas [right] = mas [left];
                right--;
            }
        }
    }
    mas [left] = p;
    p = left;
    left = c_left;
    right = c_right;
    if (left < p) {
        q_sort (mas, left, p-1);
    }
    if (right > p)
        q_sort(mas, p + 1, right);




}

int main() {
    unsigned int size;
    int *mas = new int [size];
    if (cin >> size){
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
    for (unsigned int i=0; i<size;i++) {
        if (!(stream >> mas[i])) {
            cout << "ERROR" << endl;
            delete[]mas;
            return -1;
        }
    }
    int left = mas[1];
    int right = mas [size];
    q_sort (mas, left, right);
    for(unsigned int i=0; i<size; i++){
        cout << mas[i] << " ";
    }
    delete[]mas;
    return 0;

}
