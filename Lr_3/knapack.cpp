#include <queue>
#include <iostream>
using namespace std;

struct node
{
    int level;
    int benefit;
    int weight;
    int bound;
    vector<int> nums; //set of items selected
};

double bound(node u, int n, int maxWeight, const vector<int>& c, const vector<int>& w)
{
    if (u.weight >= maxWeight)
        return 0;

    double result = u.benefit;
    int j = u.level;
    int totalWeight = u.weight;
    while ((j < n) && (totalWeight + w[j] <= maxWeight))
    {
        totalWeight += w[j];
        result += c[j];
        j++;
    }
    if (j < n)
    {
        result += (maxWeight - totalWeight) * (double)c[j]/w[j];
    }
    return result;
}

void knapsack(int n, const vector<int>& c, const vector<int>& w, int maxWeight)
{
    queue<node> Q;
    node bestSoFar, v, current, next, nextNo;
    Q.empty();

    for (int i = 0; i < n; i++)
    {
        next.nums.push_back(0);
        nextNo.nums.push_back(0);
    }

    //best so far
    bestSoFar.level = 0;
    bestSoFar.benefit = -1000;
    bestSoFar.weight = 0;
    bestSoFar.bound = 0;
    for (int i = 0; i < n; i++)
        bestSoFar.nums.push_back(0);

    //a_node
    v.level = 0;
    v.benefit = 0;
    v.weight = 0;
    for (int i = 0; i < n; i++)
        v.nums.push_back(0);
    v.bound = bound(v, n, maxWeight, c, w);

    Q.push(v);

    while (!Q.empty())
    {
        //current
        current = Q.front();
        Q.pop();

        if (current.level < n && current.bound > bestSoFar.benefit)
        {
            //create a node nextAdded equal to currNode with the next item added
            next.level = current.level + 1;
            next.benefit = current.benefit + c[next.level - 1];
            next.weight = current.weight + w[next.level - 1];
            for (int i = 0; i < n; i++)
                next.nums[i] = current.nums[i];
            next.nums[next.level - 1] = 1;
            next.bound = bound(next, n, maxWeight, c, w);

            if (next.weight <= maxWeight)
            {
                if (next.benefit > bestSoFar.benefit)
                {
                    //set bestSoFar equal to nextAdded
                    bestSoFar.level = next.level;
                    bestSoFar.weight = next.weight;
                    bestSoFar.benefit = next.benefit;
                    for (int i = 0; i < n; i++)
                        bestSoFar.nums[i] = next.nums[i];
                     bestSoFar.bound = next.bound;
                   // bestSoFar.bound = bound(bestSoFar, n, maxWeight, c, w);
                }

                if (next.bound > bestSoFar.benefit)
                {
                    //enqueue nextAdded
                    Q.push(next);
                }
            }

            //create a node nextNotAdded equal to currNode without the next item added
            nextNo.level = current.level + 1;
            nextNo.weight = current.weight;
            nextNo.benefit = current.benefit;
            for (int i = 0; i < n; i++)
                 nextNo.nums[i] = current.nums[i];

            nextNo.bound = bound(nextNo, n, maxWeight, c, w);

            if (nextNo.bound > bestSoFar.benefit)
            {
                Q.push(nextNo);
            }
        }
    }


   cout << endl << bestSoFar.benefit << endl;
   for (int i = 0; i < n; i++)
   {
       if (bestSoFar.nums[i]==1)
            cout << w[i] << " " << c[i] << endl;
   }
}

int main()
{
    int n, maxWeight, w0, c0;
    vector<int> w, c;

    cin >> n;
    cin >> maxWeight;
    for (int i = 0; i < n; i++)
    {
        cin >> w0;
        w.push_back(w0);
        cin >> c0;
        c.push_back(c0);
    }

    for(int i = 1; i < n; ++i)
        for(int j = 0; j < n-i; j++)
            if((double)c[j]/w[j] < (double)c[j+1]/w[j+1])
            {
                std::swap(c[j], c[j+1]);
                std::swap(w[j], w[j+1]);
            }

    knapsack(n, c, w, maxWeight);
}
