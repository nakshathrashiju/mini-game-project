#include <iostream>
using namespace std;

int main() {
    const int size = 5;
    int x = 2, y = 2;   // snake position
    int fx = 4, fy = 4; // fruit position
    int score = 0;

    char move;

    while (true) {

        // draw board
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {

                if (i == x && j == y)
                    cout << "O ";
                else if (i == fx && j == fy)
                    cout << "* ";
                else
                    cout << ". ";
            }
            cout << endl;
        }

        cout << "Score: " << score << endl;
        cout << "Move (W/A/S/D, X to exit): ";
        cin >> move;

        // update position
        if (move == 'w') x--;
        else if (move == 's') x++;
        else if (move == 'a') y--;
        else if (move == 'd') y++;
        else if (move == 'x') break;

        // wall check
        if (x < 0 || x >= size || y < 0 || y >= size) {
            cout << "Game Over! You hit the wall.\n";
            break;
        }

        // fruit check
        if (x == fx && y == fy) {
            score += 10;
            fx = (fx + 1) % size;
            fy = (fy + 2) % size;
        }

        system("cls"); // remove this if it causes issues
    }

    cout << "Final Score: " << score << endl;

    return 0;
}