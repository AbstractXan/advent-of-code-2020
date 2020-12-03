#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;
int returnProd(vector<int> v){
    int sum = 2020;
    int left = 0;
    int right = v.size()-1;
    while(left < right && left + right != sum){
        int temp = v[left]+v[right];
        if(temp>sum){
            right--;
        }else if(temp<sum){
            left++;    
        }else{
            cout << v[left] << " " << v[right] << endl;
            return v[left]*v[right];
        }
    }
    return 0;
}
int main(){
    // inputs
    ifstream myfile("aoc-1-input.txt");
    vector<int> v;
    if (myfile.is_open())
    {
        string line;
        while ( getline (myfile,line) )
        {
           v.push_back(atoi(line.c_str()));
        }
    }
    myfile.close();
    sort(v.begin(),v.end());
    cout << returnProd(v) << endl;
}
