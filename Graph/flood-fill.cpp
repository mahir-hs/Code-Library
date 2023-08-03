int fx[] = {0, 1, 0, -1};
int fy[] = { -1, 0, 1, 0};
int row_num;
int col_num;
string building[300];
bool visited[300][300];

void floodfill(int r, int c) {
    // Note: you can also use a queue and pop from the front for a BFS-based
    // approach
    stack<pair<int, int>> frontier;
    frontier.push({r, c});
    while (!frontier.empty()) {
        r = frontier.top().first;
        c = frontier.top().second;
        frontier.pop();

        if (r < 0 || r >= row_num || c < 0 || c >= col_num ||
                building[r][c] == '#' || visited[r][c])
            continue;

        visited[r][c] = true;
        for (int i = 0; i < 4; i++) {
            frontier.push({r + fx[i], c + fy[i]});
        }
    }
}