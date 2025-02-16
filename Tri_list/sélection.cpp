#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> myList = {1, 3, 2, 9, 10, 4, 5, 6, 7, 8};
    int size = myList.size();

    
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (myList[j] < myList[minIndex]) {
                minIndex = j;
            }
        }
        
        swap(myList[i], myList[minIndex]);
    }

       
    for (int i = 0; i < size; i++) {
        cout << myList[i] << " ";
    }

    return 0;
}
