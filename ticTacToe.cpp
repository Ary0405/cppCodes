#include<bits/stdc++.h>
using namespace std;
char arr[3][3];
#define rep(i,a,b) for(int i = a;i<b;i++)
struct twin{
    int x;
    int y;
};
int ch(int x,int y){
  rep(i,1,3){
    if(arr[x][i]!=arr[x][i-1]){
      return 0;
    }
  }
  return 1;
}
int cs(int x, int y){
  rep(i,1,3){
    if(arr[i][y]!=arr[i-1][y]){
      return 0;
    }
  }
  return 1;
}
int cd1(int x, int y){
  int i = 0;
  while(i<2){
    if(arr[i][i]!=arr[i+1][i+1] || arr[i][i]=='-'){
      return 0;
    }
    i++;
  }
  return 1;
}
int cd2(int x, int y){
  int i = 0,j=2;
  while(i<2 && j>0){
    if(arr[i][j]!=arr[i+1][j-1] || arr[i][j]=='-'){
      return 0;
    }
    i++;j--;
  }
  return 1;
}
bool checkValid(int x1, int y1){
    if(arr[x1][y1] != '-'){
        return false;
    }else{
        return true;
    }
}
bool cdc1(char token1, char token2){
    int count = 0;
    int i=0,j=0;
    while(i<3 && j<3){
        if(arr[i][j] == token1){
            count++;
        }
        if(arr[i][j] == token2){
            return false;
        }
        i++;j++;
    }
    if(count==2){
        return true;
    }else{
        return false;
    }
}
bool cdc2(char token1, char token2){
    int count = 0;
    int i=0,j=2;
    while(i<3 && j>=0){
        if(arr[i][j] == token1){
            count++;
        }
        if(arr[i][j] == token2){
            return false;
        }
        i++;j--;
    }
    if(count==2){
        return true;
    }else{
        return false;
    }
}
struct twin mainDig(){
    struct twin t;
    int i =0,j=0;
    while(i<3 && j<3){
        if(arr[i][j] == '-'){
            if(checkValid(i,j)){
            t.x =i;
            t.y = j;
            }
        }
        i++;j++;
    }
    return t;
}
struct twin digonal2(){
    struct twin t;
    int i =0,j=2;
    while(i<3 && j>=0){
        if(arr[i][j] == '-'){
            if(checkValid(i,j)){
            t.x = i;
            t.y = j;
            }
        }
        i++;j--;
    }
    return t;
}
bool hori(char token1, char token2){
    int count = 0;
    rep(i,0,3){
        if(arr[0][i]==token1){
            count++;
        }
        if(arr[0][i]==token2){
            break;
        }
    }
    if(count==2){
        return true;
    }
    count = 0;
    rep(i,0,3){
        if(arr[1][i]==token1){
            count++;
        }
        if(arr[1][i]==token2){
            break;
        }
    }
    if(count==2){
        return true;
    }
    count = 0;
    rep(i,0,3){
        if(arr[2][i]==token1){
            count++;
        }
        if(arr[2][i]==token2){
            break;
        }
    }
    if(count==2){
        return true;
    }
    return false;
}
struct twin horizontal(char token){
    struct twin t;
    int j1 = 0,j2=0;
    int count = 0;
    rep(i,0,3){
        if(arr[0][i]==token){
            count++;
            if(count==1){
                j1 = i;
            }
            if(count==2){
                j2 = i;
            }
        }
    }
    if(count==2){
        if(j1==0 && j2==1){
            t.x = 0;t.y = 2;
        }else if(j1==0 && j2==2){
            t.x = 0;t.y = 1;
        }else if(j1==1 && j2==2){
            t.x = 0;t.y = 0;
        }else if(j1==1 && j2==0){
            t.x = 0;t.y = 2;
        }else if(j1==2 && j2==0){
            t.x = 0;t.y = 1;
        }else if(j1==2 && j2==1){
            t.x = 0;t.y = 0;
        }
    }
    //2nd line
    count = 0;
    rep(i,0,3){
        if(arr[1][i]==token){
            count++;
            if(count==1){
                j1 = i;
            }
            if(count==2){
                j2 = i;
            }
        }
    }
    if(count==2){
        if(j1==0 && j2==1){
            t.x = 1;t.y = 2;
        }else if(j1==0 && j2==2){
            t.x = 1;t.y = 1;
        }else if(j1==1 && j2==2){
            t.x = 1;t.y = 0;
        }else if(j1==1 && j2==0){
            t.x = 1;t.y = 2;
        }else if(j1==2 && j2==0){
            t.x = 1;t.y = 1;
        }else if(j1==2 && j2==1){
            t.x = 1;t.y = 0;
        }
    }
    //3rd line
    count =0;
    rep(i,0,3){
        if(arr[2][i]==token){
            count++;
            if(count==1){
                j1 = i;
            }
            if(count==2){
                j2 = i;
            }
        }
    }
    if(count==2){
        if(j1==0 && j2==1){
            t.x = 2;t.y = 2;
        }else if(j1==0 && j2==2){
            t.x = 2;t.y = 1;
        }else if(j1==1 && j2==2){
            t.x = 2;t.y = 0;
        }else if(j1==1 && j2==0){
            t.x = 2;t.y = 2;
        }else if(j1==2 && j2==0){
            t.x = 2;t.y = 1;
        }else if(j1==2 && j2==1){
            t.x = 2;t.y = 0;
        }
    }
    return t;
}
bool vert(char token1, char token2){
    int count = 0;
    rep(i,0,3){
        if(arr[i][0]==token1){
            count++;
        }
        if(arr[i][0]==token2){
            break;
        }
    }
    if(count==2){
        return true;
    }
    count = 0;
    rep(i,0,3){
        if(arr[i][1]==token1){
            count++;
        }
        if(arr[i][1]==token2){
            break;
        }
    }
    if(count==2){
        return true;
    }
    count = 0;
    rep(i,0,3){
        if(arr[i][2]==token1){
            count++;
        }
        if(arr[i][2]==token2){
            break;
        }
    }
    if(count==2){
        return true;
    }
    return false;
}
struct twin vertical(char token){
    struct twin t;
    int count = 0;
    int i1,i2;
    rep(i,0,3){
        if(arr[i][0]==token){
            count++;
            if(count == 1){
                i1 = i;
            }
            if(count==2){
                i2 = i;
            }
        }
    }
    if(count==2){
        if(i1==0 && i2==1){
            t.x = 2;t.y = 0;
        }else if(i1==0 && i2==2){
            t.x = 1;t.y = 0;
        }else if(i1==1 && i2==2){
            t.x = 0;t.y = 0;
        }else if(i1==1 && i2==0){
            t.x = 2;t.y = 0;
        }else if(i1==2 && i2==0){
            t.x = 1;t.y = 0;
        }else if(i1==2 && i2==1){
            t.x = 0;t.y = 0;
        }
    }
    //2nd line
    count = 0;
    rep(i,0,3){
        if(arr[i][1]==token){
            count++;
            if(count == 1){
                i1 = i;
            }
            if(count==2){
                i2 = i;
            }
        }
    }
    if(count==2){
        if(i1==0 && i2==1){
            t.x = 2;t.y = 1;
        }else if(i1==0 && i2==2){
            t.x = 1;t.y = 1;
        }else if(i1==1 && i2==2){
            t.x = 0;t.y = 1;
        }else if(i1==1 && i2==0){
            t.x = 2;t.y = 1;
        }else if(i1==2 && i2==0){
            t.x = 1;t.y = 1;
        }else if(i1==2 && i2==1){
            t.x = 0;t.y = 1;
        }
    }
    //3rd line
    count=0;
    rep(i,0,3){
        if(arr[i][2]==token){
            count++;
            if(count == 1){
                i1 = i;
            }
            if(count==2){
                i2 = i;
            }
        }
    }
    if(count==2){
        if(i1==0 && i2==1){
            t.x = 2;t.y = 2;
        }else if(i1==0 && i2==2){
            t.x = 1;t.y = 2;
        }else if(i1==1 && i2==2){
            t.x = 0;t.y = 2;
        }else if(i1==1 && i2==0){
            t.x = 2;t.y = 2;
        }else if(i1==2 && i2==0){
            t.x = 1;t.y = 2;
        }else if(i1==2 && i2==1){
            t.x = 0;t.y = 2;
        }
    }
    return t;
}
int checkFull(){
  rep(i,0,3){
    rep(j,0,3){
      if(arr[i][j]=='-'){
        return 0;
      }
    }
  }
  return 1;
}
struct twin checkFirstEmpty(){
    struct twin t;
    rep(i,0,3){
        rep(j,0,3){
            if(arr[i][j] == '-'){
                if(checkValid(i,j)){
                t.x = i;
                t.y = j;
                return t;
                }
            }
        }
    }
}
int main(){
    rep(i,0,3){
        rep(j,0,3){
            arr[i][j] = '-';
        }
    }
    cout<<"Welcome to Tic-Tac-Toe"<<endl;
    cout<<"The Computer has been assigned O and you have been assigned X"<<endl;
    cout<<"Player goes first"<<endl;
    while(1){
        if(checkFull()==1){
            cout<<"Its a tie :)\n\n";
            cout<<"Thanks for playing :)\n";
            exit(0);
        }
        int x1,y1;
        int valid = 0;
        while(valid != 1){
            cout<<"Enter co-ordinates of the point : -";
            cin>>x1>>y1;
            if(x1<0 || x1>2 || y1<0 || y1>2){
                cout<<"Re-enter"<<endl;
            }
            if(checkValid(x1,y1)==false){
                cout<<"Re-enter"<<endl;
            }else{
                arr[x1][y1] = 'X';
                valid =1;
            }
        }
        cout<<"Current status of grid :- "<<endl;
        rep(i,0,3){
            rep(j,0,3){
                cout<<arr[i][j]<<" ";
            }cout<<endl;
        }
        if(ch(x1,y1)==1 || cd1(x1,y1)==1 || cd2(x1,y1)==1 || cs(x1,y1)==1){
            cout<<"Congratulations to player on winning this game :) !!!\n\n";
            cout<<"Thanks for playing :)\n";
            exit(0);
        }
        if(checkFull()==1){
            cout<<"Its a tie :)\n\n";
            cout<<"Thanks for playing :)\n";
            exit(0);
        }
        if(cdc1('O','X')){
            struct twin t = mainDig();
            arr[t.x][t.y] = 'O';
            cout<<"Current status:- \n";
            rep(i,0,3){
                rep(j,0,3){
                    cout<<arr[i][j]<<" ";
                }cout<<endl;
            }
            if(ch(t.x,t.y)==1 || cd1(t.x,t.y)==1 || cd2(t.x,t.y)==1 || cs(t.x,t.y)==1){
                cout<<"Sorry you lost :( \n\n";
                cout<<"Thanks for playing :)\n";
                exit(0);
            }
        }
        else if(cdc1('X','O')==true){
            struct twin t = mainDig();
            arr[t.x][t.y] = 'O';
            cout<<"Current status:- \n";
            rep(i,0,3){
                rep(j,0,3){
                    cout<<arr[i][j]<<" ";
                }cout<<endl;
            }
            if(ch(t.x,t.y)==1 || cd1(t.x,t.y)==1 || cd2(t.x,t.y)==1 || cs(t.x,t.y)==1){
                cout<<"Sorry you lost :( \n\n";
                cout<<"Thanks for playing :)\n";
                exit(0);
            }
        }
        else if(cdc2('O','X')){
            struct twin t = digonal2();
            arr[t.x][t.y] = 'O';
            cout<<"Current status:- \n";
            rep(i,0,3){
                rep(j,0,3){
                    cout<<arr[i][j]<<" ";
                }cout<<endl;
            }
            if(ch(t.x,t.y)==1 || cd1(t.x,t.y)==1 || cd2(t.x,t.y)==1 || cs(t.x,t.y)==1){
                cout<<"Sorry you lost :( \n\n";
                cout<<"Thanks for playing :)\n";
                exit(0);
            }
        }
        else if(cdc2('X','O')==true){
            struct twin t = digonal2();
            arr[t.x][t.y] = 'O';
            cout<<"Current status:- \n";
            rep(i,0,3){
                rep(j,0,3){
                    cout<<arr[i][j]<<" ";
                }cout<<endl;
            }
            if(ch(t.x,t.y)==1 || cd1(t.x,t.y)==1 || cd2(t.x,t.y)==1 || cs(t.x,t.y)==1){
                cout<<"Sorry you lost :( \n\n";
                cout<<"Thanks for playing :)\n";
                exit(0);
            }
        }
        else if(hori('O','X')){
            struct twin t = horizontal('O');
            arr[t.x][t.y] = 'O';
            cout<<"Current status:- \n";
            rep(i,0,3){
                rep(j,0,3){
                    cout<<arr[i][j]<<" ";
                }cout<<endl;
            }
            if(ch(t.x,t.y)==1 || cd1(t.x,t.y)==1 || cd2(t.x,t.y)==1 || cs(t.x,t.y)==1){
                cout<<"Sorry you lost :( \n\n";
                cout<<"Thanks for playing :)\n";
                exit(0);
            }
        }
        else if(hori('X','O')){
            struct twin t = horizontal('X');
            arr[t.x][t.y] = 'O';
            cout<<"Current status:- \n";
            rep(i,0,3){
                rep(j,0,3){
                    cout<<arr[i][j]<<" ";
                }cout<<endl;
            }
            if(ch(t.x,t.y)==1 || cd1(t.x,t.y)==1 || cd2(t.x,t.y)==1 || cs(t.x,t.y)==1){
                cout<<"Sorry you lost :( \n\n";
                cout<<"Thanks for playing :)\n";
                exit(0);
            }
        }
        else if(vert('O','X')){
            struct twin t = vertical('O');
            arr[t.x][t.y] = 'O';
            cout<<"Current status:- \n";
            rep(i,0,3){
                rep(j,0,3){
                    cout<<arr[i][j]<<" ";
                }cout<<endl;
            }
            if(ch(t.x,t.y)==1 || cd1(t.x,t.y)==1 || cd2(t.x,t.y)==1 || cs(t.x,t.y)==1){
                cout<<"Sorry you lost :( \n\n";
                cout<<"Thanks for playing :)\n";
                exit(0);
            }
        }
        else if(vert('X','O')){
            struct twin t = vertical('X');
            arr[t.x][t.y] = 'O';
            cout<<"Current status:- \n";
            rep(i,0,3){
                rep(j,0,3){
                    cout<<arr[i][j]<<" ";
                }cout<<endl;
            }
            if(ch(t.x,t.y)==1 || cd1(t.x,t.y)==1 || cd2(t.x,t.y)==1 || cs(t.x,t.y)==1){
                cout<<"Sorry you lost :( \n\n";
                cout<<"Thanks for playing :)\n";
                exit(0);
            }
        }
        else{
            struct twin t =checkFirstEmpty();
            arr[t.x][t.y] = 'O';
            cout<<"Current status of grid :- "<<endl;
            rep(i,0,3){
                rep(j,0,3){
                    cout<<arr[i][j]<<" ";
                }cout<<endl;
            }
            if(ch(t.x,t.y)==1 || cd1(t.x,t.y)==1 || cd2(t.x,t.y)==1 || cs(t.x,t.y)==1){
                cout<<"Sorry you lost :( \n\n";
                cout<<"Thanks for playing :)\n";
                exit(0);
            }
        }
    }
    return 0;
}