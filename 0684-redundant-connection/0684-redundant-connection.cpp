int parent[1001];
int sz[1001];

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}


void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 1; i <= edges.size(); i++)
        make_set(i);
    
        for (int i = 0; i < edges.size(); i++)
        {
            int a = find_set(edges[i][0]);
            int b = find_set(edges[i][1]);

            if (a == b)
                return {edges[i][0], edges[i][1]};
                
            
            //union
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
        return {};
    }
};