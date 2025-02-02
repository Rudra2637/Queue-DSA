#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int arr[7]={2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    deque<int>maxi(k);
    deque<int>mini(k);
    for(int i=0;i<k;i++){
        while(!maxi.empty() && arr[maxi.front()] < arr[i]){
            maxi.pop_front();
        }
        while(!mini.empty() && arr[mini.front()] > arr[i]){
            mini.pop_front();
        }
        maxi.push_back(i);
        
        mini.push_back(i);
    }
    int sum = 0;
    sum += arr[maxi.front()]+arr[mini.front()];
    for(int i=k;i<7;i++){
        
        while(!maxi.empty() && i-maxi.front() >=k){
            maxi.pop_front();
        }
        while(!mini.empty() && i-mini.front() >=k){
            mini.pop_front();
        }
        
        while(!maxi.empty() && arr[maxi.front()] < arr[i]){
            maxi.pop_front();
        }
        
        while(!mini.empty() && arr[mini.front()] > arr[i]){
            mini.pop_front();
        }
        
        maxi.push_back(i);
        mini.push_back(i);
        sum += arr[maxi.front()]+arr[mini.front()];
    }
    cout<<sum<<endl;
    return 0;
}