#include <iostream>
#include <fstream>
#include <vector>

#define inf 1000

std::vector<std::vector<int> > readData()
{
    std::ifstream input("in.txt");
    std::vector<std::vector<int> > a;
    int n, m;
    input >> n;
    input >> m;    
    a.push_back(std::vector<int> (m + 1, 1));
    for (int i = 1; i <= n; i++)
    {
        a.push_back(std::vector<int>());
        for (int j = 0; j < m; j++)
        {
            int temp;
            input >> temp;
            a[i].push_back(temp);
        }
        a[i].push_back(1);
    }
    input.close();
    return a;
}

int cost(int k, int mask, bool save, int &size_, std::vector<int> &list_, std::vector<std::vector<int> > a)
{
    int start, count_;
    if (save)
    {
        list_ = std::vector<int> (list_.size(), 0);
        size_ = 0;
    }
    count_ = 0;
    start = -1;
    for (int i = 0; i < a[0].size(); i++)
    {
        if ((start != -1) && ((a[k][i] == 1) || ((mask & 1) != 0)))
        {
            if (list_[start] == (i - start))
                count_++;
            if (save)
            {
                list_[start] = (i - start);
                size_++;
            }
            start = -1;
        }
        if ((mask & 1) != 0)
            start = i;
        if ((a[k][i] == 1) && ((mask & 1) != 0)) 
            return inf;
        if ((a[k][i] == 0) && (start == -1))
            return inf;
        mask = (mask >> 1);
    }
    return (size_ - count_);
}

void solve(std::vector<std::vector<int> > a)
{
	int l = 1 << (a[0].size() - 1);
    int res = 0;
    std::vector<std::vector<int> > f(a.size(), std::vector<int> (l, 0));
    int size_ = 0;
    std::vector<int> list_(a[0].size() - 1, 0);
    f[0][0] = 0;
    for (size_t i = 1; i < a.size(); i++)
        for (size_t mask = 0; mask < l; mask++)
        {
            f[i][mask] = inf;
            if ( cost(i, mask, true, size_, list_, a) == inf)
                continue;
            for (int prev = 0; prev < l; prev++)
            {
                f[i][mask] = std::min(f[i][mask], f[i-1][prev] + cost(i - 1, prev, false, size_, list_, a));               
			}
        }
    res = inf;
    for (int mask = 0; mask < l; mask++)
        res = std::min(res, f[a.size() - 1][mask]);
    std::cout << res << "\n";
}

void print(std::vector<std::vector<int> > a) {
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
            std::cout << a[i][j] << " ";
        std::cout <<std::endl;
    }
}

int main()
{
    std::vector<std::vector<int> > a;
    a = readData();
    print(a);
    solve(a);
    return 0;
}
