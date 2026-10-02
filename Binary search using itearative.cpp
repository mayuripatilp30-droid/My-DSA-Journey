#include<iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int>arr, int tar){
  int st=0, end=arr.size()-1;
  while (st <= end)
  {
    int mid = (st+end)/2;
    
    if(/* code */tar > arr[mid])
    {
      st = mid+1;
    }else if(tar<arr[mid]){
      end=mid-1;
    }else{
      return mid;
    }
  }
  return -1;
  
}

int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tar1 = 7;

    cout<<binarysearch(arr1, tar1)<<endl;

    vector<int> arr2 = {1, 2, 3, 4, 5, 6, };
    int tar2 = 3;

    return 0;
}
