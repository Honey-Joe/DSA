#include <stdio.h>
#include <stdlib.h>

struct Node {
    int pid;
    int remaining_bt;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

/* Enqueue */
void enqueue(int pid, int bt) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->pid = pid;
    newNode->remaining_bt = bt;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

/* Dequeue */
struct Node* dequeue() {
    if (front == NULL)
        return NULL;

    struct Node *temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    return temp;
}

int isEmpty() {
    return front == NULL;
}

int main() {
    int n, tq, i;
    int burst[10], waiting[10] = {0}, turnaround[10] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &burst[i]);
        enqueue(i + 1, burst[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0;
    printf("\nGantt Chart:\n");

    while (!isEmpty()) {
        struct Node *p = dequeue();

        if (p->remaining_bt > tq) {
            printf("| P%d ", p->pid);
            time += tq;
            p->remaining_bt -= tq;
            enqueue(p->pid, p->remaining_bt);
        } else {
            printf("| P%d ", p->pid);
            time += p->remaining_bt;
            turnaround[p->pid - 1] = time;
            waiting[p->pid - 1] = turnaround[p->pid - 1] - burst[p->pid - 1];
        }
        free(p);
    }
    printf("|\n");

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n",
               i + 1, burst[i], waiting[i], turnaround[i]);
        avg_wt += waiting[i];
        avg_tat += turnaround[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}