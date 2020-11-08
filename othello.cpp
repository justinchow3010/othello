// SID 1155125328 email 1155125328@link.cuhk.edu.hk name chow him chak
//

#include <iostream>
#include <iomanip>  

using namespace std;
const int N = 6;
void Init(char board[N][N], char Letter[N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = '.';
            if (i == N / 2 - 1 || i == N / 2) {
                if (j == N / 2- 1 || j == N / 2) {
                    if (j == i) {
                        board[i][j] = 'X';
                    }
                    else {
                        board[i][j] = 'O';
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        Letter[i] = 65 + i;
    } 
}

void InitArray(int TilesToFlipx[N], int TilesToFlipy[N]) {
    for (int x = 0; x < N; x++) {
        TilesToFlipx[x] = 99999999;
        TilesToFlipy[x] = 99999999;
    }
}

void PrintBoard(char board[N][N], char Letter[N]) {
    for (int k = 0; k < N; k++) {
        if (k == 0) {
            cout << "   ";
        }
        cout << Letter[k] << " ";
        if (k == N - 1) {
            cout << endl;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << setw(2) << i+1 << " ";
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool CheckValid(char board[N][N], int column, int row_num, int count, int TilesToFlipx[N], int TilesToFlipy[N]) {
    //int column = (int)column_char - 65;
    int row = row_num - 1;
    char OtherTile = 's';
    char Tile = 's';
    int number = 0;
    //int* ptr = NULL;
    if (count == 0) {
        OtherTile = 'O';
        Tile = 'X';
    }
    else {
        OtherTile = 'X';
        Tile = 'O';
    }
    if (board[row][column] != '.' || column > N - 1 || row < 0) {
        return false;
    }
    else {
        for (int i = row-1; i <= row+1; i++) {
            for (int j = column-1; j <= column +1; j++) {
                if (i > N - 1 || i < 0 || j > N - 1 || j < 0) {
                    continue;
                }
                else if (board[i][j] == OtherTile) {
                    //cout << "hi1" << endl;
                    if (column == j && row > i) {//same col up
                        int x = i;
                        int y = j;
                        //cout << "same col up" << endl;
                        //cout << board[x][y] << endl;
                        while (board[x][y] == OtherTile) {
                            x--;
                            //cout << "hi2" << endl;
                            if (x < 0 || board[x][y] != OtherTile)
                                break;
                        }
                        if (board[x][y] == Tile && x>=0) {
                            while (true) {
                                x++;
                                //cout << "hi3" << endl;
                                if (x == row)
                                    break;
                                TilesToFlipx[number] = x;
                                TilesToFlipy[number] = y;
                                number++;
                            }
                        }
                    }
                    else if (column == j && row < i) {//same col down
                        int x = i;
                        int y = j;
                        //cout << "same col down" << endl;
                        //cout << board[x][y] << endl;
                        while (board[x][y] == OtherTile) {
                            x++;
                            //cout << "hi2" << endl;
                            if (x > N -1 || board[x][y] != OtherTile)
                                break;
                        }
                        if (board[x][y] == Tile && x<=N-1) {
                            while (true) {
                                x--;
                                //cout << "hi3" << endl;
                                if (x == row)
                                    break;
                                TilesToFlipx[number] = x;
                                TilesToFlipy[number] = y;
                                //cout << TilesToFlipx[number] << endl;
                                //cout << TilesToFlipy[number] << endl;
                                number++;
                            }
                        }
                    }
                    else if (column > j && row == i) {//same row left
                        int x = i;
                        int y = j;
                        //cout << "same row left" << endl;
                        //cout << board[x][y] << endl;
                        while (board[x][y] == OtherTile) {
                            y--;
                            //cout << "hi2" << endl;
                            if (y < 0 || board[x][y] != OtherTile)
                                break;
                        }
                        if (board[x][y] == Tile && y >= 0) {
                            while (true) {
                                y++;
                                //cout << "hi3" << endl;
                                if (y == column)
                                    break;
                                TilesToFlipx[number] = x;
                                TilesToFlipy[number] = y;
                                //cout << TilesToFlipx[number] << endl;
                                //cout << TilesToFlipy[number] << endl;
                                number++;
                            }
                        }
                    }
                    else if (column < j && row == i) {//same row right
                        int x = i;
                        int y = j;
                        //cout << "same row right" << endl;
                        //cout << board[x][y] << endl;
                        while (board[x][y] == OtherTile) {
                            y++;
                            //cout << "hi2" << endl;
                            if (y > N-1 || board[x][y] != OtherTile)
                                break;
                        }
                        if (board[x][y] == Tile && y <= N-1) {
                            while (true) {
                                y--;
                                //cout << "hi3" << endl;
                                if (y == column)
                                    break;
                                TilesToFlipx[number] = x;
                                TilesToFlipy[number] = y;
                                //cout << TilesToFlipx[number] << endl;
                                //cout << TilesToFlipy[number] << endl;
                                number++;
                            }
                        }
                    }
                    else if (column > j && row < i) {//left down corner
                        int x = i;
                        int y = j;
                        //cout << "left down corner" << endl;
                        //cout << board[x][y] << endl;
                        while (board[x][y] == OtherTile) {
                            y--;
                            x++;
                            //cout << "hi2" << endl;
                            if (y < 0 || board[x][y] != OtherTile)
                                break;
                        }
                        if (board[x][y] == Tile && y >= 0) {
                            while (true) {
                                y++;
                                x--;
                                //cout << "hi3" << endl;
                                if (y == column)
                                    break;
                                TilesToFlipx[number] = x;
                                TilesToFlipy[number] = y;
                                //cout << TilesToFlipx[number] << endl;
                                //cout << TilesToFlipy[number] << endl;
                                number++;
                            }
                        }
                    }
                    else if (column > j && row > i) {//left top corner
                        int x = i;
                        int y = j;
                        //cout << "left top corner" << endl;
                        //cout << board[x][y] << endl;
                        while (board[x][y] == OtherTile) {
                            y--;
                            x--;
                            //cout << "hi2" << endl;
                            if (y < 0 || board[x][y] != OtherTile)
                                break;
                        }
                        if (board[x][y] == Tile && y >= 0) {
                            while (true) {
                                y++;
                                x++;
                                //cout << "hi3" << endl;
                                if (y == column)
                                    break;
                                TilesToFlipx[number] = x;
                                TilesToFlipy[number] = y;
                                //cout << TilesToFlipx[number] << endl;
                                //cout << TilesToFlipy[number] << endl;
                                number++;
                            }
                        }
                    }
                    else if (column < j && row > i) {//right top corner
                        int x = i;
                        int y = j;
                        //cout << "right top corner" << endl;
                        //cout << board[x][y] << endl;
                        while (board[x][y] == OtherTile) {
                            y++;
                            x--;
                            //cout << "hi2" << endl;
                            if (y > N -1 || board[x][y] != OtherTile)
                                break;
                        }
                        if (board[x][y] == Tile && x >= 0) {
                            while (true) {
                                y--;
                                x++;
                                //cout << "hi3" << endl;
                                if (y == column)
                                    break;
                                TilesToFlipx[number] = x;
                                TilesToFlipy[number] = y;
                                //cout << TilesToFlipx[number] << endl;
                                //cout << TilesToFlipy[number] << endl;
                                number++;
                            }
                        }
                    }
                    else if (column < j && row < i) {//right down corner
                        int x = i;
                        int y = j;
                        //cout << "right down corner" << endl;
                        //cout << board[x][y] << endl;
                        while (board[x][y] == OtherTile) {
                            y++;
                            x++;
                            //cout << "hi2" << endl;
                            if (y > N -1 || board[x][y] != OtherTile)
                                break;
                        }
                        if (y <= N - 1 && board[x][y] == Tile) {
                            while (true) {
                                y--;
                                x--;
                                //cout << "hi3" << endl;
                                if (y == column)
                                    break;
                                TilesToFlipx[number] = x;
                                TilesToFlipy[number] = y;
                                //cout << TilesToFlipx[number] << endl;
                                //cout << TilesToFlipy[number] << endl;
                                number++;
                            }
                        }
                    }
                }
            }
        }
        if (TilesToFlipx[0] != 99999999) {
            //for (int s : TilesToFlipy)
            //    cout << s << endl;
            return true;
        }
        else
            return false;
    }
}

void Flip(char board[N][N], char column_char, int row_num, int count, int TilesToFlipx[N], int TilesToFlipy[N]) {
    char OtherTile = 's';
    char Tile = 's';
    int column = (int)column_char - 65;
    int row = row_num - 1;
    if (count == 0) {
        OtherTile = 'O';
        Tile = 'X';
    }
    else {
        OtherTile = 'X';
        Tile = 'O';
    } 
    board[row][column] = Tile;
    //CheckValid(board, column_char, row_num, count, TilesToFlipx, TilesToFlipy);
    for (int i = 0; i < N; i++) {
        if (TilesToFlipx[i] == 99999999)
            break;
        else {
            //cout << "Tx" << TilesToFlipx[i] << endl;
            //cout << "Ty" << TilesToFlipy[i] << endl;
            board[TilesToFlipx[i]][TilesToFlipy[i]] = Tile;
        }
    }
}

bool CheckWholeBoard(char board[N][N], int count) {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            int* CheckX = new int[N]();
            int* CheckY = new int[N]();
            InitArray(CheckX, CheckY);
            if (CheckValid(board, j, i, count, CheckX, CheckY)) {
                //cout << "suc" << endl;
                return true;
                break;
            }   
        }
    }
    return false;
}

int CheckEndGame(char board[N][N]) {
    int NumberofX = 0;
    int NumberofY = 0;
    int win = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'X')
                NumberofX++;
            if (board[i][j] == 'O')
                NumberofY++;
        }
    }
    if (NumberofX > NumberofY) {
        win = 1;
    }
    else if (NumberofX == NumberofY) {
        win = 2;
    }

    return win;
}

bool CheckFull(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '.')
                return false;
        }
    }
    return true;
}
int main()
{
    char board[N][N] = { };
    char Letter[N] = { };
    int pits = 3;
    char column_char;
    int row_num;
    bool flag = true;
    int i = 1;
    bool counter = true;
    int Round = 1;
    int turn = 0;
    int end = 0;
    Init(board, Letter);
    while (flag) {
        cout << "Enter number of pits: ";
        cin >> pits;
        if (pits > N * N / 2) {
            flag = true;
            cout << "Too many pits!" << endl;
        }
        else
            flag = false;
    }

    while (i <= pits) {
        cout << "Enter position for pits " << i << ":";
        cin >> column_char >> row_num;
        column_char = toupper(column_char);
        if ((int)column_char - 65 <= N - 1 && row_num > 0 && row_num <=N && board[row_num - 1][(int)column_char - 65] == '.') {
            board[row_num - 1][(int)column_char - 65] = '#';
            i++;
        }
        else {
            cout << "Invalid position!" << endl;
        }
    }

    while (counter) {
        cout << "Round " << Round << ":" << endl;
        PrintBoard(board, Letter);
        bool con = 1;
        if (turn == 0) {
            while (con) {
                if (CheckWholeBoard(board, turn)) {
                    cout << "Player X's turn: ";
                    cin >> column_char >> row_num;  
                    int* TilesToFlipx = new int[N]();
                    int* TilesToFlipy = new int[N]();
                    InitArray(TilesToFlipx, TilesToFlipy);
                    column_char = toupper(column_char);
                    int column = (int)column_char - 65;
                    if (CheckValid(board, column, row_num, turn, TilesToFlipx, TilesToFlipy)) {
                        Flip(board, column_char, row_num, turn, TilesToFlipx, TilesToFlipy);
                        turn++;
                        Round++;
                        con = 0;
                        end = 0;
                    }
                    else {
                        cout << "Invalid move!" << endl;
                    }
                }
                else {
                    cout << "Player X has no valid moves! Pass!" << endl;
                    con = 0;
                    turn++;
                    end++;
                    Round++;
                }
            }
        }
        else {
            while (con) {
                if (CheckWholeBoard(board, turn)) {
                    cout << "Player O's turn: ";
                    cin >> column_char >> row_num;
                    int* TilesToFlipx = new int[N]();
                    int* TilesToFlipy = new int[N]();
                    InitArray(TilesToFlipx, TilesToFlipy);
                    column_char = toupper(column_char);
                    int column = (int)column_char - 65;
                    if (CheckValid(board, column, row_num, turn, TilesToFlipx, TilesToFlipy)) {
                        Flip(board, column_char, row_num, turn, TilesToFlipx, TilesToFlipy);
                        turn++;
                        Round++;
                        con = 0;
                        end = 0;
                    }
                    else {
                        cout << "Invalid move!" << endl;
                    }
                }
                else {
                    cout << "Player O has no valid moves! Pass!" << endl;
                    con = 0;
                    turn++;
                    end++;
                    Round++;
                }
            }
        }
        turn %= 2;
        if (end == 2 || CheckFull(board)) {
            int win = CheckEndGame(board);
            cout << "Game Over:" << endl;
            PrintBoard(board, Letter);
            if (win == 0) {
                cout << "Player O wins!" << endl;
            }
            else if (win == 1) {
                cout << "Player X wins!" << endl;
            }
            else
                cout << "Draw game!" << endl;
                
            return 0;
        }    
    }
    return 0;
}