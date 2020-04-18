/* Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.
Input
There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:

2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
Output
For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. Intermediate overflow will not occur with proper use of 64-bit signed integer.
Input:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1
Output:
Case 1:
30
7
13
Case 2:
1 */




#include<iostream>
using namespace std;
struct tree_attrs
{
	int sum_of_squares;
	int sum;
};
struct lazy_attrs
{
	int setter = 0;
	int incermentor = 0;
};
void build_tree(int* arr, tree_attrs* tree, int start, int end, int treenode)
{
	if (start == end)
	{
		tree[treenode].sum_of_squares = arr[start]*arr[start];
		tree[treenode].sum = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	build_tree(arr, tree, start, mid, 2 * treenode);
	build_tree(arr, tree, mid + 1, end, 2 * treenode + 1);
	tree[treenode].sum = tree[2 * treenode].sum + tree[2 * treenode + 1].sum;
	tree[treenode].sum_of_squares = tree[2 * treenode].sum_of_squares + tree[2 * treenode + 1].sum_of_squares;
}
void lazy_update_setter(tree_attrs* tree, lazy_attrs* lazy, int start, int end, int left, int right, int current_position, int x)
{
	if (start > end)
	{
		return;
	}
	if (lazy[current_position].setter != 0)
	{
		tree[current_position].sum = (right-left + 1) * (lazy[current_position].setter);
		tree[current_position].sum_of_squares = (right-left + 1) * (lazy[current_position].setter * lazy[current_position].setter);
		if (start != end)
		{
			lazy[2 * current_position].setter = lazy[current_position].setter;
			lazy[2 * current_position+1].setter = lazy[current_position].setter;
		}
		lazy[current_position].setter = 0;
	}

	//completely outside
	if (start > right || end < left)
	{
		return;
	}
	//complete overlap
	if (start >= left && end <= right)
	{
		tree[current_position].sum_of_squares = (right-left + 1) * (x * x);
		tree[current_position].sum = (right-left + 1) * x;
		if (start != end)
		{
			lazy[2 * current_position].setter = x;
			lazy[2 * current_position + 1].setter = x;
		}
		return;
	}
	//partial overlap
	int mid = (start + end) / 2;
	lazy_update_setter(tree, lazy, start, mid, left, right, 2 * current_position, x);
	lazy_update_setter(tree, lazy, mid+1, end, left, right, 2 * current_position+1, x);
	tree[current_position].sum = tree[2 * current_position].sum + tree[2 * current_position + 1].sum;
	tree[current_position].sum_of_squares = tree[2 * current_position].sum_of_squares + tree[2 * current_position + 1].sum_of_squares;
	return;
}
void lazy_update_incrementor(tree_attrs* tree, lazy_attrs* lazy, int start, int end, int left, int right, int current_position, int increment)
{
	if (start > end)
	{
		return;
	}
	if (lazy[current_position].incermentor != 0)
	{
		tree[current_position].sum_of_squares += (right-left + 1) * (lazy[current_position].incermentor * lazy[current_position].incermentor) + 2 * lazy[current_position].incermentor * tree[current_position].sum;
		tree[current_position].sum += (right-left + 1) * lazy[current_position].incermentor;
		if (start != end)
		{
			lazy[2 * current_position].incermentor += lazy[current_position].incermentor;
			lazy[2 * current_position + 1].incermentor += lazy[current_position].incermentor;
		}
		lazy[current_position].incermentor = 0;
	}
	if (lazy[current_position].setter != 0)
	{
		tree[current_position].sum = (right - left + 1) * (lazy[current_position].setter);
		tree[current_position].sum_of_squares = (right - left + 1) * (lazy[current_position].setter * lazy[current_position].setter);
		if (start != end)
		{
			lazy[2 * current_position].setter = lazy[current_position].setter;
			lazy[2 * current_position + 1].setter = lazy[current_position].setter;
		}
		lazy[current_position].setter = 0;
	}
	//completely outside
	if (start > right || end < left)
	{
		return;
	}
	//complete overlap
	if(start>=left&&end<=right)
	{
		tree[current_position].sum_of_squares += (right-left + 1) * (increment * increment) + 2 * increment * tree[current_position].sum;
		tree[current_position].sum += (right-left + 1) * increment;
		if (start != end)
		{
			lazy[2 * current_position].incermentor += increment;
			lazy[2 * current_position + 1].incermentor += increment;
		}
		return;
	}
	//partial overlap
	int mid = (start + end) / 2;
	lazy_update_incrementor(tree, lazy, start, mid, left, right, 2 * current_position, increment);
	lazy_update_incrementor(tree, lazy, mid+1, end, left, right, 2 * current_position+1, increment);
	tree[current_position].sum = tree[2 * current_position].sum + tree[2 * current_position + 1].sum;
	tree[current_position].sum_of_squares = tree[2 * current_position].sum_of_squares + tree[2 * current_position + 1].sum_of_squares;
	return;
}

tree_attrs query(tree_attrs* tree, lazy_attrs *lazy, int start, int end, int left, int right, int treenode)
{
	if (start > end)
	{
		return { 0, 0 };
	}
	if (lazy[treenode].incermentor != 0)
	{
		tree[treenode].sum_of_squares += 2 * lazy[treenode].incermentor * tree[treenode].sum + lazy[treenode].incermentor * lazy[treenode].incermentor * (right - left + 1);
		tree[treenode].sum += (right - left + 1) * lazy[treenode].incermentor;
		if (start != end)
		{
			lazy[2 * treenode].incermentor = lazy[treenode].incermentor;
			lazy[2 * treenode + 1].incermentor = lazy[treenode].incermentor;
		}
		lazy[treenode].incermentor = 0;
	}
	if (lazy[treenode].setter != 0)
	{
		tree[treenode].sum = (right - left + 1) * lazy[treenode].setter;
		tree[treenode].sum_of_squares = (right - left + 1) * lazy[treenode].setter;
		if (start != end)
		{
			lazy[2 * treenode].setter = lazy[treenode].setter;
			lazy[2 * treenode + 1].setter = lazy[treenode].setter;
		}
		lazy[treenode].setter = 0;
	}
	//completely outside
	if (start > right || end < left)
	{
		return { 0, 0 };
	}
	//fully inside
	if (start >= left && end <= right)
	{
		return tree[treenode];
	}
	//partial overlap
	int mid = (start + end) / 2;
	tree_attrs left_child = query(tree, lazy, start, mid, left, right, 2 * treenode);
	tree_attrs right_child = query(tree, lazy, mid+1, end, left, right, 2 * treenode+1);
	tree_attrs ans;
	ans.sum = left_child.sum + right_child.sum;
	ans.sum_of_squares = left_child.sum_of_squares + right_child.sum_of_squares;
	return ans;
}

int main()
{
	int t;
	cin >> t;
	int case_number = 1;
	while (t--)
	{
		cout << "Case " << case_number << ":" << endl;
		int n, q;
		cin >> n >> q;
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		tree_attrs* tree = new tree_attrs[4 * n]();
		lazy_attrs* lazy = new lazy_attrs[4 * n]();
		build_tree(arr, tree, 0, n - 1, 1);
		while (q--)
		{
			int type_of_operation;
			cin >> type_of_operation;
			if (type_of_operation == 2)
			{
				int left, right;
				cin >> left >> right;
				cout << query(tree, lazy, 0, n-1, left - 1, right - 1, 1).sum_of_squares<<endl;
			}
			else if (type_of_operation == 1)
			{
				int left, right;
				cin >> left >> right;
				int increment;
				cin >> increment;
				lazy_update_incrementor(tree, lazy, 0, n-1, left-1, right-1, 1, increment);
			}
			else
			{
				int left, right;
				cin >> left >> right;
				int x;
				cin >> x;
				lazy_update_setter(tree, lazy, 0, n-1, left-1, right-1, 1, x);
			}
		}
		case_number++;
	}
}

































// #include<iostream>
// #include<algorithm>
// using namespace std;
// void build_tree(int* arr, int* tree, int start, int end, int treeNode) {

// 	if (start == end) {
// 		tree[treeNode] = arr[start];
// 		return;
// 	}
// 	int mid = (start + end) / 2;

// 	build_tree(arr, tree, start, mid, 2 * treeNode);
// 	build_tree(arr, tree, mid + 1, end, 2 * treeNode + 1);
// 	tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
// }
// void lazy_update(int *tree, int *lazy, int start/*low*/, int end/*high*/, int left/*startr*/, int right/*endr*/, int current_position, int increment)
// {
// 	if (start > end)
// 	{
// 		return;
// 	}
// 	if (lazy[current_position] != 0)
// 	{
// 		tree[current_position] += lazy[current_position];
// 		if (start != end)
// 		{
// 			lazy[2 * current_position] += lazy[current_position];
// 			lazy[2 * current_position + 1] += lazy[current_position];
// 		}
// 		lazy[current_position] = 0;
// 	}
// 	//completely outside or no overlap.
// 	if (left > end || right < start)
// 	{
// 		return;
// 	}
// 	//complete overlap
// 	if (start>=left && right>=end)
// 	{
// 		tree[current_position] += increment;
// 		if (start != end)
// 		{
// 			lazy[2*current_position] +=increment;
// 			lazy[2 * current_position + 1] += increment;
// 		}
// 		return;
// 	}
// 	//partial overlap
// 	int mid = (start + end) / 2;
// 	lazy_update(tree, lazy, start, mid, left, right, 2 * current_position, increment);
// 	lazy_update(tree, lazy, mid + 1, end, left, right, 2 * current_position + 1, increment);
// 	tree[current_position] = min(tree[2 * current_position], tree[2 * current_position + 1]);
// }
// int main()
// {
// 	int arr[] = { 1,3,-2,4 };
// 	int* tree = new int[12]();
// 	build_tree(arr, tree, 0, 3, 1);
// 	int* lazy = new int[12]();
// 	lazy_update(tree, lazy, 0, 3, 0, 3, 1, 3);
// 	lazy_update(tree, lazy, 0, 3, 0, 1, 1, 2);

// 	cout << "Segment Tree" << endl;
// 	for (int i = 1; i < 12; i++) {
// 		cout << tree[i] << endl;
// 	}

// 	cout << "Lazy Tree" << endl;
// 	for (int i = 1; i < 12; i++) {
// 		cout << lazy[i] << endl;
// 	}

// 	return 0;
// }





/*FOLLOWING IS THE CODE OF A TA*/

// #include<iostream>
// #include<algorithm>
// #define FOR(i,a,b) for(int i=a;i<b;++i)
// #define FORR(i,a,b) for(int i=a;i>=b;--i)
// #define FORC(it,container) for(typeof(container.begin()) it=container.begin();it!=container.end();++it)
// #define INT(x) scanf("%d",&x)
// #define LLD(x) scanf("%lld",&x)
// #define STR(x) scanf("%s",x)
// #define CHAR(x) scanf("%c",&x)
// #define PINT(x) printf("%d\n",x)
// #define PLLD(x) printf("%lld\n",x)
// #define CLR(x) memset(x,0,sizeof(x));
// #define F first
// #define S second
// #define PB push_back

// const int INF = INT_MAX;
// const int MAX = 100000;
// const int MOD = 1e9 + 7;

// typedef long long LL;
// typedef unsigned long long ULL;
// int arr[MAX + 5];

// struct data
// {
// 	LL sumsq;
// 	LL sum;
// 	int lazyset;
// 	int setval;
// 	int addval;

// 	void assignleaf()
// 	{

// 	}
// 	void assignleaf(int idx, int val)
// 	{

// 	}

// 	void combine(data& l, data& r)
// 	{
// 		sumsq = l.sumsq + r.sumsq;
// 		sum = l.sum + r.sum;
// 	}
// };

// data tree[4 * MAX + 5];

// void pushdown(int node, int segs, int sege)
// {
// 	int mid = segs + sege; mid /= 2;

// 	if (tree[node].lazyset == 1)
// 	{
// 		tree[node].lazyset = 0;

// 		tree[2 * node].lazyset = 1;
// 		tree[2 * node + 1].lazyset = 1;

// 		tree[2 * node].setval = tree[node].setval;
// 		tree[2 * node + 1].setval = tree[node].setval;

// 		tree[2 * node].sum = (mid - segs + 1) * tree[node].setval;
// 		tree[2 * node + 1].sum = (sege - mid) * tree[node].setval;

// 		tree[2 * node].addval = 0;
// 		tree[2 * node + 1].addval = 0;

// 		tree[2 * node].sumsq = (mid - segs + 1) * tree[node].setval * tree[node].setval;
// 		tree[2 * node + 1].sumsq = (sege - mid) * tree[node].setval * tree[node].setval;;


// 	}


// 	if (tree[node].addval)
// 	{

// 		tree[2 * node].addval += tree[node].addval;
// 		tree[2 * node + 1].addval += tree[node].addval;

// 		tree[2 * node].sumsq += (mid - segs + 1) * tree[node].addval * tree[node].addval + 2 * tree[node].addval * tree[2 * node].sum;
// 		tree[2 * node + 1].sumsq += (sege - mid) * tree[node].addval * tree[node].addval + 2 * tree[node].addval * tree[2 * node + 1].sum;

// 		tree[2 * node].sum += (mid - segs + 1) * tree[node].addval;
// 		tree[2 * node + 1].sum += (sege - mid) * tree[node].addval;

// 		tree[node].addval = 0;

// 	}


// }

// void build_tree(int node, int s, int e)
// {
// 	tree[node].addval = 0;
// 	tree[node].lazyset = 0;

// 	if (s > e) return;

// 	if (s == e)
// 	{
// 		tree[node].sum = arr[s];
// 		tree[node].sumsq = arr[s] * arr[s];
// 		return;
// 	}

// 	int mid = (s + e) / 2;

// 	build_tree(2 * node, s, mid);
// 	build_tree(2 * node + 1, mid + 1, e);

// 	tree[node].combine(tree[2 * node], tree[2 * node + 1]);

// }

// LL query(int node, int segs, int sege, int qs, int qe)
// {

// 	//cout<<" q -- node = "<<node<<" segs = "<<segs<<" sege = "<<sege<<" qs = "<<qs<<" qe =  "<<qe<<endl;


// 	if (segs > sege || segs > qe || sege < qs)
// 	{
// 		if (tree[node].lazyset || tree[node].addval)
// 			pushdown(node, segs, sege);

// 		return 0;

// 	}

// 	if (tree[node].lazyset || tree[node].addval)
// 		pushdown(node, segs, sege);

// 	if (segs >= qs && sege <= qe)
// 	{

// 		//cout<<"q1 node = "<<node<<" segs = "<<segs<<" sege = "<<sege<<" sumsq  = "<<tree[node].sumsq<<endl;
// 		return tree[node].sumsq;

// 	}

// 	int mid = segs + sege; mid /= 2;


// 	return query(2 * node, segs, mid, qs, qe) + query(2 * node + 1, mid + 1, sege, qs, qe);

// }

// //comm=1
// void update_add(int node, int segs, int sege, int qs, int qe, int x)
// {

// 	//cout<<" ua -  node = "<<node<<" segs = "<<segs<<" sege = "<<sege<<" qs = "<<qs<<" qe =  "<<qe<<" x = "<<x<<endl;


// 	if (segs > sege || segs > qe || sege < qs)	return;

// 	if (segs >= qs && sege <= qe)
// 	{
// 		tree[node].addval += x;
// 		tree[node].sumsq += (LL)(sege - segs + 1) * x * x + (LL)2 * x * (tree[node].sum);
// 		tree[node].sum += (LL)(sege - segs + 1) * x;
// 		return;
// 	}

// 	int mid = segs + sege; mid /= 2;

// 	if (tree[node].lazyset || tree[node].addval)
// 		pushdown(node, segs, sege);

// 	update_add(2 * node, segs, mid, qs, qe, x);
// 	update_add(2 * node + 1, mid + 1, sege, qs, qe, x);

// 	tree[node].combine(tree[2 * node], tree[2 * node + 1]);


// }

// //comm=0
// void update_set(int node, int segs, int sege, int qs, int qe, int x)
// {

// 	//cout<<" node = "<<node<<" segs = "<<segs<<" sege = "<<sege<<" qs = "<<qs<<" qe =  "<<qe<<" x = "<<x<<endl;

// 	if (segs > sege || segs > qe || sege < qs)
// 		return;


// 	if (segs >= qs && sege <= qe)
// 	{
// 		tree[node].lazyset = 1;
// 		tree[node].setval = x;
// 		tree[node].sumsq = (LL)(sege - segs + 1) * x * x;
// 		tree[node].sum = (LL)(sege - segs + 1) * x;
// 		tree[node].addval = 0;
// 		return;
// 	}

// 	if (tree[node].lazyset || tree[node].addval)
// 		pushdown(node, segs, sege);


// 	int mid = segs + sege;
// 	mid /= 2;


// 	update_set(2 * node, segs, mid, qs, qe, x);
// 	update_set(2 * node + 1, mid + 1, sege, qs, qe, x);

// 	tree[node].combine(tree[2 * node], tree[2 * node + 1]);


// }





// int main()
// {

// 	int test; INT(test);

// 	FOR(tt, 1, test + 1)
// 	{
// 		int n, q; INT(n); INT(q);


// 		CLR(arr);
// 		CLR(tree);

// 		FOR(i, 0, n)
// 			INT(arr[i]);

// 		build_tree(1, 0, n - 1);




// 		printf("Case %d:\n", tt);
// 		while (q--)
// 		{

// 			//FOR(i,1,16)
// 			//cout<<" node = "<<i<<" sumsq = "<<tree[i].sumsq<<" sum = "<<tree[i].sum<<" lazyset = "<<tree[i].lazyset<<" addval = "<<tree[i].addval<<" setval = "<<tree[i].setval<<endl;


// 			int comm; int l, r;

// 			INT(comm); INT(l); INT(r);


// 			if (comm == 0)
// 			{
// 				//set x	
// 				int x; INT(x);
// 				update_set(1, 0, n - 1, l - 1, r - 1, x);

// 			}
// 			else if (comm == 1)
// 			{
// 				//add x
// 				int x; INT(x);
// 				update_add(1, 0, n - 1, l - 1, r - 1, x);

// 			}
// 			else if (comm == 2)
// 			{
// 				LL ans = query(1, 0, n - 1, l - 1, r - 1);

// 				PLLD(ans);

// 			}

// 		}

// 	}

// 	return 0;
// }