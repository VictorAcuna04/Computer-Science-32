#include <iostream>
#include <queue>
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
    queue<Coord> coordQueue;
    Coord start(sr, sc);
    coordQueue.push(start);
    maze[sr][sc] = 'X'; // mark starting coordinate as visited
    while (!coordQueue.empty()) {
        Coord current = coordQueue.front();
        coordQueue.pop();
        int r = current.r();
        int c = current.c();
        if (r == er && c == ec) {
            return true; // reached the end
        }
        // check each direction to move to
        if (r < 9 && maze[r + 1][c] == '.') { // south
            Coord next(r + 1, c);
            coordQueue.push(next);
            maze[r + 1][c] = 'X'; // mark as visited
        }
        if (c < 9 && maze[r][c + 1] == '.') { // east
            Coord next(r, c + 1);
            coordQueue.push(next);
            maze[r][c + 1] = 'X'; // mark as visited
        }
        if (r > 0 && maze[r - 1][c] == '.') { // north
            Coord next(r - 1, c);
            coordQueue.push(next);
            maze[r - 1][c] = 'X'; // mark as visited
        }
        if (c > 0 && maze[r][c - 1] == '.') { // west
            Coord next(r, c - 1);
            coordQueue.push(next);
            maze[r][c - 1] = 'X'; // mark as visited
        }
    }
    return false; // no path found
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
