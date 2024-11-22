//Given an array of integers, sort it in descending order using merge sort algorithm.
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &a,vector<int> &b,vector<int> &res){
    int i=0;
    int j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
         if(a[i]>=b[j]) res[k++]=a[i++];
         else res[k++]=b[j++];
    }
    if(i==a.size()) while(j<b.size()) res[k++]=b[j++];//a is at end
    if(j==b.size()) while(i<a.size()) res[k++]=a[i++];//b is at end
}
void mergeSortDe(vector<int>&v){
    int size=v.size();
    if(size==1) return;
    int n1=size/2,n2=size-n1;
    vector<int> v1(n1),v2(n2);
    for(int i=0;i<n1;i++) v1[i]=v[i];
    for(int i=0;i<n2;i++) v2[i]=v[i+n1];
    mergeSortDe(v1);
    mergeSortDe(v2);
    merge(v1,v2,v);
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergeSortDe(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    
}
