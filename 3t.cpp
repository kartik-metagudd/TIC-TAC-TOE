#include<iostream>
#include<string>
#include<unistd.h>
#include<windows.h>
#include<cstring>


using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif



void move(char& player,char& shape);
string p1,p2;
char ttt[3][3]=

{{' ',' ',' '},
{' ',' ',' '},
{' ',' ',' '}};


void reset(){
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ttt[i][j]=' ';
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
    cout<<MAGENTA;
    if (checkWin('X')){
        cout << p1 << " wins..!" << endl;
        cout<<RESET;
    }  

    else if (checkWin('O')){
    cout << p2 << " wins..!" << endl;
    cout<<RESET;
    }
}

void display(){
    for(int i=0;i<3;i++){
        cout<<"\t  ";
        for(int j=0;j<3;j++){
            if (ttt[i][j]=='X'){
                if(j==2){
                    cout<<RED<<ttt[i][j]<<"     "<<RESET;
                }
                else 
                cout<<RED<<ttt[i][j]<<RESET<<CYAN<<"  |  "<<RESET;
            }
            else if(ttt[i][j]=='O'){
                if(j==2){
                    cout<<YELLOW<<ttt[i][j]<<RESET<<CYAN<<"    "<<RESET;
                }
                else 
                cout<<YELLOW<<ttt[i][j]<<RESET<<CYAN<<"  |  "<<RESET;

            }
            else if(j==2) 
            cout<<RESET<<ttt[i][j]<<CYAN<<"     "<<RESET;
            else 
            cout<<RESET<<ttt[i][j]<<CYAN<<"  |  "<<RESET;

        }
        if(i<2)
        cout<<endl<<CYAN<<"\t ----|-----|----"<<RESET<<endl;
        else 
        cout<<endl;
        
    }
    
}


void input(int& turn) {
    int a, b;
    bool validInput = false;

    while (!validInput) {
        cout<<MAGENTA;

        if (turn % 2 == 0) {
            cout << ">> "<<p2<< "'s turn, Enter coordinates with a space between them (row , column): ";
        } else {
            cout << ">> "<<p1<< "'s turn, Enter coordinates with a space between them (row , column) : ";
        }
        cout<<RESET;

        cin >> a >> b;

        // Validate the input coordinates
        if (a >= 0 && a <= 2 && b >= 0 && b <= 2 && ttt[a][b] == ' ') {
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
            cout<<MAGENTA;
            cout << " Invalid input! Try again..." << endl;
            cout<<RESET;
        }
        
    }
}


void engin(){

    string name;
    bool right=false;
    char mark;
    cin.sync();
    cout<<MAGENTA;
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
                cout<<MAGENTA;
                cout<<">> Enter co-ordinates with space between them (row , column) : ";
                cout<<RESET;
                cin>>a>>b;
                cout<<endl;
                if (a >= 0 && a <= 2 && b >= 0 && b <= 2 && ttt[a][b] == ' '){
                    ttt[a][b]=player;
                    right=true;
                    display();
                    winner();
                    turn++;
                    loop++;
                }else {
                cout<<MAGENTA;
                cout<<" Invalid input :( "<<endl<<endl;
                cout<<RESET;
                }
            }
        }
        else {
            cout<<GREEN;
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

        else if(loop>=9){
        cout<<MAGENTA;
        cout<<" Its a draw "<<endl;
        cout<<RESET;
        }

    }
}


void move(char& player,char& shape){
    bool val,val2,MoveMade=false;
    for(int i=0;i<3&&!MoveMade;i++){
        for(int j=0;j<3&&!MoveMade;j++){
            if(ttt[i][j]==' '){
                ttt[i][j]=player;
                val=checkWin(player);
                ttt[i][j]=' ';
                ttt[i][j]=shape;
                val2=checkWin(shape);
                ttt[i][j]=' ';
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
                    if(ttt[i][j]==' '){
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
    cout<<GREEN;
    cout<<"______TIC-TAC-TOE______"<<endl<<endl;
    cout<<"1] ENGIN(Computer) "<<endl;
    cout<<"2] TWO PLAYER "<<endl<<endl;
    cout<<RESET;
    while(!right){
        cout<<BLUE;
        cout<<">> Enter your choice(integer 1 , 2 ) : ";
        cout<<RESET;
        cin>>choice;
        if(choice =='1'){
            right = true;
            engin();
        }
        else if (choice =='2'){
            right=true;
            cin.sync();
            cout<<MAGENTA;
            cout<<">> Enter player one name : ";
            getline(cin,p1);
            cout<<">> Enter player two name : ";
            getline(cin,p2);
            cout<<RESET;
            while(turn<10){
                input(turn);
                if(checkWin('X')||checkWin('O'))
                break;
            }
        }
        else{
            cout<<MAGENTA;
            cout<<" Invalid input :( "<<endl;
            cout<<RESET;
        } 
    }
    if(turn >9){
        cout<<MAGENTA;
        cout<<" It's a draw !!"<<endl; 
        cout<<RESET;
    }    
    
}


int main(){
    char again;
    while(1){
        start();
        reset();
        cout<<MAGENTA;
        cout <<">> Enter 0 to 'Quit' or Enter any key(alphabet) to 'PlayAgain' : ";
        cout<<RESET;
        cin>>again;
        if(again=='0')
        exit(0);
        }
  
    return 0;

}
