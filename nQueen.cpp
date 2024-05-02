#include<bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> board;
bool isSafe(int row,int col){
     int i,j;
     for(i=0;i<col;i++){
        if(board[row][i])return false;
     }
     for(i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j])return false;
     }
     for(i=row,j=col; j>=0 && i<N ;i++,j--){
        if(board[i][j]) return false;
     }
    return true;
}

bool nQueenUtils(int col){
    if(col>= N) return true;
    for(int i=0; i<N;i++){
        if(isSafe(i,col)){
            board[i][col] = 1;
            if(nQueenUtils(col+1)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void solveNQueens()
{
   if(!nQueenUtils(0)){
    cout<<"doesnt exist"<<endl;
    return;
   }
   for(int i=0;i < N;i++){
     for(int j=0;j<N;j++){
        cout<< board[i][j] <<" ";
     }
     cout<<endl;
   }
}

int main() {
    cout << "Enter the number of queens: ";
    cin >> N;

    // Resize and initialize the board
    board.resize(N, vector<int>(N, 0));

    solveNQueens();

    return 0;
}
