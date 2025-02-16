#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> myList= {1,3,2,9,10,4,5,6,7,8};

    int size = myList.size(); 
for ( int j = 0; j < size; j++)
{
for ( int i = 0; i < size-1; i++)
{
   if(myList[i]>myList[i+1]){

        int temp = myList[i];
        myList[i]=myList[i+1];
        myList[i+1] = temp;
       
    }
}
}
       
    for (int j=0; j < size ;j++){
        cout << myList[j] << " ";
    }
    
    return 0;
}