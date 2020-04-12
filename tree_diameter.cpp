int N = 40001;

pair<int, int> bfs(vector<int>vec[], int src){
    queue<int>q;
    int dis[N];
    memset(dis, -1, sizeof(dis));
    q.push(src);
    dis[src] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < vec[u].size(); i++)
        {
            int v = vec[u][i];
            if(dis[v]==-1)
            {
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
    int maxdis = 0;
    int retnode;
    for(int i = 0; i < N; i++){
        if(dis[i] > maxdis){
            maxdis = dis[i];
            retnode = i;
        }
    }
    return make_pair(retnode, maxdis);
}

int Solution::solve(vector<int> &A) {
    if(A.size()==1)return 0;
    vector<int>vec[N];
    for(int i = 0; i < A.size(); i++){
        if(A[i]!=-1){
            vec[i].push_back(A[i]);
            vec[A[i]].push_back(i);
        }
    }
    pair<int, int>p1 = bfs(vec, 0);
    pair<int, int>p2 = bfs(vec, p1.first);
    return p2.second;
}
