#include<iostream>
#include<vector>
using namespace std;

int recbinarysearch(vector<int>arr, int st, int end, int tar){

  while (st <= end)
  {
    int mid = st+(end-st)/2;
    
    if(/* code */tar > arr[mid])
    {
      return recbinarysearch(arr, mid+1, end, tar);
    }else if(tar<arr[mid]){
      return recbinarysearch(arr, st, mid-1, tar);
    }else{
      return mid;
    }
  }
  return -1;
  
}

int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tar = 7;

    cout<<recbinarysearch(arr1, 0, arr1.size()-1, tar)<<endl;

    return 0;
}
