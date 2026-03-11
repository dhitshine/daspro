#include <stdio.h>
#include <stdlib.h>
const int mxn = 2e5;
typedef struct {
  int *data;
  int used;
  int size;
} Vector;

Vector adj[200005];

void add_edge(Vector *adj, int to){
  if(adj->used == adj->size){
    if(adj->used == 0){
      adj->size = 1;
    }else{
      adj->size = 2*(adj->used);
    }
    adj->data = (int *)realloc(adj->data, (adj->size) * sizeof(int));
  }
  adj->data[adj->used] = to;
  adj->used++;
}

int main(){
  int u, v, n = 1;
  for(int i = 0; i < mxn; i++){
    adj[i].used = 0;
    adj[i].size = 0;
    adj[i].data = NULL;
  }
  while(scanf("%d %d", &u, &v) != EOF){
    add_edge(&adj[u], v);
    add_edge(&adj[v], u);
    if(n < u){
      n = u;
    }
    if(n < v){
      n = v;
    }
  }
  for(int i = 1; i <= n; i++){
    if(adj[i].used == 0) continue;
    printf("Pulau %d: ", i);
    for(int j = 0; j < adj[i].used; j++){
      printf("%d ", adj[i].data[j]);
    }
    printf("\n");
  }
  for(int i = 1; i <= n; i++){
    if(adj[i].data != NULL){
      free(adj[i].data);
    }
  }
  return 0;
}


/*
typedef struct Node {
  int to;
  struct Node* next;
} Node;

Node* adj[200005];      // ptr yang menunjuk ke head linked list pada node ke i

void add_edge(int u, int v){
  Node* newnode = malloc(sizeof(Node));    // newnode adalah pointer yang menunjuk ke blok memori kosong
  newnode->to = v;
  newnode->next = adj[u];
  adj[u] = newnode;
}

int main(){
  int u, v;
  for(int i = 0; i < mxn; i++){
    adj[i] = NULL;
  }
  int n = 1;
  while(scanf("%d %d", &u, &v) == 2){
    add_edge(u, v);
    add_edge(v, u);
    if(n < u){
      n = u;
    }
    if(n < v){
      n = v;
    }
  }
  for(int i = 1; i <= n; i++){
    Node *ptr = adj[i];
    if(ptr == NULL){ // kalo node i gada tetangga skip
      continue;
    }
    printf("Pulau %d: ", i);
    while(ptr != NULL){
      printf("%d ", ptr->to);
      ptr = ptr->next;
    }
    printf("\n");
  }
}
*/
