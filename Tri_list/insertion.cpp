#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myList = {1,3,2,9,10,4,5,6,7,8};
	int size = myList.size();

	for (int i = 1; i < size; i++)
	{
		for (int j = i ; j > 0 ;j--){
			if(myList[j] < myList[j-1]){
                  
               int temp = myList[j-1];
               myList[j-1]=myList[j];
                myList[j] = temp;
                
                }
		}
	}

    for (int j=0; j < size ;j++){
        cout << myList[j] << " ";
    }
	return 0;
}