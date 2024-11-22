//Reverse Pairs (Leetcode Problem) : Given an integer array nums, return the number of reverse
//pairs in the array. Also i have solved it on leetcode.
#include<iostream>
#include<vector>
using namespace std;
int ReversePairs(vector<int> &a,vector<int> &b){
    int i=0,j=0;
    int count=0;
    while(i<a.size() && j<b.size()){
        if((long long )a[i]>(long long) 2*b[j]) {  //Calculate the number of reverse pairs
            count+=(a.size()-i);
            j++;
        }
        else{ 
            i++;
        }
    }
    return count;
}
void merge(vector<int> &a,vector<int> &b,vector<int> &res){
    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]) res[k++]=a[i++];
        else res[k++]=b[j++];
    }
    if(i==a.size()) while(j<b.size()) res[k++]=b[j++];//a is at end
    if(j==b.size()) while(i<a.size()) res[k++]=a[i++];//b is at end
}
int mergeSort(vector<int>& v){
    int count=0;
    int size=v.size();
    if(size==1) return 0;
    int n1=size/2,n2=size-size/2;
    vector<int> v1(n1),v2(n2);
    for(int i=0;i<n1;i++) v1[i]=v[i];// Copy paste
    for(int i=0;i<n2;i++) v2[i]=v[i+n1];
    count+=mergeSort(v1);
    count+=mergeSort(v2);
    count+=ReversePairs(v1,v2);
    merge(v1,v2,v);
    v1.clear();
    v2.clear();
    return count;
}
int main(){
    int arr[]={1,3,2,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n);
    cout<<endl;
    cout<<"Number of reverse Pair is: "<<mergeSort(v);
}
