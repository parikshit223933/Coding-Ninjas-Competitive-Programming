#include <stdio.h>
#include <stdlib.h>
#define init(i,a,n) for(i=1;i<=n;i++)a[i]=i
typedef struct Edge {
    int f,t,w;
} E;
E roads[100005];
int set[10005];
int getParent(int i,int *set) {
    if(i==set[i])
        return i;
    else
        return (set[i]=getParent(set[i],set));
}
int isUnion(int a,int b,int* set) {
    return getParent(a,set)==getParent(b,set);
}
void makeUnion(int a,int b,int* set) {
    set[getParent(a,set)] = getParent(b,set);
}
int cmp(const void*a,const void*b) {
    return ((E*)a)->w-((E*)b)->w;
}
int main() {
    int c,cc,n,v,i,j,cost,total,air;
    scanf("%d",&c);
    cc=1;
    while(c--) {
        scanf("%d %d %d",&n,&v,&cost);
        for(i=0; i<v; i++)
            scanf("%d %d %d",&roads[i].f,&roads[i].t,&roads[i].w);
        qsort(roads,v,sizeof(E),&cmp);
        init(i,set,n);
        total = 0;
        j=0;
        air = 0;
        for(i=0; i<v&&j<n-1&&roads[i].w<cost; i++) {
            if(!isUnion(roads[i].t,roads[i].f,set)) {
                total+=roads[i].w;
                makeUnion(roads[i].t,roads[i].f,set);
                j++;
            }
        }
        for(i=1; i<=n; i++) {
            total+=cost*(set[i]==i);
            air+=(set[i]==i);
        }
        printf("Case %d: %d %d\n",cc++,total,air);
    }
    return 0;
}