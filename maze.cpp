#include <string>
#include <vector>

void floodFill(std::vector<std::vector<int>> &maze, int x, int y) {
    if(maze[y][x] == 1) return;
    if(maze[y][x] == -1) return;
    maze[y][x] = 1;
    if(y + 1 < static_cast<int>(maze.size()))     // south
        floodFill(maze, x, y + 1);
    if(y - 1 >= 0)                                // north
        floodFill(maze, x, y - 1);
    if(x + 1 < static_cast<int>(maze[y].size()))  // east
        floodFill(maze, x + 1, y);
    if(x - 1 >= 0)                                // west
        floodFill(maze, x - 1, y);
    return;
}

bool path_finder(std::string maze_) {

    // get maze size
    unsigned int size = 0;
    for (auto &i: maze_) {
        if(i == '\n') break;
        ++size;
    }

    // fill maze
    int x = 0;
    int y = 0;
    std::vector<std::vector<int>> maze {size, std::vector<int>(size, -1)};
    for(auto &i : maze_) {
        if(i == '\n') {
            x = 0;
            ++y;
            continue;
        }
        if (i == '.') maze[y][x] = 0;
        ++x;
    }

    // navigate though the maze
    x = 0;
    y = 0;
    floodFill(maze, x, y);

    // check if end has been visited
    if(maze[maze.size() - 1][maze[0].size() -1] == 1) return true;
    else  return false;
}