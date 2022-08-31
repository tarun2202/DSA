#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> ans;
void printPath(vector<vector<int> >& mat, vector<pair<int,int> >&path, int i, int j){
	//poisonous cell entered
	if(mat[i][j]==1)
		return;
	if(i==j && j==mat.size()-1){
        path.push_back({i,j});
		ans.push_back(path);
        path.pop_back();
		return;	
	}
	path.push_back({i,j});
	//when reached the last row
	if(i==mat.size()-1)
		printPath(mat,path,i,j+1);
	//when reached the last column	
	else if(j==mat.size()-1)
		printPath(mat,path,i+1,j);
	//when in between the maze, and can move either right or down	
	else{
		printPath(mat,path,i,j+1);
		printPath(mat,path,i+1,j);
	}
	//backtracking
	path.pop_back();
}
int main(){
	vector<vector<int> > matrix{{0,0,1,1},{0,0,1,0},{1,0,1,1},{0,0,0,0}};
    vector<pair<int,int>> path;
    printPath(matrix,path,0,0);
    for (auto i : ans) {
        for (auto cell : i) 
			cout << "(" << cell.first << ", " << cell.second << ")\t";
        cout << endl;
    }
}
