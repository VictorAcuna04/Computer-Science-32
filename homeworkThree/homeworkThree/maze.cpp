using namespace std;

const char WALL = 'X';
const char OPEN = '.';
const char SEEN = 'o';

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    if (sr < 0  ||  sr > 9  ||  sc < 0  || sc > 9  ||
        er < 0  ||  er > 9  ||  ec < 0  || ec > 9  ||
        maze[sr][sc] != OPEN  ||  maze[er][ec] != OPEN)
       return false;

    if (sr == er && sc == ec) { // Base case: we've reached the end
        return true;
    }

    maze[sr][sc] = SEEN; // Mark the current location as visited

    if (sr + 1 < 10 && maze[sr + 1][sc] == OPEN && pathExists(maze, sr + 1, sc, er, ec)) {
        return true;
    }

    if (sc + 1 < 10 && maze[sr][sc + 1] == OPEN && pathExists(maze, sr, sc + 1, er, ec)) {
        return true;
    }

    if (sr - 1 >= 0 && maze[sr - 1][sc] == OPEN && pathExists(maze, sr - 1, sc, er, ec)) {
        return true;
    }

    if (sc - 1 >= 0 && maze[sr][sc - 1] == OPEN && pathExists(maze, sr, sc - 1, er, ec)) {
        return true;
    }

    return false;
}
