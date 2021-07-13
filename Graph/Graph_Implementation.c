#include<stdio.h>
#include<stdlib.h>

struct edge{
    char data;
    struct edge *next;
};

struct node{
    char data;
    struct node *next;
    struct edge *enext;
};

void addvertex(struct node**, char);
void insertedge(struct node*, char, char);
struct node *findvertex(struct node*, char);
void removeedge(struct node*, char, char);
void removevertex(struct node**, char);
void display(struct node*);

void main(){
    int choice; 
    char vertex1, vertex2;
    struct node *start = NULL;

    while(choice != 6){
        printf("\n1. Add Vertex \n2. Insert Edge \n3. Remove Vertex \n4. Remove Edge \n5. Display \n6. Exit \nEnter choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter Vertex : ");
                scanf(" %c", &vertex1);
                addvertex(&start, vertex1);
                break;
            case 2:
                printf("\nEnter Starting Vertex : ");
                scanf(" %c", &vertex1);
                printf("\nEnter Destination Vertex : ");
                scanf(" %c", &vertex2);
                insertedge(start, vertex1, vertex2);
                break;
            case 3:
                printf("\nEnter Vertex : ");
                scanf(" %c", &vertex1);
                removevertex(&start, vertex1);
                break;
            case 4:
                printf("\nEnter source Vertex : ");
                scanf(" %c", &vertex1);
                printf("\nEnter destination Vertex : ");
                scanf(" %c", &vertex2);
                removeedge(start, vertex1, vertex2);
                break;
            case 5:
               display(start);
                break;
            case 6:
                continue;
            default:
                printf("Please enter a valid choice !");
        }
    }
}

void addvertex(struct node **ps, char data){
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    p->enext = NULL;

    if(*ps == NULL){
        *ps = p;
        return;
    }
    
    struct node *temp = *ps;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = p;
}

void insertedge(struct node *start, char v1, char v2){
    if(start == NULL){
        printf("\nNo vertex found; edge can not be inserted.");
        return;
    }
    if(start->next == NULL){
        if(v1==v2 && v1==start->data){
            struct edge *newEdge = (struct edge*)malloc(sizeof(struct edge));
            newEdge->data = v1; 
            newEdge->next = NULL;
            start->enext = newEdge;
        }
        else{
            printf("\nVertices not found.");
        }
        return;
    }
    struct node *vertex1 = findvertex(start, v1);
    struct node *vertex2 = findvertex(start, v2);
    if(vertex1 == NULL || vertex2 == NULL){
        printf("\nVertices not found.");
        return;
    }

    struct edge *newEdge1 = (struct edge*)malloc(sizeof(struct edge));
    newEdge1->data = v2; 
    newEdge1->next = NULL;

    struct edge *temp1 = vertex1->enext; //*temp2 = vertex2->enext;

    if(temp1 == NULL){
        vertex1->enext = newEdge1;
    }
    else{
        while(temp1->next!=NULL){
            temp1 = temp1->next;
        }
        temp1->next = newEdge1;
    }

}

struct node *findvertex(struct node *start, char vertex){
    while(start!=NULL && start->data != vertex)
        start = start->next;

    return start;
}

void removeedge(struct node *start, char v1, char v2){
    if(start == NULL){
        printf("\nNo node present in graph:");
        return;
    }
    if(start->next == NULL){
        if(v1 == v2 && v1 == start->data){
            free(start->enext);
            start->enext = NULL;
        }
        else
            printf("\nVertices are not present in the graph.");
        
        return;
    }

    struct node *vertex1 = findvertex(start, v1);
    struct node *vertex2 = findvertex(start, v2);

    if(vertex1 == NULL || vertex2 == NULL){
        printf("\nVertices not found.");
        return;
    }

    struct edge *temp1 = vertex1->enext; //*temp2 = vertex2->enext;
    struct edge *prev1 = temp1;  //*prev2 = temp2;
    
    while(temp1!=NULL && temp1->data!=v2){
        prev1 = temp1;
        temp1 = temp1->next;
    }

    if(temp1 == NULL){
        printf("\nEdge is not present between the given vertices.");
        return;
    }

    prev1->next = temp1->next;
    if(vertex1->enext == prev1){
        vertex1->enext = NULL;
    }
    free(temp1);

}

void removevertex(struct node **ps, char vertex){
    if(*ps == NULL){
        printf("\n Graph contains 0 vertices.");
        return;
    }

    struct node *temp = *ps;
    if((*ps)->next == NULL){
        if((*ps)->data == vertex){
            free(temp);
            *ps = NULL;
        }
        else
            printf("Vertex not found.");
        return;
    }

    int count = 0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    temp = *ps;
    int arr[count], i=0;

    struct node *vert = findvertex(*ps, vertex);
    if(vert == NULL){
        printf("\nVertex not found.");
        return;
    }

    struct edge *temp2 = vert->enext;
    while(temp2!=NULL){
        arr[i] = temp2->data;
        i++;
    }
    
    count = i;
    for(i=0; i<count; i++){
        removeedge(*ps, vertex, arr[i]);
        removeedge(*ps, arr[i], vertex);
    }

    temp = *ps;
    struct node *prev = temp;
    while(temp->data!=vertex){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    
}

void display(struct node *start){
    if(start == NULL){
        printf("\nGraph has no vertices.");
        return;
    }

    struct edge *temp;
    while(start!=NULL){
        temp = start->enext;
        printf("\nVertex: %c", start->data);
        printf("\nAdjacent vertices : ");
        if(temp == NULL){
            printf("No adjacent vertex.");
        }
        while(temp!=NULL){
            printf(" %c", temp->data);
            temp = temp->next;
        }
        start = start->next;
    }

}