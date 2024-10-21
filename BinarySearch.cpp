#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements : " ;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int numtbf;
    cout<<"Enter number to be found : ";
    cin>>numtbf;
    int low = 0;
    int high = n-1;
    bool check = false;
    while(high>=low){
        int mid = high/2 - low/2+low;
        if(arr[mid]<numtbf){
            low=mid+1;
        }
        else if(arr[mid]==numtbf){
            check = true;
            break;
        }
        else{
            high = mid-1;
        }
    }
    if(check) cout<<"Found";
    else cout<<"Not Found";
}
