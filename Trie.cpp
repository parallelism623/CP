#include<bits/stdc++.h>
using namespace std;


struct Trie{
    struct Node{
        int cnt, exist;
        int child[26];
        Node(){
            memset(child, -1, sizeof(child));
            cnt = exist = 0;
        }
    };
    int cur;
    vector<Node> node;
    Trie() : cur(0){
        node.push_back(Node());
    }
    int new_node()
    {
        cur++;
        node.push_back(Node());
        return cur;
    }
    void add_string(string &s)
    {
        int pos = 0;
        for (auto it : s)
        {
            int c = it - 'a';
            if (node[pos].child[c] == -1)
            {
                node[pos].child[c] = new_node();
            }
            pos = node[pos].child[c];
            node[pos].cnt++;
        }
        node[pos].exist++;
    }

    bool find_string(string &s)
    {
        int pos = 0;
        for (auto it : s)
        {
            if (node[pos].child[it - 'a'] == -1) return false;
            pos = node[pos].child[it - 'a'];
        }
        return (node[pos].exist != 0);
    }
    bool delete_string_recursive(int pos, string &s, int pos)
    {
        if (i != (int)s.size())
        {
            bool isChildDeleted = delete_string_recursive(node[pos].child[s[i] - 'a'], s, i + 1);
            if (isChildDeleted == true) node[pos].child[c] = -1;
        }
        else
        {
            node[pos].exist--;
        }
        if (pos != 0)
        {
            node[pos].cnt--;
            if (node[pos].cnt == 0) return true;
        }
        return false;
    }
    void delete_string(string &s)
    {
        if (find_string(s) == false) return;
        delete_string_recursive(0, s, 0);
    }
    int cntPrefixSubString (string &s)
    {
        int cnt = 0;
        int pos = 0;
        for (auto it : s)
        {
            int c = it - 'a';
            if (node[pos].child[c] == -1) break;
            pos = node[pos].child[c];
            cnt += node[pos].cnt;
        }
    }
};
