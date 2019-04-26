#include <iostream>
#include <string>

using namespace std;

void playerTurn(int turn, bool& LostGame){

    string answer;

    cin >> answer;

    for(int i = 0; i < answer.length();i++){answer[i] = toupper(answer[i]);}

    if(turn % 15 == 0 && answer != "FIZZBUZZ"){LostGame = true;}
    if(turn % 3 == 0 && turn % 15 != 0 && answer != "FIZZ"){LostGame = true;}
    if(turn % 5 == 0 && turn % 15 != 0 &&answer != "BUZZ"){LostGame = true;}
    if(turn % 3 != 0 && turn % 5 != 0 && answer != to_string(turn)){LostGame = true;}

}

void cpuTurn(int turn){

    if(turn % 15 == 0){cout << "FizzBuzz" << endl;}
    else if(turn % 3 == 0){cout << "Fizz" << endl;}
    else if(turn % 5 == 0){cout << "Buzz" << endl;}
    else{cout << turn << endl;}
}

int main(){
    bool Lost = false;
    int turn = 1;

    while(!Lost){

        playerTurn(turn, Lost);
        if(Lost){break;}
        turn++;

        cpuTurn(turn);
        turn++;
    }

    cout << "You have lost the game!" << endl;

    return 0;
}
