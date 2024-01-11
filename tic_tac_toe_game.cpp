#include <iostream>
#include <string>

using namespace std;

void print_table(const string table[6][5]) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 5; j++) {
            cout << table[i][j];
        }
        cout << endl;
    }
}

char check_winner(const string table[6][5]) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((table[i * 2][0] == table[i * 2][2] && table[i * 2][2] == table[i * 2][4]) ||
            (table[0][i * 2] == table[2][i * 2] && table[2][i * 2] == table[4][i * 2])) {
            return table[i * 2][i * 2][1];
        }
    }
    if ((table[0][0] == table[2][2] && table[2][2] == table[4][4]) ||
        (table[0][4] == table[2][2] && table[2][2] == table[4][0])) {
        return table[2][2][1];
    }

    return 'D'; // No winner yet
}

void user_play(string table[6][5], char play, int pos) {
    if (pos >= 0 && pos < 9) {
        int row = pos / 3 * 2;
        int col = pos % 3 * 2;

        if (table[row][col] != " X " && table[row][col] != " O ") {
            table[row][col] = " " + string(1, play) + " ";
        } else {
            cout << "Position " << pos << " has already been played. Choose another position." << endl;
        }
    } else {
        cout << "Invalid position. Please choose a position between 0 and 8." << endl;
    }
}

int main() {
    string table[6][5] = {
        {" 0 ", "|", " 1 ", "|", " 2 "},
        {"___", "|", "___", "|", "___"},
        {" 3 ", "|", " 4 ", "|", " 5 "},
        {"___", "|", "___", "|", "___"},
        {" 6 ", "|", " 7 ", "|", " 8 "},
        {"   ", "|", "   ", "|", "   "}};

    char player_1, player_2;
    char current_player = 'X';

    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Let's begin! Will you be playing as 'X' or 'O'" << endl;
    char choice;
    cin >> choice;

    if (choice == 'X' || choice == 'x') {
        player_1 = 'X';
        player_2 = 'O';
        cout << "Player 1, you are X. Player 2 is O." << endl;
    } else {
        player_1 = 'O';
        player_2 = 'X';
        cout << "Player 1, you are O. Player 2 is X." << endl;
    }

    int pos;
    bool game_over = false;

    while (!game_over) {
        print_table(table);
        cout << "Current player: Player " << (current_player == 'X' ? "1 (X)" : "2 (O)") << endl;
        cout << "Choose a position to play: ";
        cin >> pos;

        if (current_player == 'X') {
            user_play(table, player_1, pos);
        } else {
            user_play(table, player_2, pos);
        }

        char winner = check_winner(table);
        if (winner != 'D') {
            print_table(table);
            cout << "Player " << (winner == 'X' ? "1 (X)" : "2 (O)") << " wins!" << endl;
            game_over = true;
        } else {
            bool all_positions_played = true;
            for (int i = 0; i < 9; ++i) {
                int row = i / 3 * 2;
                int col = i % 3 * 2; 
                if (table[row][col] != " X " && table[row][col] != " O ") {
                    all_positions_played = false;
                    break;
                }
            }

            if (all_positions_played) {
                print_table(table);
                cout << "It's a draw!" << endl;
                game_over = true;
            } else {
                current_player = (current_player == 'X') ? 'O' : 'X';
            }
        }
    }

    return 0;
}

