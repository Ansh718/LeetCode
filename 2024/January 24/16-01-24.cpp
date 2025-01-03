class RandomizedSet
{
public:
    unordered_map<int, int> umP;
    vector<int> values;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (umP.find(val) != umP.end())
        {
            return false;
        }
        umP[val] = values.size();
        values.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (umP.find(val) == umP.end())
        {
            return false;
        }
        int v1 = umP[val];
        int v2 = values.size() - 1;
        swap(values[v1], values[v2]);
        values.pop_back();
        umP[values[v1]] = v1;
        umP.erase(val);
        return true;
    }

    int getRandom()
    {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */