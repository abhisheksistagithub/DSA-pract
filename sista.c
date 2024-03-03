Bubble sort:
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Optimization: Flag to track if any swaps occurred
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;  // Set flag if a swap happens
            }
        }

        // Optimization: Early termination if no swaps occurred
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
#include <stdio.h>

void selectionSort(int arr[], int n) {
  int i, j, min_idx;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < n - 1; i++) {
    // Find the minimum element in unsorted array
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }

    // Swap the found minimum element with the first element
    if (min_idx != i) {
      swap(&arr[min_idx], &arr[i]);
    }
  }
}

// A utility function to swap two elements
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);

  selectionSort(arr, n);

  printf("Sorted array: \n");
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}





#include <stdio.h>

void insertionSort(int arr[], int n) {
  int i, key, j;

  // One by one move boundary of unsorted subarray
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {12, 11, 13, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  insertionSort(arr, n);

  printf("Sorted array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}














#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Partition function to place pivot element at its correct position
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1); // index of smaller element

  for (int j = low; j <= high - 1; j++) {
    // If current element is smaller than the pivot
    if (arr[j] < pivot) {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

// Recursive function to implement quick sort
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    // pi is partitioning index, arr[p] is now at right place
    int pi = partition(arr, low, high);

    // Recursively sort elements before and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Function to print the array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort(arr, 0, n - 1);

  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}
















#include <stdio.h>

// Function prototypes
void swap(int *a, int *b);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain max-heap property
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Main function to test the heap sort
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temporary arrays
  int left[n1], right[n2];

  // Copy data to temporary arrays
  for (int i = 0; i < n1; i++) {
    left[i] = arr[l + i];
  }
  for (int j = 0; j < n2; j++) {
    right[j] = arr[m + 1 + j];
  }

  // Merge the temporary arrays back into arr[l..r]
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of left[]
  while (i < n1) {
    arr[k] = left[i];
    i++;
    k++;
  }

  // Copy the remaining elements of right[]
  while (j < n2) {
    arr[k] = right[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Find the middle point
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted halves
    merge(arr, l, m, r);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {6, 5, 3, 1, 8, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, n - 1);

  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}



















Sequential Search
#include <stdio.h>

int sequentialSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 2, 8, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    int index = sequentialSearch(arr, size, key);

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    } return 0;  }
#include <stdio.h>
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }
  int mid = low + (high - low) / 2;
 if (arr[mid] == key) {
        return mid;
    } else if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, high, key);
    } else {
        return binarySearch(arr, low, mid - 1, key);   }
}
int main() {
    int arr[] = {2, 5, 8, 12, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 12;
    int index = binarySearch(arr, 0, size - 1, key);
   if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }   return 0;
}
#include <stdio.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = element;
}
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
int main() {
    push(10);
    push(20);
    push(30);
 printf("Popped element: %d\n", pop());
return 0;  }
4th Question
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char ch) {
    switch (ch) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void push(char ch) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

void infixToPostfix(char *infix, char *postfix) {
    int i, j;
    char ch;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (stack[top] != '(' && top != -1) {
                postfix[j++] = pop();
            }
            if (top == -1) {
                printf("Invalid Expression\n");
                exit(1);
            }
            pop(); // pop the '('
        } else {
            while (top != -1 && precedence(ch) <= precedence(stack[top])) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char *postfix) {
    int i, val1, val2, stack[MAX_SIZE], top = -1;

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            val2 = pop();
            val1 = pop();
            switch (ch) {
                case '+':
                    push(val1 + val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '/':
                    push(val1 / val2);
                    break;
                case '^':
                    push(val1 ^ val2); // Assuming non-negative integer exponentiation
                    break;
                default:
                    printf("Invalid Expression\n");
                    exit(1);
            }
        }
    }
  return stack[top];
}
int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
   infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("Evaluation result: %d\n", result);
     return 0;
}


















#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void push(int element) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = element;
}

int pop() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
  printf("Popped element: %d\n", pop());
   display();
   return 0;
}


6th Question
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void displayList(struct Node* head);
struct Node* insertAtBeginning(struct Node** head, int data);
struct Node* insertAtEnd(struct Node* head, int data);
struct Node* deleteNode(struct Node* head, int data);

int main() {
    struct Node* head = NULL;

    // Create linked list
    head = insertAtEnd(head, 10);
    head = insertAtBeginning(&head, 5);
    head = insertAtEnd(head, 20);

    // Display list
    printf("Created linked list: ");
    displayList(head);

    // Delete node
    head = deleteNode(head, 10);

    // Display list after deletion
    printf("Linked list after deletion: ");
    displayList(head);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    return *head;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
// Function to delete a node with the given data
struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        return head;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
   while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
 if (temp == NULL) {
        printf("Element not found\n");
        return head;
    }
   if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    return head;
}




















7th Question
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void displayList(struct Node* head);
struct Node* insertAtBeginning(struct Node** head, int data);
struct Node* insertAtEnd(struct Node* head, int data);
struct Node* deleteNode(struct Node* head, int data);

int main() {
    struct Node* head = NULL;

    // Create linked list
    head = insertAtEnd(head, 10);
    head = insertAtBeginning(&head, 5);
    head = insertAtEnd(head, 20);

    // Display list
    printf("Created doubly linked list: ");
    displayList(head);

    // Delete node
    head = deleteNode(head, 10);

    // Display list after deletion
    printf("Doubly linked list after deletion: ");
    displayList(head);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the doubly linked list
struct Node* insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
    return *head;
}

// Function to insert a node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to delete a node with the given data
struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        return head;
    }
    struct Node* temp = head;

    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
        return head;
    }

    if (temp->prev == NULL) {
        head = temp->next;
    } else {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}







8th Question
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
void insertNode(struct Node** root, int data);
struct Node* deleteNode(struct Node* root, int data);
void preOrderTraversal(struct Node* root);

int main() {
    struct Node* root = NULL;

    // Create binary tree
    insertNode(&root, 50);
    insertNode(&root, 30);
    insertNode(&root, 20);
    insertNode(&root, 40);
    insertNode(&root, 70);
    insertNode(&root, 60);
    insertNode(&root, 80);

    // Display tree using pre-order traversal
    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    // Delete node
    root = deleteNode(root, 20);

    // Display tree after deletion
    printf("Pre-order traversal after deletion: ");
    preOrderTraversal(root);
    printf("\n");

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
void insertNode(struct Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    if (data < (*root)->data) {
        insertNode(&(*root)->left, data);
    } else {
        insertNode(&(*root)->right, data);
    }
}

// Function to find the minimum value node in a sub-tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from the binary tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with one or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to perform pre-order traversal of the binary tree
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}



Dijkstra:

#include <stdio.h>
#include <limits.h>
#define V 9
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int n) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V);
}
int main(){
    int graph[V][V] = {
        {0, 15, 0, 0, 0, 0, 0, 9, 0},
        {6, 0, 9, 0, 0, 0, 0, 15, 0},
        {0, 9, 8, 7, 0, 6, 0, 0, 3},
        {0, 0, 9, 0, 9, 17, 0, 0, 0},
        {11, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 18, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {9, 15, 0, 0, 24, 0, 1, 0, 9},
        {0, 0, 5, 0, 0, 0, 6, 9, 0}
    };

    printf("Dijkstra's Algorithm:\n");
    dijkstra(graph, 0);

    return 0;
}






Floyd Warshall:

#include <stdio.h>

#define V 4
#define INF 99999

void printSolution(int dist[][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V]) {
    int dist[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
  printSolution(dist);
}
int main() {
    int graph[V][V] = {
        {0, 19, INF, 27},
        {INF, 0, 27, INF},
        {INF, INF, 0, 7},
        {INF, INF, INF, 17}
    };
    printf("Floyd's Algorithm:\n");
    floydWarshall(graph);
    return 0;
}
