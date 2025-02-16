#include <iostream>
#include <vector>

namespace std;

bool searchBinary(int num, const vector<int>& myList) {

    int start = 0;
    int end = myList.size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (myList[mid] == num) {
            return true;
        } else if (myList[mid] < num) {
            start = mid + 1; 
        } else {
            end = mid - 1; 
        }
    }

    return false; 
}

int main() {
    vector<int> myList = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39};

    int number = 90;
    bool result = searchBinary(number, myList);

    if (result) {
        cout << number << " oui " << endl;
    } else {
        cout << number << " non " << endl;
    }

    return 0;
}
