#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
class Solution{
public:
int sum;
    Solution(){
        sum = 0;    
    }
    int satisfies(int lower, int upper, char c, char* s){
        string str(s);

        /** Part 1
        int count = 0;
        for(auto x: str){
            if(x-'a'==c-'a'){
                count++;
            }
        }
        if(count>=lower && count<=upper){
            return 1;
        }
        **/

        //Debug
        //cout << count << " " << lower << " " << upper << " " << c << " " << str << endl;
       
        /* Part 2 */
        int count = 0;
        if(lower-1<str.size() && str[lower-1]==c){
            count++;
        }
        if(upper-1<str.size() && str[upper-1]==c){
            count++;
        }
        if(count==1){return 1;}
        return 0;
    }
    void input(){
        ifstream myfile("aoc-2-input.txt");
        string line;
    
        while(myfile.is_open()){
            while( getline(myfile,line)){
                int lower, upper;
                char c;
                char s[50];
                sscanf(line.c_str(), "%d-%d %c: %s", &lower, &upper, &c, s);
                this->sum += satisfies(lower,upper,c,s);
            }
        myfile.close();
        }
    }
};
int main(){
    Solution sol;
    sol.input();
    cout << sol.sum << endl;
    return 0;
}
