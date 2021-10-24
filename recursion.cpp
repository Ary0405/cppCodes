#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
//N Quuen Problem
bool isposs(int** arr, int x, int y, int n)
{
    for(int row = 0;row<x;row++){
        if(arr[row][y]==1){
            return false;
        }
    }
    int row = x;
    int col = y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;col--;
    }
    row = x;
    col = y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;col++;
    }
    return true;
}
bool nQueen(int** arr, int x, int n){
    if(x>=n){
        return true;
    }
    for(int col=0;col<n;col++){
        if(isposs(arr,x,col,n)){
            arr[x][col]=1;
            if(nQueen(arr,x+1,n)){
                return true;
            }
            arr[x][col] = 0;
        }
    }
    return false;
}
//Permutations
void permute(vector<int> &a, int idx)
{
    if(idx == a.size()){
        ans.push_back(a);
        return;
    }
    for(int i = idx;i<a.size();i++){
        swap(a[i],a[idx]);
        permute(a,idx+1);
        swap(a[i],a[idx+1]);
    }
    return;
}
//Rat in a maze
bool isSafe(int** arr, int x, int y, int n)
{
    if(x<n && y<n && arr[x][y] == 1){
        return true;
    }
    return false;
}
bool ratInMaze(int** arr, int x, int y, int n, int** solArr)
{
    if(x==(n-1) && y==(n-1)){
        solArr[x][y] = 1;
        return true;
    }
    if(isSafe(arr,x,y,n)){
        solArr[x][y] = 1;
        if(ratInMaze(arr,x+1,y,n,solArr)){
            return true;
        }
        if(ratInMaze(arr,x,y+1,n,solArr)){
            return true;
        }
        solArr[x][y] = 0; //backtrack
        return false;
    }
    return false;
}
//Knapsack Problem
int knapsack(int value[], int wt[], int n, int W)
{
    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1]>W){
        return  knapsack(value, wt,n-1,W);
    }
    int inclNthitem = knapsack(value,wt,n-1,W-wt[n-1]) + value[n-1];
    int notIncluNthitem = knapsack(value, wt,n-1,W);
    return max(inclNthitem,notIncluNthitem);
}
//Friends Pairing Problem
int friendsPairing(int n){
    if(n==0){
        return 0;
    }
    if(n==1 || n==2){
        return n;
    }
    return friendsPairing(n-1) + friendsPairing(n-2)*(n-1);
}
//Tilling Problem
int tillingways(int n){
    if(n==0 || n==1){
        return n;
    }
    return (tillingways(n-1)+tillingways(n-2));
            //vertical       horizontal
}
//Count the number of possible paths in a maze
int countMaze(int n, int i, int j)
{
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    int count = 0;
    count = countMaze(n,i+1,j) + countMaze(n,i,j+1);
    return count;
}
//No of possible paths from start to end point in a gameboard
int countPath(int s, int e)
{
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count = 0;
    for(int i=1;i<=6;i++){
        count+=countPath(s+i,e);
    }
    return count;
}
//Print all permutations of a string
void permutation(string s, string ans)
{
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];
        string ros = s.substr(0,i) + s.substr(i+1);
        permutation(ros,ans+ch);
    }
}
//Print all possible words from phone digits
string keypadArr[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string s, string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string code = keypadArr[ch-'0'];
    string ros = s.substr(1);
    for(int i=0;i<code.length();i++)
    {
        keypad(ros,ans+code[i]);
    }

}
//Generate Subtrings with ascii number
void substrings(string s, string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    substrings(ros,ans);    
    substrings(ros,ans+ch);    
    substrings(ros,ans+to_string(code));    

}
//Generate all Substrings of the given strings
void subseq(string s, string ans)
{
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    subseq(ros,ans);
    subseq(ros,ans+ch);
}
//Move all x to the end of the string
string movex(string s)
{
    if(s.length() == 0){
        return "";
    }
    char ch = s[0];
    string ans = movex(s.substr(1));
    if(ch=='x'){
        return ans+ch;
    }
    return ch+ans;
}
//Remove all duplicates from a sorted string
string removeDup(string s)
{
    if(s.length()==0){
        return "";
    }
    char ch = s[0];
    string ros = removeDup(s.substr(1));
    if(ch == ros[0]){
        return ros;
    }
    return (ch+ros);
}
//Tower of Hanoi
void towerOfHanoi(int n, char src, char dest, char helper)
{
    if(n==0){
        return;
    }
    towerOfHanoi(n-1,src,helper,dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1,helper,dest,src);
}
//Replace pi with 3.14 in a string
void replacePi(string s)
{
    if(s.length()==0)
    {
        return;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        replacePi(s.substr(2));
    }else{
        cout<<s[0];
        replacePi(s.substr(1));
    }
}
//Reverse a string using recurrsion
void reverse(string s)
{
    if(s.length()==0){
        return;
    }
    string ros = s.substr(1);
    reverse(ros);
    cout<<s[0];
}
//Find first and last occurance of an element in an array
int first(int arr[], int n, int i, int key)
{
    if(i==n)
    {
        return -1;
    }
    if(arr[i] == key)
    {
        return i;
    }
    return first(arr,n,i+1,key);
}
int last(int arr[], int n, int i, int key)
{
    if(i==0)
    {
        return -1;
    }
    if(arr[i]==key)
    {
        return i;
    }
    return last(arr,n,i-1,key);
}
//Print numbers till n in increasing order
void inc(int n)
{
    if(n==0)
    {
        return;
    }
    inc(n-1);
    cout<<n<<endl;
}
//Print numbers till n in decreasing order
void dec(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}
//Check if array is sorted or not
bool sorted(int arr[], int n)
{
    if(n==1){
        return true;
    }
    bool restArray = sorted(arr+1, n-1);
    if(arr[0]<arr[1] && restArray)
    {
        return true;
    }else{
        return false;
    }
}
//Print nth fibonacci number
int fibonacci(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    return (fibonacci(n-1) + fibonacci(n-2));
}
//Calculate factorial of a number
int factorial(int n)
{
    if(n==0){
        return 1;
    }
    return (n*factorial(n-1));
}
//Calculate n raised to power of p
int power(int n, int p)
{
    if(p==0){
        return 1;
    }
    int prevPower = power(n,p-1);
    return n*prevPower;
}
//Add all numbers till n
int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    return (n+sum(n-1));
}
//Main Function
int main()
{
    // int n;
    // cin>>n;
    // int** arr = new int*[n];
    // for(int i=0;i<n;i++){
    //     arr[i]=new int[n];
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // int** solArr = new int*[n];
    // for(int i=0;i<n;i++){
    //     arr[i]=new int[n];
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         solArr[i][j]=0;
    //     }
    // }
    // if(ratInMaze(arr,0,0,n,solArr)){
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             cout<<solArr[i][j]<<" ";
    //     }cout<<endl;
    // }
    // }

    int n;
    cin>>n;
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
        
            for(int j=0;j<n;j++){

                cout<<arr[i][j]<<" ";

            }cout<<endl;
        }
    }

    return 0;
}