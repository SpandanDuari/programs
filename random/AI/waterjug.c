#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int jugA, jugB;
} State;

typedef struct {
    State queue[MAX];
    int front, rear;
} Queue;

typedef struct {
    State stack[MAX];
    int top;
} Stack;

typedef struct {
    bool visited[100][100];
} Visited;

void initQueue(Queue *q) { q->front = q->rear = 0; }
bool isQueueEmpty(Queue *q) { return q->front == q->rear; }
void enqueue(Queue *q, State s) { if (q->rear < MAX) q->queue[q->rear++] = s; }
State dequeue(Queue *q) { return q->queue[q->front++]; }

void initStack(Stack *s) { s->top = -1; }
bool isStackEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, State st) { if (s->top < MAX - 1) s->stack[++s->top] = st; }
State pop(Stack *s) { return s->stack[s->top--]; }

void initVisited(Visited *v) {
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            v->visited[i][j] = false;
}
bool isVisited(Visited *v, State s) { return v->visited[s.jugA][s.jugB]; }
void markVisited(Visited *v, State s) { v->visited[s.jugA][s.jugB] = true; }

bool isGoal(State s, int target) { return s.jugA == target || s.jugB == target; }

void bfs(int capA, int capB, int target) {
    Queue q; Visited visited; initQueue(&q); initVisited(&visited);
    State start = {0, 0}; enqueue(&q, start); markVisited(&visited, start);

    while (!isQueueEmpty(&q)) {
        State current = dequeue(&q);
        printf("Jug A: %d, Jug B: %d\n", current.jugA, current.jugB);
        if (isGoal(current, target)) { printf("Solution found using BFS!\n"); return; }

        State nextStates[] = {
            {capA, current.jugB}, {current.jugA, capB},
            {0, current.jugB}, {current.jugA, 0},
            {current.jugA - (capB - current.jugB) > 0 ? current.jugA - (capB - current.jugB) : 0,
             current.jugB + (current.jugA > capB - current.jugB ? capB - current.jugB : current.jugA)},
            {current.jugA + (current.jugB > capA - current.jugA ? capA - current.jugA : current.jugB),
             current.jugB - (capA - current.jugA) > 0 ? current.jugB - (capA - current.jugA) : 0}
        };

        for (int i = 0; i < 6; i++) {
            if (nextStates[i].jugA >= 0 && nextStates[i].jugB >= 0 && !isVisited(&visited, nextStates[i])) {
                markVisited(&visited, nextStates[i]);
                enqueue(&q, nextStates[i]);
            }
        }
    }
    printf("No solution found using BFS.\n");
}

void dfs(int capA, int capB, int target) {
    Stack s; Visited visited; initStack(&s); initVisited(&visited);
    State start = {0, 0}; push(&s, start); markVisited(&visited, start);

    while (!isStackEmpty(&s)) {
        State current = pop(&s);
        printf("Jug A: %d, Jug B: %d\n", current.jugA, current.jugB);
        if (isGoal(current, target)) { printf("Solution found using DFS!\n"); return; }

        State nextStates[] = {
            {capA, current.jugB}, {current.jugA, capB},
            {0, current.jugB}, {current.jugA, 0},
            {current.jugA - (capB - current.jugB) > 0 ? current.jugA - (capB - current.jugB) : 0,
             current.jugB + (current.jugA > capB - current.jugB ? capB - current.jugB : current.jugA)},
            {current.jugA + (current.jugB > capA - current.jugA ? capA - current.jugA : current.jugB),
             current.jugB - (capA - current.jugA) > 0 ? current.jugB - (capA - current.jugA) : 0}
        };

        for (int i = 0; i < 6; i++) {
            if (nextStates[i].jugA >= 0 && nextStates[i].jugB >= 0 && !isVisited(&visited, nextStates[i])) {
                markVisited(&visited, nextStates[i]);
                push(&s, nextStates[i]);
            }
        }
    }
    printf("No solution found using DFS.\n");
}

int main() {
    int capA = 4, capB = 3, target = 2;
    printf("Solving using BFS:\n"); bfs(capA, capB, target);
    printf("\nSolving using DFS:\n"); dfs(capA, capB, target);
    return 0;
}