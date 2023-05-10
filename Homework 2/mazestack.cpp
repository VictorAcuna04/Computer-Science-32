#include <iostream>
#include <stack>
using namespace std;

class Coord {
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec) {
    stack<Coord> coordStack;
    Coord start(sr, sc);
    coordStack.push(start);
    maze[sr][sc] = 'X'; // Mark the starting coordinate as visited
    while (!coordStack.empty()) {
        Coord current = coordStack.top();
        coordStack.pop();
        int r = current.r();
        int c = current.c();
        if (r == er && c == ec) {
            return true;
        }
        // Check each direction
        if (r < 9 && maze[r + 1][c] == '.') { // South
            Coord next(r + 1, c);
            coordStack.push(next);
            maze[r + 1][c] = 'X'; 
        }
        if (c < 9 && maze[r][c + 1] == '.') { // East
            Coord next(r, c + 1);
            coordStack.push(next);
            maze[r][c + 1] = 'X';
        }
        if (r > 0 && maze[r - 1][c] == '.') { // North
            Coord next(r - 1, c);
            coordStack.push(next);
            maze[r - 1][c] = 'X'; 
        }
        if (c > 0 && maze[r][c - 1] == '.') { // West
            Coord next(r, c - 1);
            coordStack.push(next);
            maze[r][c - 1] = 'X'; 
        }
    }
    return false; // No path is found
}

int main()
{
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X' },
        { 'X','.','.','.','X','.','.','.','.','X' },
        { 'X','.','.','X','X','.','X','X','.','X' },
        { 'X','.','X','.','.','.','.','X','X','X' },
        { 'X','X','X','X','.','X','X','X','.','X' },
        { 'X','.','.','X','.','.','.','X','.','X' },
        { 'X','.','.','X','.','X','.','.','.','X' },
        { 'X','X','.','X','.','X','X','X','X','X' },
        { 'X','.','.','.','.','.','.','.','.','X' },
        { 'X','X','X','X','X','X','X','X','X','X' }
    };

    if (pathExists(maze, 3,4, 8,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}