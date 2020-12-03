#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
void input(vector< vector<int> > &m, string fileName){
    ifstream myFile(fileName);
    while(myFile.is_open()){
        string line;
        while( getline(myFile,line) ){
            
            // row ; default 0
            vector<int> temp(line.size(),0);
            // populate row with 1
            for(int i=0; i<line.size() ; i++){
                if(line[i]=='#'){
                    temp[i]=1;
                }
            }

            // update
            m.push_back(temp);
        }
        myFile.close();
    }
}

// right down
int traverseXY(vector< vector<int> > m, int right, int down){
    int x=0;
    int y=0;
    int count=0;
    while(y<m.size()){
        // reset x if overflow
        if(x >= m[0].size()){x%=m[0].size();}
        //count
        if(m[y][x]==1){ count++;} 
        
        x+=right; y+=down;
    }
    return count;
}
int main(){
    // map
    vector< vector<int> > m; 
    input(m, "aoc-3-input.txt");
    vector< pair<int,int> > input = {
        make_pair(1,1),
        make_pair(3,1),
        make_pair(5,1),
        make_pair(7,1),
        make_pair(1,2),
    };
    long long int prod = 1;
    for(auto p : input){
        prod*=traverseXY(m,p.first,p.second); 
    }
    cout << prod << endl;
    return 0;
}
