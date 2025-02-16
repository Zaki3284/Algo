#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector<int> myList1 = {1, 4, 7};
	vector<int> myList2 ={2, 5, 8};
    vector<int> myList ;

    for(int i=0 ;i<myList1.size();i++){
    	
    	if (myList1[i]<myList2[i])
    	{
    		myList.push_back(myList1[i]);
    		 
    	}
        if(myList2[i] < myList1[i+1]){
        	myList.push_back(myList2[i]);
        }

        
    }

    for (int i = 0; i < myList.size(); ++i)
    {
    	cout << myList[i] << " ";
    }
}