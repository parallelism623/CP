struct Basis_V1{
    vector<int> a;
    
    void add(int x)
    {
        for (auto it : a)
        {
            x = min(x, x ^ it);
        }
        if (x) a.push_back(x);
    }
    void add(Basis_V1 b)
    {
        for (auto it : b.a)
        {
            add(it);
        }
    }
    
    int isExist(int x)
    {
        for (auto it : a)
        {
            x = min(x, x ^ it);
        }
        return x == 0;
    }
}
