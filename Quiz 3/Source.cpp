#include <iostream>
#include <string>
using namespace std;

enum DIRECTIONS {
	UP, DOWN, NONE
};

void Recursion(int num, int value, int direction);
void Game();
void calendar(int month);

int main() {
	bool run = true;
	while (run) {
		cout << "Choose your option!" << endl << "1) Calendar" << endl << "2) Game" << endl << "3) Recursion" << endl << "4) quit!" << endl << endl;
		int answer = 0;
		cin >> answer;
		switch (answer) {
		case 1:
			cout << "Calendar!" << endl;
			cout << "> Enter A Month!" << endl;
			cin >> answer;
			calendar(answer);
			break;
		case 2:
			cout << "Game!" << endl;
			Game();
			break;
		case 3:
			cout << "Recursion!" << endl;
			cout << "> Enter A Number!" << endl;
			cin >> answer;
			Recursion(answer + 1, answer, DOWN);
			cout << endl << endl;
			break;
		case 4:
			run = false;
			break;
		default:
			cout << "Not an option!" << endl;
		}
	}
}

void calendar(int month) {
	string NAME[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30,31};
	month -= 1;
	if (month >= 0 && month <= 11)
		cout << NAME[month] << " has " << days[month] << " days!" << endl;
	else
		cout << "Error!" << endl;
}

void Game() {
	bool run2 = true;
	int room = 1;
	char answer = 'p';
	while (run2) {
		cout << "You are in room " << room << endl << "> Type q to quit!" << endl << endl;
		switch (room) {
		case 1:
			cout << "you can go N, E, W!" << endl;
			cin >> answer;
			if (answer == 'N' || answer == 'n') {
				room = 2;
			}
			if (answer == 'E' || answer == 'e') {
				room = 4;
			}
			if (answer == 'W' || answer == 'w') {
				room = 3;
			}
			if (answer == 'Q' || answer == 'q') {
				run2 = false;
			}
			break;
		case 2:
			cout << "you can go S!" << endl;
			cin >> answer;
			if (answer == 'S' || answer == 's') {
				room = 1;
			}
			if (answer == 'Q' || answer == 'q') {
				run2 = false;
			}
			break;
		case 3:
			cout << "you can go E!" << endl;
			cin >> answer;
			if (answer == 'E' || answer == 'e') {
				room = 1;
			}
			if (answer == 'Q' || answer == 'q') {
				run2 = false;
			}
			break;
		case 4:
			cout << "you can go S, W!" << endl;
			cin >> answer;
			if (answer == 'W' || answer == 'w') {
				room = 1;
			}
			if (answer == 'S' || answer == 's') {
				room = 5;
			}
			if (answer == 'Q' || answer == 'q') {
				run2 = false;
			}
			break;
		case 5:
			cout << "you can go N!" << endl;
			cin >> answer;
			if (answer == 'N' || answer == 'n') {
				room = 4;
			}
			if (answer == 'Q' || answer == 'q') {
				run2 = false;
			}
			break;
		}
	}
};
void Recursion(int num, int value, int direction) {
	if (direction == NONE)
		direction = UP;
	if (num == 1 && direction == DOWN)
		direction = NONE;
	if (direction == UP && value > num)
		num += 1;
	if (direction == DOWN)
		num -= 1;
	cout << num << " ";
	if (direction == UP && num == value)
		return;
	if(num <= value)
	Recursion(num, value, direction);
};