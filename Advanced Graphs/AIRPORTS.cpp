/* AIRPORTS
The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
Of course, one option is to build an airport in each of these places, but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations. Since these are long distance roads connecting major locations in the country (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
A location is considered to have access to an airport either if it contains an airport or if it is possible to travel by road to another location from there that has an airport. You are given the cost of building an airport and a list of possible roads between pairs of locations and their corresponding costs. The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport. The aim is to make airport access as easy as possible, so if there are several ways of getting the minimal cost, choose the one that has the most airports.
Input
The first line of input contains the integer T (T < 25), the number of test cases. The rest of the input consists of T cases. Each case starts with two integers N, M and A (0 < N ≤ 10, 000, 0 ≤ M ≤ 100, 000, 0 < A ≤ 10, 000) separated by white space. N is the number of locations, M is the number of possible roads that can be built, and A is the cost of building an airport.
The following M lines each contain three integers X, Y and C (1 ≤ X, Y ≤ N, 0 < C ≤ 10, 000), separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .
Output
Your program should output exactly T lines, one for each case. Each line should be of the form ‘Case #X: Y Z’, where X is the case number Y is the minimum cost of making roads and airports so that all locations have access to at least one airport, and Z is the number of airports to be built. As mentioned earlier, if there are several answers with minimal cost, choose the one that maximizes the number of airports.
Sample Input
2
4 4 100
1 2 10
4 3 12
4 1 41
2 3 23
5 3 1000
1 2 20
4 5 40
3 2 30
Sample Output
Case #1: 145 1
Case #2: 2090 2 */



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