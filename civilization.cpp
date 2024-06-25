#include <iostream>
#include <list>
#include <set>

using namespace std;

char playMap[1000 + 2][1000+ 2] = {0};
int weight[1000 + 2][1000+ 2] = {0};
char path[1000+ 2][1000+ 2] = {0};

void searching(int N, int M, int xStart, int yStart, int xEnd, int yEnd) {
    set<pair<int, pair<int, int>>> dist;
    weight[xStart][yStart] = 0;
    dist.insert({weight[xStart][yStart], {xStart, yStart}});

    while (!dist.empty()) {
        int curX = dist.begin()->second.first;
        int curY = dist.begin()->second.second;
        dist.erase(dist.begin());

        if (curX == xEnd && curY == yEnd) {
            break;
        }

        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto& dir : directions) {
            int newX = curX + dir[0];
            int newY = curY + dir[1];

            if (newX >= 1 && newX <= N && newY >= 1 && newY <= M && weight[curX][curY] + playMap[newX][newY] < weight[newX][newY]) {
                dist.erase({weight[newX][newY], {newX, newY}});
                weight[newX][newY] = weight[curX][curY] + playMap[newX][newY];
                path[newX][newY] = (dir[0] == 0 && dir[1] == 1) ? 'E' : (dir[0] == 1 && dir[1] == 0) ? 'S' : (dir[0] == 0 && dir[1] == -1) ? 'W' : 'N';
                dist.insert({weight[newX][newY], {newX, newY}});
            }
        }
    }
}

int main() {
    int N, M, xStart, yStart, xEnd, yEnd;
    cin >> N >> M >> xStart >> yStart >> xEnd >> yEnd;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            char cur;
            cin >> cur;
            if (cur == '.' || cur == 'W') {
                playMap[i][j] = (cur == '.') ? 1 : 2;
                weight[i][j] = 1000000;
            }
        }
    }

    searching(N, M, xStart, yStart, xEnd, yEnd);

    if (weight[xEnd][yEnd] != 1000000) {
        cout << weight[xEnd][yEnd] << endl;
        int x = xEnd, y = yEnd;
        list<char> resPath;

        while (x != xStart || y != yStart) {
            char dir = path[x][y];
            resPath.push_front(dir);

            if (dir == 'E') y -= 1;
            else if (dir == 'S') x -= 1;
            else if (dir == 'W') y += 1;
            else if (dir == 'N') x += 1;
        }

        for (char c : resPath) {
            cout << c;
        }
    } else {
        cout << -1;
    }

    return 0;
}
