#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;
// vector, index, sum
int returnProd(vector<int> v,int i, int sum){
    int left = 0;
    int right = v.size()-1;
    while(left < right && left + right != sum){
        
        //skip i
        if(left==i){
            left++;
        }else if(right==i){
            right--;
        }

        int temp = v[left]+v[right];
        if(temp>sum){
            right--;
        }else if(temp<sum){
            left++;    
        }else{
            cout << v[left] << " " << v[right] << " " << v[i] << endl;
            return v[left]*v[right]*v[i];
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

    for(int i=0 ; i<v.size(); i++){
        if(int a=returnProd(v,i,2020-v[i])){
            cout << a << endl;
            return 0;
        }
    }
    return 0;
}
