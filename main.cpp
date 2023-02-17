// Tic Tac Toe Game

#include <iostream>
using namespace std;

//  declare variables and functions
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int check_win();
void board();


/*********************************************
check_win function returns 3 outputs"
    1 - Game Won
	0 - Game Draw
   -1 - Game in Progress
**********************************************/

int check_win(){

	// horizontal cases
	if (square[1] == square[2] && square[2] == square[3]){
		return 1;
	} else if (square[4] == square[5] && square[5] == square[6]){
		return 1;
	} else if (square[7] == square[8] && square[8] == square[9]){
		return 1;
	}

	// vertical cases
	else if (square[1] == square[4] && square[4] == square[7]){
		return 1;
	} else if (square[2] == square[5] && square[5] == square[8]){
		return 1;
	} else if (square[3] == square[6] && square[6] == square[9]){
		return 1;
	}

	// diagonal cases
	else if (square[1] == square[5] && square[5] == square[9]){
		return 1;
	} else if (square[7] == square[5] && square[5] == square[3]){
		return 1;
	}

	// draw cases [all squares are filled]
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
            && square[4] != '4' && square[5] != '5' && square[6] != '6' 
            && square[7] != '7' && square[8] != '8' && square[9] != '9'){
		return 0;
	}
	
	// no win
	else{
		return -1;
	}
}


/*******************************************************************
   			   Build Tic Tac Toe Board with User Entry
********************************************************************/


void board()
{
	cout << "\n=================================" << endl;
    cout << "|\t-- Tic Tac Toe --\t|" << endl;
	cout << "=================================" << endl;
    cout << "   Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "\t     |     |     \n\n" << endl;
}


/*********************************************
   				 Main function
**********************************************/

int main() {

	int player = 1,i,choice;
	char mark;
	do {
		board();                      // prints the current state of the board
		player = (player % 2) ? 1:2;  // toggle between player1 and player2
		cout << "Player " << player << ", enter a number: ";
		cin >> choice; 		                // Ask for input block
		mark = (player == 1) ? 'X' : 'O';   // return mark based on condition 

		// fill the board with valid entry
		if (choice == 1 && square[1] == '1'){
			square[1] = mark;
		} else if (choice == 2 && square[2] == '2'){
			square[2] = mark;
		} else if (choice == 3 && square[3] == '3'){
			square[3] = mark;
		} else if (choice == 4 && square[4] == '4'){
			square[4] = mark;
		} else if (choice == 5 && square[5] == '5'){
			square[5] = mark;
		} else if (choice == 6 && square[6] == '6'){
			square[6] = mark;
		} else if (choice == 7 && square[7] == '7'){
			square[7] = mark;
		} else if (choice == 8 && square[8] == '8'){
			square[8] = mark;
		} else if (choice == 9 && square[9] == '9'){
			square[9] = mark;
		} else {
			cout << "Invalid Move" << endl;
			cout << "Please Give a New Input" << endl;
			player--;                       // player is not toggled
			cin.ignore();                   // earlier player input is ignored
			cin.get();
		}

		i = check_win();
		player++;

	} 
	
	// process result of the move
	while(i==-1);                                // no result, keep looping
	board();                                     // print final board
	if(i==1){                                    // game has a winner
		cout<<"==>\a Player "<<--player<<" wins ";
	} else{                                      // game is a draw
		cout<<"==>\a Game Draw";
	}
	cin.ignore();  // clear characters from input buffer
	cin.get();
	return 0;
} 
