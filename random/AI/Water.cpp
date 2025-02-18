#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct State {
    int A, B;
    State(int _A, int _B) : A(_A), B(_B) {}
};

bool is_goal_state(int A, int B, int target) {
    return A == target || B == target;
}

void bfs_water_jug(int jugA, int jugB, int target) {
    set<pair<int, int>> visited;
    queue<State> q;
    q.push(State(0, 0));

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (visited.count({current.A, current.B}))
            continue;
        visited.insert({current.A, current.B});

        cout << "Jug A: " << current.A << ", Jug B: " << current.B << "\n";

        if (is_goal_state(current.A, current.B, target)) {
            cout << "Reached target: Jug A: " << current.A << ", Jug B: " << current.B << "\n";
            return;
        }

        q.push(State(jugA, current.B));  // Fill Jug A
        q.push(State(current.A, jugB));  // Fill Jug B
        q.push(State(0, current.B));     // Empty Jug A
        q.push(State(current.A, 0));     // Empty Jug B
        q.push(State(current.A - min(current.A, jugB - current.B), current.B + min(current.A, jugB - current.B))); // Pour Jug A -> Jug B
        q.push(State(current.A + min(current.B, jugA - current.A), current.B - min(current.B, jugA - current.A))); // Pour Jug B -> Jug A
    }
}

void dfs_water_jug(int A, int B, int jugA, int jugB, int target, set<pair<int, int>>& visited) {
    if (visited.count({A, B}))
        return;
    visited.insert({A, B});

    cout << "Jug A: " << A << ", Jug B: " << B << "\n";

    if (is_goal_state(A, B, target)) {
        cout << "Reached target: Jug A: " << A << ", Jug B: " << B << "\n";
        return;
    }

    dfs_water_jug(jugA, B, jugA, jugB, target, visited);  // Fill Jug A
    dfs_water_jug(A, jugB, jugA, jugB, target, visited);  // Fill Jug B
    dfs_water_jug(0, B, jugA, jugB, target, visited);     // Empty Jug A
    dfs_water_jug(A, 0, jugA, jugB, target, visited);     // Empty Jug B
    dfs_water_jug(A - min(A, jugB - B), B + min(A, jugB - B), jugA, jugB, target, visited); // Pour Jug A -> Jug B
    dfs_water_jug(A + min(B, jugA - A), B - min(B, jugA - A), jugA, jugB, target, visited); // Pour Jug B -> Jug A
}

int main() {
    int jugA = 4, jugB = 3, target = 2;
    cout << "BFS Solution:\n";
    bfs_water_jug(jugA, jugB, target);

    cout << "\nDFS Solution:\n";
    set<pair<int, int>> visited;
    dfs_water_jug(0, 0, jugA, jugB, target, visited);

    return 0;
}