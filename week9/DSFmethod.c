#include<stdio.h>
#define MAX 10
int visited[MAX], adj[MAX][MAX], n;
void DFS(int v){
    visited[v]=1;
    printf("%d",v);
    for (int i=0;i<n;i++){
        if (adj[v][i]==1 && !visited[i]){
            DFS(i);
        }
    }
}
int main(){
    printf("Enter no. of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacence matrix: ");
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for (int i=0;i<n;i++){
        visited[i]=0;
    }
    printf("DFS Traversal: \n");
    DFS(0);
    return 0;
}