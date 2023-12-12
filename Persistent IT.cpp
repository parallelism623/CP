struct Node{
    int ln, left, right;
    Node(){}
    Node(int ln, int left, int right): ln(ln), left(left), right(right){}
} it[10000011];

const int N = 1e5 + 10;
int nNode;
int ver[N];
int Function(int a, int b)
void Merge(int id)
{
    it[id].ln = Function(it[it[id].left].ln, it[it[id].right].ln);
}
int update(int l, int r, int u, int x, int oldID)
{
    if (l == r)
    {
        ++nNode;
        it[nNode] = Node(x, 0, 0);
        return nNode;
    }
    int mid = l + r >> 1;
    int cur = ++nNode;
    if (u <= mid)
    {
        it[cur].left = update(l, mid, u, x, it[oldID].left);
        it[cur].right = it[oldID].right;
        Merge(cur);
    }
    else
    {
        it[cur].left = it[oldID].left;
        it[cur].right = update(mid + 1, r, u, x, it[oldID].right);
        Merge(cur);
    }
    return cur;
}
