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

void printArray(vector<int> arr){
    for(int i =0 ; i<arr.size();i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl;
}

vector<int> findAverage(vector<vector<int>>arr,int subs,int students){
    vector <int> avgmarks (subs , 0);
    for(int i = 0;i<arr.size() ; i++){
        avgmarks[arr[i][1]]+=arr[i][2]/students;
    }
    return avgmarks;
}

pair<int , int> highestAverage(vector <vector<int >> arr ,int subs,int students  ){
    vector <int > avgMarks;
    avgMarks = findAverage(arr , subs,students);
    int maxmarks = 0;
    int subno;
    for(int i = 0 ; i < avgMarks.size();i++){
        if(maxmarks<avgMarks[i]){
            maxmarks = avgMarks[i];
            subno = i;
        }
    }
    return {maxmarks , subno};
}

int main(){
    vector <vector <int> > nums = {
        {0,0,10 , 0},
        {21 , 0 , 17 ,0},
        {0,12 , 0 ,0 },
        {0,0,7,0},
        {0,0,25,3},
        {12,0,0,1},
        {0,0,56,0},
    };
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
    cout<<"avg marks : " <<endl;
    printArray(findAverage(efficientArr , nums[0].size(),nums.size()));
    pair < int , int > highest ;
    highest = highestAverage(efficientArr , nums[0].size(),nums.size());
    cout<<"maximum average : "<<highest.first <<" Subject : "<<highest.second;
}
