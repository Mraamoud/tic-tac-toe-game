#include <iostream>
#include <ctime>
using namespace std;

void drawboard (char *spaces);
void playerchoice (char *spaces , char player );
void computerchoice (char *spaces , char computer);
bool winner (char *spaces , char player , char computer );
bool tie (char *spaces);

int main(){
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool run = true;
    drawboard(spaces);
    while (run){
        playerchoice(spaces,player);

        if(winner(spaces,player,computer)){
            run = false;
            break;
        }
        else if (tie(spaces)){
            run = false;
            break;
        }
        computerchoice(spaces,computer);
        drawboard(spaces);
        if(winner(spaces,player,computer)){
            run = false;
            break;
        }
        else if (tie(spaces)){
            run = false;
            break;
        }

    }
    cout << "thank you for playing , we hope that you enjoyed";
    return 0;
}
void drawboard (char *spaces){
    cout << '\n';
    cout << "    |    |    \n";
    cout << "  " << spaces[0] << " |  " << spaces[1] << " |  " << spaces[2] << " \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << "  " << spaces[3] << " |  " << spaces[4] << " |  " << spaces[5] << " \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << "  " << spaces[6] << " |  " << spaces[7] << " |  " << spaces[8] << " \n";
    cout << "    |    |    \n";
    cout << '\n';
}
void playerchoice (char *spaces , char player ){
    int num;
    do {
        cout << "please choose a place to fill it from 1 to 9: ";
        cin >> num; cout << '\n';
        num --;
        if (spaces[num] == ' '){
            spaces[num] = player;
            break;
        }
    }while(num < 0 || num > 8);
}
void computerchoice (char *spaces , char computer){
    srand (time(0));
    int num;
    while(true){
        int num = rand() % 9;
        if (spaces[num] == ' '){
            spaces[num] = computer;
            break;
        }
    }
}
bool winner (char *spaces , char player , char computer ){
    if( spaces[0] != ' ' && spaces[0] == spaces[1] && spaces [1] == spaces[2]){
        spaces[0] == player ? cout << "you win \n" : cout << "you lose \n";
    }
    else if( spaces[3] != ' ' && spaces[3] == spaces[4] && spaces [4] == spaces[5]){
        spaces[3] == player ? cout << "you win \n" : cout << "you lose \n";
    }
    else if( spaces[6] != ' ' && spaces[6] == spaces[7] && spaces [7] == spaces[8]){
        spaces[6] == player ? cout << "you win \n" : cout << "you lose \n";
    }
    else if( spaces[0] != ' ' && spaces[0] == spaces[3] && spaces [3] == spaces[6]){
        spaces[0] == player ? cout << "you win \n" : cout << "you lose \n";
    }
    else if( spaces[1] != ' ' && spaces[1] == spaces[4] && spaces [4] == spaces[7]){
        spaces[1] == player ? cout << "you win \n" : cout << "you lose \n";
    }
    else if( spaces[2] != ' ' && spaces[2] == spaces[5] && spaces [5] == spaces[8]){
        spaces[2] == player ? cout << "you win \n" : cout << "you lose \n";
    }
    else if( spaces[0] != ' ' && spaces[0] == spaces[4] && spaces [4] == spaces[8]){
        spaces[0] == player ? cout << "you win \n" : cout << "you lose \n";
    }
    else if( spaces[2] != ' ' && spaces[2] == spaces[4] && spaces [4] == spaces[6]){
        spaces[2] == player ? cout << "you win \n" : cout << "you lose \n";
    }
    else{
        return false;
    }
    return true;
}
bool tie (char *spaces){
    for (int i = 0 ; i < 9 ; i++){
        if (spaces[i] == ' '){
            return false;
        }
    }
    cout << "It's a tie \n";

    return true;
}
