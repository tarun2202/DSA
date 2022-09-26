//Radix Sort: 

#include <bits/stdc++.h>
using namespace std;
int find(vector<int> &a){
    int i;
    int n = a.size();
    int maxi = 0;
    for (i = 0; i < n; i++)
        maxi = max(maxi, a[i]);
    return maxi;
}
void solve(vector<int> &v)
{
    int maxi = find(v);
    int factor = 1;
    vector<int> ans(v.size(), 0);
    while (maxi != 0)
    {
        vector<int> fre(10, 0);
        for (int i = 0; i < v.size(); i++){
            int temp = v[i];
            temp = temp / factor;
            int digit = temp % 10;
            fre[digit]++;
        }
        for (int i = 1; i < fre.size(); i++)
            fre[i] += fre[i - 1];
        for (int i = v.size() - 1; i >= 0; i--){
            int temp = v[i];
            temp = temp / factor;
            int digit = temp % 10;
            int index = fre[digit];
            ans[index - 1] = v[i];
            fre[digit]--;
        }
        for (int i = 0; i < ans.size(); i++)
            v[i] = ans[i];
        factor *= 10;
        maxi = maxi / 10;
    }
    for (int i = 0; i < ans.size(); i++)
        v[i] = ans[i];
    return;
}
int main(){
    int n;
    cin >> n;
    int i, j;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    vector<int> positive;
    vector<int> negative;
    for (i = 0; i < n; i++){
        if (a[i] >= 0)
            positive.push_back(a[i]);
        else
            negative.push_back(a[i] * -1);
    }
    solve(positive);
    solve(negative);
    reverse(negative.begin(), negative.end());
    for (i = 0; i < negative.size(); i++){
        negative[i] *= -1;
        a[i] = negative[i];
    }
    for (j = 0; j < positive.size(); j++){
        a[i] = positive[j];
        i++;
    }
    for (int i=0;i<a.size();i++)
        cout << a[i]<< " ";
}
