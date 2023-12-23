class Solution {
public:
    
struct S
{
    priority_queue<long long, vector<long long>, greater<long long>> minHeapForPos;
    priority_queue<long long> maxHeapForNeg;
};

vector<vector<int>> adjList;
S solve(int node, vector<int> &cost, vector<long long> &coins, int par)
{
    priority_queue<long long, vector<long long>, greater<long long>> minHeapForPos;
    priority_queue<long long> maxHeapForNeg;

    for (auto child : adjList[node])
    {
        if (child != par)
        {
            auto e = solve(child, cost, coins, node);
            while (e.minHeapForPos.size())
            {
                minHeapForPos.push(e.minHeapForPos.top());
                e.minHeapForPos.pop();
            }

            while (e.maxHeapForNeg.size())
            {
                maxHeapForNeg.push(e.maxHeapForNeg.top());
                e.maxHeapForNeg.pop();
            }
        }
    }
    if (cost[node] > 0)
        minHeapForPos.push(cost[node]);
    else
        maxHeapForNeg.push(cost[node]);

    while (minHeapForPos.size() > 3)
    {
        minHeapForPos.pop();
    }
    while (maxHeapForNeg.size() > 3)
    {
        maxHeapForNeg.pop();
    }

    if (minHeapForPos.size() + maxHeapForNeg.size() < 3)
    {
        coins[node] = 1;
    }
    else
    {
        priority_queue<long long, vector<long long>, greater<long long>> copy1 = minHeapForPos;
        vector<long long> v;
        while (copy1.size())
        {
            v.push_back(copy1.top());
            copy1.pop();
        }

        priority_queue<long long> copy2 = maxHeapForNeg;

        while (copy2.size())
        {
            v.push_back(copy2.top());
            copy2.pop();
        }

        sort(v.begin(), v.end());
        int lastIdx = v.size() - 1;
        long long ans = v[lastIdx] * v[lastIdx - 1] * v[lastIdx - 2];

        ans = max(ans, v[0] * v[1] * v[lastIdx]);

        coins[node] = max(0ll, ans);
    }
    return S{minHeapForPos, maxHeapForNeg};
}

//    If size of the subtree of node i is less than 3, place 1 coin.
// Otherwise, place an amount of coins equal to the maximum product of cost values assigned to 3 distinct nodes in the subtree of node i. If this product is negative, place 0 coins.

vector<long long> placedCoins(vector<vector<int>> &edges, vector<int> &cost)
{
    vector<long long> coins(cost.size(), 1);
    adjList.resize(edges.size() + 1);

    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }

    priority_queue<long long> pq;
    solve(0, cost, coins, 0);

    return coins;
}
};