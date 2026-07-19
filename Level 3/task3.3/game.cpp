#include <iostream>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void print_board() {
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2){cout << "|";}
        }
        if (i < 2){cout << "\n---|---|---\n";}
    }
    cout<<"\n";
}

bool player_win(int c) {// all cases of winners
    // Horizontal rows
    if ((board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
    (board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
    (board[2][0] == board[2][1] && board[2][1] == board[2][2]) ||

    // Diagonals
    (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
    (board[0][2] == board[1][1] && board[1][1] == board[2][0]) ||

    // Vertical columns
    (board[0][0] == board[1][0] && board[1][0] == board[2][0]) ||
    (board[0][1] == board[1][1] && board[1][1] == board[2][1]) ||
    (board[0][2] == board[1][2] && board[1][2] == board[2][2])){
        if (c%2==0) {
            cout<<"player 2 win!!\n";
        }
        else {
            cout<<"player 1 win!!\n";
        }
        return true;
    }
    return false;
}

bool play(int r,int c,int t) {// play1->odd/plat2->even
   if (t%2==0) {//play2
       if (board[r][c]!='X' && board[r][c]!='O') {
           board[r][c]='O';
           return true;
       }
       else {
           cout<<"invalid choice! \n";
           return false;
       }
   }else {//play1
       if (board[r][c]!='X' && board[r][c]!='O') {
           board[r][c]='X';
           return true;
       }
       else {
           cout<<"invalid choice! \n";
           return false;
       }
   }

}

bool Draw() {
    int count=0;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (board[i][j]!='X' && board[i][j]!='O') {count++;}
        }
    }
    if (count==0) {
        cout<<"DRAW!!\n";
        return true;
    }
    return false;
}

int main() {
cout << "--- Tic-Tac-Toe Game ---\n";
    int counter=0;
    for (int i=0;i<9;i++) {
        print_board();
        cout<<"choose number from 1 to 9: \n"; int num; cin>>num;
        int row=(num-1)/3,col=(num-1)%3;
        counter++;
        if (!play(row,col,counter)) {
            i--;
        }
        if (player_win(counter)) {
            return 0;
        }
    }
    Draw();

    return 0;
}