/*
MP3 Tic Tac D'Oh - Elizabeth Huang Burkholder - 16 November 2023
Program will allow two players to play games of tic tac toe, counting wins, losses, and ties.
After each game the program will ask if the game should reset, allowing for players to continue (while still keeping track of previous wins/ties)
*/

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 9;

//function prototypes
void displayBoard(char board[]);
void placeMarkOnBoard(char board[], char playerMark, int location);
void clearBoard(char board[]);
void displayGameStats(int ties, int playerOneScore, int playerTwoScore, string PLayerOne, string PlayerTwo);
int getPlayerInput(string playerName);
bool hasThreeInRow(char board[], char playerMark);
bool isMoveLegal(char board[], int location);
bool tiedGame(char board[], bool legalMove);
bool endGames(char board[]);

//MAIN FUNCTION
int main() {
	int location, player1Score = 0, player2Score = 0, ties=0;
	string playerOne, playerTwo;
	char playerOneMark = 'X', playerTwoMark = 'O';
	bool gameEnd = false, legality = false, continueTheGame = true, playerOneTurn = true, gameTie, endingGames;

	//Getting player's names
	cout << "Please enter player 1's name: ";
	getline(cin, playerOne);
	cout << "Please enter player 2's name: ";
	getline(cin, playerTwo);

	//Declaring game board array
	char gameBoard[SIZE] = { '7', '8', '9', '4', '5', '6', '1', '2', '3' };
	
	//CONTINUE GAMES CYCLE
	do {

		//MAIN GAME CYCLE WHEN PLAYER 1 STARTS
		if (playerOneTurn == true) {
			do {
				//Player One's Turn
				while (legality == false) {
					displayBoard(gameBoard);
					location = getPlayerInput(playerOne);
					legality = isMoveLegal(gameBoard, location);
				}
				placeMarkOnBoard(gameBoard, playerOneMark, location);
				gameEnd = hasThreeInRow(gameBoard, playerOneMark);
				if (gameEnd == true) {
					player1Score++;
					displayBoard(gameBoard);
					cout << playerOne << " wins!" << endl;
					displayGameStats(ties, player1Score, player2Score, playerOne, playerTwo);
					break;
				}
				legality = false;

				//Detecting for Tie
				gameTie = tiedGame(gameBoard, legality);
				if (gameTie == true) {
					ties++;
					displayBoard(gameBoard);
					cout << "It's a tie!" << endl;
					displayGameStats(ties, player1Score, player2Score, playerOne, playerTwo);
					break;
				}

				//Player Two's Turn
				while (legality == false) {
					displayBoard(gameBoard);
					location = getPlayerInput(playerTwo);
					legality = isMoveLegal(gameBoard, location);
				}
				placeMarkOnBoard(gameBoard, playerTwoMark, location);
				gameEnd = hasThreeInRow(gameBoard, playerTwoMark);
				if (gameEnd == true) {
					player2Score++;
					displayBoard(gameBoard);
					cout << playerTwo << " wins!" << endl;
					displayGameStats(ties, player1Score, player2Score, playerOne, playerTwo);
					break;
				}
				legality = false;

				//Detecting for Tie
				gameTie = tiedGame(gameBoard, legality);
				if (gameTie == true) {
					ties++;
					displayBoard(gameBoard);
					cout << "It's a tie!" << endl;
					displayGameStats(ties, player1Score, player2Score, playerOne, playerTwo);
					break;
				}

			} while (gameEnd == false);
		}

		//MAIN GAME CYCLE WHEN PLAYER 2 STARTS
		if (playerOneTurn == false) {
			do {

				//Player Two's Turn
				while (legality == false) {
					displayBoard(gameBoard);
					location = getPlayerInput(playerTwo);
					legality = isMoveLegal(gameBoard, location);
				}
				placeMarkOnBoard(gameBoard, playerTwoMark, location);
				gameEnd = hasThreeInRow(gameBoard, playerTwoMark);
				if (gameEnd == true) {
					player2Score++;
					displayBoard(gameBoard);
					cout << playerTwo << " wins!" << endl;
					displayGameStats(ties, player1Score, player2Score, playerOne, playerTwo);
					break;
				}
				legality = false;

				//Detecting for Tie
				gameTie = tiedGame(gameBoard, legality);
				if (gameTie == true) {
					ties++;
					displayBoard(gameBoard);
					cout << "It's a tie!" << endl;
					displayGameStats(ties, player1Score, player2Score, playerOne, playerTwo);
					break;
				}

				//Player One's Turn
				while (legality == false) {
					displayBoard(gameBoard);
					location = getPlayerInput(playerOne);
					legality = isMoveLegal(gameBoard, location);
				}
				placeMarkOnBoard(gameBoard, playerOneMark, location);
				gameEnd = hasThreeInRow(gameBoard, playerOneMark);
				if (gameEnd == true) {
					player1Score++;
					displayBoard(gameBoard);
					cout << playerOne << " wins!" << endl;
					displayGameStats(ties, player1Score, player2Score, playerOne, playerTwo);
					break;
				}
				legality = false;

				//Detecting for Tie
				gameTie = tiedGame(gameBoard, legality);
				if (gameTie == true) {
					ties++;
					displayBoard(gameBoard);
					cout << "It's a tie!" << endl;
					displayGameStats(ties, player1Score, player2Score, playerOne, playerTwo);
					break;
				}

			} while (gameEnd == false);
		}

		//End Game Choice
		endingGames = endGames(gameBoard);
		if (endingGames == true) {
			clearBoard(gameBoard);
			if (playerOneTurn == true)
				playerOneTurn = false;
			else if (playerOneTurn == false)
				playerOneTurn = true;
			legality = false;
		}
		else {
			continueTheGame = false;
		}

	} while (continueTheGame);

	return 0;
}

//function definitions
/*
displayBoard - Prints out the updated board.
@params - Must be the board array
*/
void displayBoard(char board[]){
	cout << endl;
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "---+---+----" << endl;
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "---+---+----" << endl;
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

/*
placeMarkOnBoard - Prints out the character mark on desired spot
@params - Must be a valid spot on the board.
*/
void placeMarkOnBoard(char board[], char playerMark, int location) {
	if (location == 1)
		board[6] = playerMark;
	else if (location == 2)
		board[7] = playerMark;
	else if (location == 3)
		board[8] = playerMark;
	else if (location == 4)
		board[3] = playerMark;
	else if (location == 5)
		board[4] = playerMark;
	else if (location == 6)
		board[5] = playerMark;
	else if (location == 7)
		board[0] = playerMark;
	else if (location == 8)
		board[1] = playerMark;
	else if (location == 9)
		board[2] = playerMark;

}

/*
clearBoard - Updates the board to be reset to original (number set)
@params - Must be the board array
*/
void clearBoard(char board[]) {
	board[0] = '7';
	board[1] = '8';
	board[2] = '9';
	board[3] = '4';
	board[4] = '5';
	board[5] = '6';
	board[6] = '1';
	board[7] = '2';
	board[8] = '3';
}

/*
displayGameStats - Prints out number of games won per player and ties
@params - Input integers for scores and the character names via string.
*/
void displayGameStats(int ties, int playerOneScore, int playerTwoScore, string playerOne, string playerTwo) {
	cout << "Ties: " << ties << "		" << playerOne << " Wins: " << playerOneScore << "		" << playerTwo << " Wins: " << playerTwoScore << endl;
}

/*
getPlayerInput - Asks the player for desired movement location
@params - Entered number must be an integer between 1 and 9 inclusive
@returns a value 1-9 inclusive
*/
int getPlayerInput(string playerName) {
	int num;
	do {
		cout << playerName << ", please input a number 1-9 where you would like to place your mark: ";
		cin >> num;
		if (num <= 0 || num >= 10)
			cout << "Not in range..."<<endl;
	} while (num <= 0 || num>=10);
	if (num > 0 && num < 10)
		return num;
}

/*
hasThreeInRow - checks if there are three marks in a row
@params - playerMarks must be inputted, along with the board being judged.
@returns true or false
*/
bool hasThreeInRow(char board[], char playerMark) {
	if (board[0] == playerMark && board[1] == playerMark && board[2] == playerMark)
		return true;
	else if (board[0] == playerMark && board[3] == playerMark && board[6] == playerMark)
		return true;
	else if (board[0] == playerMark && board[4] == playerMark && board[8] == playerMark)
		return true;
	else if (board[6] == playerMark && board[7] == playerMark && board[8] == playerMark)
		return true;
	else if (board[1] == playerMark && board[4] == playerMark && board[7] == playerMark)
		return true;
	else if (board[2] == playerMark && board[5] == playerMark && board[8] == playerMark)
		return true;
	else if (board[2] == playerMark && board[4] == playerMark && board[6] == playerMark)
		return true;
	else if (board[3] == playerMark && board[4] == playerMark && board[5] == playerMark)
		return true;
	else
		return false;
}

/*
isMoveLegal - checks whether the entered location is a legal move or not (is the space already occupied) and returns true/false respectively
@params - enter the location of the position to check and the game board
@returns true or false
*/
bool isMoveLegal(char board[], int location) {
	if (1 == (board[6] - '0') && location == 1)
		return true;
	else if (2 == (board[7] - '0') && location == 2)
		return true;
	else if (3 == (board[8] - '0') && location == 3)
		return true;
	else if (4 == (board[3] - '0') && location == 4)
		return true;
	else if (5 == (board[4] - '0') && location == 5)
		return true;
	else if (6 == (board[5] - '0') && location == 6)
		return true;
	else if (7 == (board[0] - '0') && location == 7)
		return true;
	else if (8 == (board[1] - '0') && location == 8)
		return true;
	else if (9 == (board[2] - '0') && location == 9)
		return true;
	else
		return false;
}

/*
Determines if game was tied.
@param Must enter the game board
@returns true/false depending on verdict
*/
bool tiedGame(char board[], bool legalMove) {
	if (board[6] != '1' && board[7] != '2' && board[8] != '3' && board[3] != '4' && board[4] != '5' && board[5] != '6' && board[0] != '7' && board[1] != '8' && board[2] != '9')
		return true;
	else
		return false;
}

/*
Asks to hit Y to reset the game and continue or N to Quit
@params Must include board into function call
@returns true or false
*/
bool endGames(char board[]) {
	char answer;
	cout << "Would you like to continue the games? Y or N ";
	cin >> answer;
	if (answer == 'Y')
		return true;
	else if (answer == 'N')
		return false;
}