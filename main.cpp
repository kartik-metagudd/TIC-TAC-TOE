#include<iostream>
#include<string>
using namespace std;

string p1,p2;

char ttt[3][3]=
{{'_','_','_'},
{'_','_','_'},
{'_','_','_'}};

bool checkWin(char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((ttt[i][0] == player && ttt[i][1] == player && ttt[i][2] == player) || 
            (ttt[0][i] == player && ttt[1][i] == player && ttt[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((ttt[0][0] == player && ttt[1][1] == player && ttt[2][2] == player) || 
        (ttt[0][2] == player && ttt[1][1] == player && ttt[2][0] == player)) {
        return true;
    }

    return false;
}

void winner() {
    if (checkWin('X')) {
        cout << p1 << " wins..!" << endl;
        exit(0); // End the game
    } else if (checkWin('O')) {
        cout << p2 << " wins..!" << endl;
        exit(0); // End the game
    }
}




    
void display(){
    for(int i=0;i<3;i++){
        cout<<"|";
        for(int j=0;j<3;j++){
            cout<<" "<<ttt[i][j]<<"  ";
        }
        cout<<"|"<<endl<<endl;
    }
}
void input(int& turn) {
    int a, b;
    bool validInput = false;

    while (!validInput) {
        if (turn % 2 == 0) {
            cout << p2 << "'s turn. Enter coordinates with a space between them: ";
        } else {
            cout << p1 << "'s turn. Enter coordinates with a space between them: ";
        }

        cin >> a >> b;

        // Validate the input coordinates
        if (a >= 0 && a <= 2 && b >= 0 && b <= 2 && ttt[a][b] == '_') {
            validInput = true; // Exit the loop if input is valid

            if (turn % 2 == 0) {
                ttt[a][b] = 'O';
            } else {
                ttt[a][b] = 'X';
            }

            display();
            winner();

            // Increment the turn only after a valid move
            turn++;
        } else {
            cout << "Invalid input! Try again..." << endl;
        }
    }
}


int main(){
  
    int turn =1;

    cout<<"Enter player one name : ";
    cin>>p1;
    cout<<"Enter player two name : ";
    cin>>p2;
    while(turn !=10){
        input(turn);
    }

    cout<<"It's a draw ";   
    return 0;

}