#include <iostream>
#include <vector>

using namespace std;

void result(int number, vector<int>& myList, int& debit, int& end) {
    int mid = (debit + end) / 2;

    if (myList[mid] == number) {
        debit = mid;  
        end = mid;     
    } else if (number < myList[mid]) {
        end = mid - 1;  
    } else {
        debit = mid + 1;  
    }
}

int main() {
    vector<int> myList = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39};
    
    int number = 90;
    int debit = 0;
    int end = myList.size() - 1;

    while (debit <= end) {
        result(number, myList, debit, end);
    }

    if (debit <= end && myList[debit] == number)
        cout << number << " found in the list!" << endl;
    else
        cout << number << " not found in the list!" << endl;

    return 0;
}
