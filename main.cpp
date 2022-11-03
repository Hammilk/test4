#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void play();
void playValidation(char);
void random();
void game(int, int);
int opponent();
int player();
void playerValidation(int);

int main() {
    random();
    play();
    return 0;
}

//Sets seed for rand function in the function "opponent()".
void random(){
    unsigned seed = time(0);
    srand(seed);
}

//Initiates and loops game
void play(){
    char again;
    do{
        game(opponent(), player());
        cout << "Play again? (Y/N)" << endl;
        cin >> again;
        playValidation(again);
    }
    while (again == 'Y' || again == 'y');
    cout << "Thanks for playing!" << endl;
}

//Validate results for function "play()".
void playValidation(char again){
    while (again != 'Y' && again != 'N' && again != 'y' && again != 'n'){
        cout << "Invalid Entry, please enter Y or N" << endl;
        cout << "Play again? (Y/N)" << endl;
        cin >> again;
    }
}

//Algorithm for determining who wins or loses.
void game(int opponent, int player){
    int result = player - opponent;
    if (result == 2 || result == -2){
        result = result * -1;
    }
    if(result == 0){ //Tie
        cout << "You tie." << endl;
    }
    else if(result > 0){ //Win
        cout << "You win!" << endl;
    }
    else{ //Lose
        cout << "You lose." << endl;
    }
}

//Takes player input for rock, paper, scissors and displays choice.
int player(){
    int choice;
    cout << "Choose from the following:" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissor" << endl;
    cin >> choice;
    playerValidation(choice);

    switch(choice){
        case 1:
            cout << "You chose Rock." << endl;
            break;
        case 2:
            cout << "You chose Paper." << endl;
            break;
        case 3:
            cout << "You chose Scissor." << endl;
            break;
        default:
            cout << "Error" << endl;
    }
    return choice;
}

//Validates results for function "player()".
void playerValidation(int choice){
    while(choice < 1 || choice > 3){
        cout << "Invalid entry, please choose from the following:" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissor" << endl;
        cin >> choice;
    }
}

//Randomly generates opponent choice for rock, paper, scissors and displays choice.
int opponent(){
    int choice;
    choice = rand() % 3 + 1;
    switch(choice){
        case 1:
            cout << "The computer chose Rock." << endl;
            break;
        case 2:
            cout << "The computer chose Paper." << endl;
            break;
        case 3:
            cout << "The computer chose Scissor." << endl;
            break;
        default:
            cout << "Error" << endl;
    }
    return choice;
}

