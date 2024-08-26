#include <bits/stdc++.h>
using namespace std;
void printArray(vector <vector <int> > arr){
    for(int i = 0 ;i < arr.size();i++){
        for(int j = 0 ;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector <vector <int> > nums = {
        {0,0,10 , 0},
        {21 , 0 , 17 ,0},
        {0,12 , 0 ,0 },
        {0,0,7,0},
        {0,0,25,3}};
    vector <vector <int> >efficientArr;
    printArray(nums);
    int nonzeros = 0;
    for(int i = 0 ;i < nums.size();i++){
        for(int j = 0 ;j<nums[0].size();j++){
            if(nums[i][j]!=0){
                int num =nums[i][j];
                vector<int> temp = {i , j , num};
                efficientArr.push_back(temp);
            }
        }
    }
    cout<<"Efficient Array : " <<endl;
    printArray(efficientArr);
}
