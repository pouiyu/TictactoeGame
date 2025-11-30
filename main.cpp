#include <iostream>
#include <cstdlib>
using namespace std;

// 游戏棋盘，0=空 1=X 2=O
int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

// 当前玩家标记
char currentPawn = 'O';

// 清屏函数
void clearScreen() {
    system("cls"); // Windows系统
    // 如果是Linux/Mac系统，使用system("clear");
}

// 切换玩家
void switchPlayer() {
    if (currentPawn == 'O') {
        currentPawn = 'X';
    } else {
        currentPawn = 'O';
    }
}

// 显示棋盘
void displayBoard() {
    clearScreen();
    for (int i = 0; i < 3; i++) {
        cout << i << " [";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                cout << " ";
            } else if (board[i][j] == 1) {
                cout << "X";
            } else if (board[i][j] == 2) {
                cout << "O";
            }
        }
        cout << "]" << endl;
    }
    cout << "    012" << endl;
}

// 检查是否有玩家获胜
bool checkWin(int player) {
    // 检查行
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    
    // 检查列
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    
    // 检查对角线
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    
    return false;
}

// 检查是否平局
bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

// 获取玩家输入
void getPlayerInput() {
    int x, y;
    cout << "轮到玩家 " << currentPawn << endl;
    cout << "输入行号(0-2): ";
    cin >> x;
    cout << "输入列号(0-2): ";
    cin >> y;
    
    // 输入验证
    while (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != 0) {
        cout << "无效位置，请重新输入!" << endl;
        cout << "输入行号(0-2): ";
        cin >> x;
        cout << "输入列号(0-2): ";
        cin >> y;
    }
    
    // 根据当前玩家设置棋子
    if (currentPawn == 'X') {
        board[x][y] = 1;
    } else {
        board[x][y] = 2;
    }
}

// 主游戏循环
void gameLoop() {
    while (true) {
        displayBoard();
        getPlayerInput();
        
        // 检查X玩家是否获胜
        if (checkWin(1)) {
            displayBoard();
            cout << "玩家 X 获胜!" << endl;
            break;
        }
        
        // 检查O玩家是否获胜
        if (checkWin(2)) {
            displayBoard();
            cout << "玩家 O 获胜!" << endl;
            break;
        }
        
        // 检查是否平局
        if (isDraw()) {
            displayBoard();
            cout << "平局!" << endl;
            break;
        }
        
        // 切换玩家
        switchPlayer();
    }
}

// 主函数
int main() {
    clearScreen();
    gameLoop();
    return 0;
}
