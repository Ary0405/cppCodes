#include<bits/stdc++.h>
using namespace std;
long long mergeq(int arr[], int l, int mid, int r)
{
    long long inv = 0;
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+i+1];
    }
    int i = 0;int j=0;int k = l;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j]){
            arr[k]=a[i];
            k++;i++;
        }
        else{
            arr[k]=b[j];
            inv+=(n1-i);
            k++;j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        i++;k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;k++;
    }
    return inv;

}
long long mergesortq(int arr[],int l, int r)
{
    long long inv = 0;
    if(l<r)
    {
        int mid = (l+r)/2;
        inv += mergesortq(arr,l,mid);
        inv += mergesortq(arr,mid+1,r);
        inv += mergeq(arr,l,mid,r);
    }
    return inv;
}
//Wave Sort
void waveSort(int arr[], int n)
{
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
//DNF Sort
void DNFSort(int arr[], int n)
{
    int low = 0;
    int high = n-1;
    int mid = 0;
    while(mid<high)
    {
        if(arr[mid]==1){
            mid++;
        }
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            mid++;low++;
        }
        if(arr[mid]==2){
            swap(arr[high],arr[mid]);
            high--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
//Count Sort
void countSort(int arr[], int n)
{
    int k = arr[0];
    for(int i=0;i<n;i++)
    {
        k=max(k,arr[i]);
    }
    int count[10]={0};
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(int i=1;i<=k;i++)
    {
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--)
    {
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}
//Quick Sort
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l-1;
    for(int j=0;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return (i+1);
}
void quickSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int pi = partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}
//Merge Sort
void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i] = arr[mid+l+i];
    }
    int i=0, j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++;i++;
        }else{
            arr[k]=b[j];
            k++;j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++;i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++;j++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
//Main Function
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<mergesortq(arr,0,n-1)<<endl;
    return 0;
}