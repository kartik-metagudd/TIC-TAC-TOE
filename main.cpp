#include<iostream>
#include<string>
#include<unistd.h>
using namespace std;
void move(char& player,char& shape);
string p1,p2;
char ttt[3][3]=

{{'_','_','_'},
{'_','_','_'},
{'_','_','_'}};


void reset(){
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ttt[i][j]='_';
        }
    }
}


bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if ((ttt[i][0] == player && ttt[i][1] == player && ttt[i][2] == player) || 
            (ttt[0][i] == player && ttt[1][i] == player && ttt[2][i] == player)) {
            return true;
        }
    }
    if ((ttt[0][0] == player && ttt[1][1] == player && ttt[2][2] == player) || 
        (ttt[0][2] == player && ttt[1][1] == player && ttt[2][0] == player)) {
        return true;
    }

    return false;
}


void winner() {
    if (checkWin('X'))
    cout << p1 << " wins..!" << endl;

    else if (checkWin('O'))
    cout << p2 << " wins..!" << endl;
    }


void display(){
    for(int i=0;i<3;i++){
        cout<<" |";
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
            cout << ">> "<<p2<< "'s turn, Enter coordinates with a space between them (row , column): ";
        } else {
            cout << ">> "<<p1<< "'s turn, Enter coordinates with a space between them (row , column) : ";
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
            cout << " Invalid input! Try again..." << endl;
        }
        
    }
}


void engin(){
    string name;
    bool right=false;
    char mark;
    cin.sync();
    cout<<">> Your Name : ";
    getline(cin,name);
    char player ,shape;
    int turn,a,b,loop=0;
    while(!right){
    cout<<">> Choose shape 1 for 'X' and 0 for 'O' : ";
    cin>>mark;
    if(mark=='1'){
        player='X';
        shape='O';
        turn=1;
        p1=name;
        p2="Computer";
        right=true;

    }else if(mark=='0'){
        player='O';
        shape='X';
        p1="Computer";
        p2=name;
        turn =0;
        right=true;
    }else{
        cout<<" Invalid input ??? "<<endl;
    }
    }
    while(loop<9){

        if(turn%2!=0){
            right=false;
            while(!right){
                cout<<">> Enter co-ordinates with space between them (row , column) : ";
                cin>>a>>b;
                cout<<endl;
                if (a >= 0 && a <= 2 && b >= 0 && b <= 2 && ttt[a][b] == '_'){
                    ttt[a][b]=player;
                    right=true;
                    display();
                    winner();
                    turn++;
                    loop++;
                }else 
                cout<<" Invalid input :( "<<endl<<endl;
                }
            }
        else {
            cout<<" (@ _ @)";
            sleep(1);
            cout<<".";
            sleep(1);
            cout<<".";
            sleep(1);
            cout<<"."<<endl<<endl;
            move(player,shape);
            display();
            winner();
            turn++;
            loop++;
        }
        if(checkWin('X')||checkWin('O'))
        break;
        else if(loop>=9)
        cout<<" Its a draw "<<endl;
        }
}


void move(char& player,char& shape){
    bool val,val2,MoveMade=false;
    for(int i=0;i<3&&!MoveMade;i++){
        for(int j=0;j<3&&!MoveMade;j++){
            if(ttt[i][j]=='_'){
                ttt[i][j]=player;
                val=checkWin(player);
                ttt[i][j]='_';
                ttt[i][j]=shape;
                val2=checkWin(shape);
                ttt[i][j]='_';
                if(val||val2){
                    ttt[i][j]=shape;
                    MoveMade=true;
                }
                }
            }
        }
        if(!MoveMade){
            for(int i=0;i<3&&!MoveMade;i++){
                for(int j=0;j<3&&!MoveMade;j++){
                    if(ttt[i][j]=='_'){
                        ttt[i][j]=shape;
                        MoveMade=true;

                }
            }
        }
        }

    
 
}





void start(){
    system("cls");
    cout<<endl;
    bool right=false;
    int turn =1;
    char choice;
    cout<<"______TIC-TAC-TOE______"<<endl<<endl;
    cout<<"1] ENGIN(Computer) "<<endl;
    cout<<"2] TWO PLAYER "<<endl;
    while(!right){
        cout<<">> Enter your choice(integer 1 , 2 or 3) : ";
        cin>>choice;
        if(choice =='1'){
            right = true;
            engin();
        }
        else if (choice =='2'){
            right=true;
            cin.sync();
            cout<<">> Enter player one name : ";
            getline(cin,p1);
            cout<<">> Enter player two name : ";
            getline(cin,p2);
            while(turn<10){
                input(turn);
                if(checkWin('X')||checkWin('O'))
                break;
            }
        }
        else{
        cout<<" Invalid input :( "<<endl;
        } 
    }
    if(turn >9)
    cout<<" It's a draw !!"<<endl; 
    
}


int main(){
    char again;
    while(1){
        start();
        reset();
        cout <<">> Enter 0 to 'Quit' or Enter any key(alphabet) to 'PlayAgain' : ";
        cin>>again;
        if(again=='0')
        exit(0);
        }
  
    return 0;

}
