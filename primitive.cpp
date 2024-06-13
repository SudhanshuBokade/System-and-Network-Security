#include<iostream>
#include<unordered_set>
#include<vector>
#include<math.h>
using namespace std  ; 
bool checkPrime(int n)
{
    int i = 2;
    while (i <= n / 2) 
    {
        if (n % i == 0)
            return false;
        else
            i++;
    }
    return true;
}

vector<int> func(int n)
{
    vector<int>vec;
    unordered_set<int>s ;
    int k = 1 ;
    for(int i  = 2 ; i < n ; i  ++)
    {
        for(int j = 1 ; s.size() != n-1 ; j ++)
        {
            int t = pow(i ,j );
            if(s.find(t % n ) == s.end())
            {
                s.insert(t%n);   
            }
            else
            {
                break;
            }
        }
        if(s.size() == n-1)
        {
            vec.push_back(i);
        }
        s.clear();
    }
    return vec ;
}
int main()
{
    int n; 
    cout<<"Enter the number n ";
    cin >> n ; 
    vector<int>vec;
    if(checkPrime(n))
    {
        vec = func(n);
        for(auto i : vec)
        {
            cout<<i<<" ";
        }
    }  
    else
    {
        cout<<"Number is not prime so primitive root not possible";
    }
}