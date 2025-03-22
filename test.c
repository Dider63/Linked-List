#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *link;
};

void print(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->link;
    }
    printf("\n");
}

struct node* insertatbeg(struct node* head, int val) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = val;
    new_node->link = head;
    return new_node;
}
struct node* deleteatbeg(struct node* head) {
    if (head == NULL) return NULL;
    struct node* temp = head;
    head = head->link;
    free(temp);
    return head;
}

struct node* insertatend(struct node *head, int val) {
    struct node *ptr = head;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = val;
    new_node->link = NULL;

    if (head == NULL) return new_node;

    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = new_node;
    return head;
}

struct node* deleteatend(struct node* head) {
    if (head == NULL) return NULL;
    if (head->link == NULL) {
        free(head);
        return NULL;
    }
    struct node *ptr = head;
    while (ptr->link->link != NULL) {
        ptr = ptr->link;
    }
    free(ptr->link);
    ptr->link = NULL;
    return head;
}

struct node* insertanypos(struct node* head, int pos, int val) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = val;
    new_node->link = NULL;

    if (pos == 1) {
        new_node->link = head;
        return new_node;
    }

    struct node *temp = head;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->link;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }

    new_node->link = temp->link;
    temp->link = new_node;
    return head;
}

struct node* deleteatpos(struct node* head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 1) {
        struct node* temp = head;
        head = head->link;
        free(temp);
        return head;
    }
    struct node *temp = head, *prev = NULL;
    int i = 1;
    while (i < pos && temp != NULL) {
        prev = temp;
        temp = temp->link;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }
    prev->link = temp->link;
    free(temp);
    return head;
}

int main() {
    struct node *head = NULL, *current = NULL, *temp = NULL;
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        temp = (struct node*)malloc(sizeof(struct node));
        temp->value = val;
        temp->link = NULL;
        if (head == NULL) {
            head = temp;
            current = temp;
        } else {
            current->link = temp;
            current = temp;
        }
    }
    printf("Original List: ");
    print(head);

    printf("\nEnter the value to insert at beg: ");
    int val1;
    scanf("%d", &val1);
    head = insertatbeg(head, val1);
    printf("After insertion: ");
    print(head);

    printf("\nEnter the value to insert at end: ");
    int val2;
    scanf("%d", &val2);
    head = insertatend(head, val2);
    printf("After insertion: ");
    print(head);

    int val3, pos;
    printf("\nEnter value to insert: ");
    scanf("%d", &val3);
    printf("Enter position to be inserted: ");
    scanf("%d", &pos);
    head = insertanypos(head, pos, val3);
    print(head);

    printf("\nDeleting at beginning...\n");
    head = deleteatbeg(head);
    print(head);

    printf("\nDeleting at end...\n");
    head = deleteatend(head);
    print(head);

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    head = deleteatpos(head, pos);
    print(head);

    return 0;
}
