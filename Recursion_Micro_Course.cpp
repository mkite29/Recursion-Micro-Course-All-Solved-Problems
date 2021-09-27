#include<bits/stdc++.h>
using namespace std;

//----------------Lecture 1.----------------------

//Question 1.
// Sum of first N natural numbers.
int sumnatural(int n)
{
	///base case
	if(n==1)
	{
		return 1;
	}

	int subtask1 = sumnatural(n-1);

	return (n + subtask1);
} 

//Question 2.
//Sum of array using recursion.
int asum(vector<int> &arr,int n)
{
	if(n==1)
		return arr[n-1];

	int subtask1 = asum(arr,n-1);
	return arr[n-1] + subtask1;
}

//Question 3.
//Reverse an array recursively
void reverse(vector<int> &arr,int n,int i,int j)
{
	if(n==1)
	{
		return;
	}

	//j-i < 1 because j-i >= 1
	//even cases per swap hi nahi karega
	if(j-i < 1)
	{
		return;
	}

	swap(arr[n-i-1],arr[i]);
	
	reverse(arr,n,i+1,j-1);
}

//Question 5.
//Check whether an array is sorted or not using recursion.
void check(int * arr ,int n)
{
	if(n==1 or n==0)
	{	
		cout<<"Yes\n";
		return;
	}

	if(arr[n-1] < arr[n-2])
	{	
		cout<<"No\n";
		return;
	}

	check(arr, n - 1);

	//return task;

}


//Factorial
int factorial(int n)
{	
	//base case 
	if(n==0 or n==1)
		return 1;

	//recursive assumption
	int subtask = factorial(n-1);

	//self work
	return n * subtask;

}

//Nth fibonacci
int nfib(int n)
{	
	// base case
	if(n == 0)
		return n;
	if(n == 1)
		return n;

	//recursive assumption
	int subtask2 = nfib(n-1);
	int subtask1 = nfib(n-2);

	//self work
	return subtask1 + subtask2;

}

//Print first n natural numbers
int natural(int n)
{
	//base case
	if(n == 1){
		return n;
	}

	//recursive approach
	int subtask = natural(n - 1);
	cout<<subtask<<" ";
	

	//self work
	return n;
	
}

//Print 1 to N increasing
void naturali(int n)
{
	//base case
	if(n == 0)
		return;

	//recursive approach
	naturali(n-1);

	//self work

	cout<<n<<" ";
}

//Print n-1 decreasing.
void naturald(int n)
{
	//base case
	if(n==0)
		return;
	
	//self work
	cout<<n<<" ";

	//recursive approach
	naturald(n-1);
}

//Print decreasing -> increasing
void di(int n)
{
	//base case
	if(n==1){
		cout<<1<<" ";
		return;
	}

	//self work 1 to print in decreasing
	cout<<n<<" ";

	//recursive approach
	di(n-1);

	//self work 2 to print in increasing
	cout<<n<<" ";
	
}


//No of substring such that no consequitive one's 
//Fibonacci Approach.
int noconsequitive1(int n)
{
	if(n==1)
		return 2;
	if(n==2)
		return 3;

	int subtask1 = noconsequitive1(n-1);
	int subtask2 = noconsequitive1(n-2);

	return subtask1 + subtask2;
}

//----------------Lecture 2.----------------------
//Question 1.
//N persons
//Either someone go alone in party or in a pair
//Find the no of ways N persons go to party.
int ways(int n)
{	
	//base case
	if(n==1)
	{
		return 1;
	}

	if(n==2)
	{
		return 2;
	}

	//Resursive approach
	int subtask1 = ways(n-1);
	int subtask2 = ways(n-2);

	//self work 
	return subtask1 + (n-1)*subtask2;
} 

//Question 2.
//Print  the Pattern
//***
//**
//*
void print2(int n ,int i)
{	
	//base case
	if(n == 1)
	{	cout<<"*";
		return;
	}

	//self work + recursion
	if(i <= n)
	{	
		cout<<"*";
		print2(n,i+1);
	}
	else
	{
		cout<<endl;
		print2(n-1 , 1);
	}
}




//Question 3.
//Print all the subsets of an array.

//unordered_map<string,int> ump;
vector <string> ans;

void printsubset(int *arr , int i ,int n , string osf)
{	/*osf output so far*/	
	//base case.
	if(i == n)
	{	
		//cout<<"["<<osf<<"]"<<endl;
		//ump["["+osf+"]"]++;
		ans.push_back(osf);
		return;
	}

	//when we include.
	printsubset(arr,i+1,n,osf + to_string(arr[i])+"");
	
	//when we do not include
	printsubset(arr,i+1,n,osf);
}

//Question 4.
//Print Pattern
//*
//**
//***
void print3(int n , int i)
{
	//base
	if( n == 1)
	{
		cout<<"*";
		return;
	}

	if(i < n)
	{
	print3(n,i+1);
	cout<<"*";	
	}

	else{
		print3(n-1,0);
		cout<<endl;
	}

}



//Question 5.
//Print the number of binary strings 
//with no consequitive ones
void print5(int k, char osf[],int n)
{
	if( n == k )
	{	
		osf[n] = '\0';
		cout<<osf<<endl;
		return;
	}

	if(osf[n-1] == '1')
	{
		osf[n] = '0';
		print5(k,osf,n+1);
	}

	if(osf[n-1] == '0')
	{
		osf[n] = '0';
		print5(k,osf,n+1);

		osf[n] = '1';
		print5(k,osf,n+1);
	}

}
void generate(int k)
{
	if(k <= 0)
		return;

	
	char ans1[k] = "0";
	print5(k,ans1,1);

	
	char ans2[k] = "1";
	print5(k,ans2,1);

}

//----------------Lecture 3------------------
//Question 1
//Given N*M Grid you are at (0,0) and want to go
//(n-1 , m-1) and can go either right or down at a time
//Print all possible paths When
//1.Diagonally move allowed.
//2.Diagonally not allowed. 

int totalpaths = 0;
void gridpath(int i,int j,int n,int m,string osf)
{
	//base case
	//1. when we reach the destination
	if(i == n-1 and j == m-1)
	{
		totalpaths++;
		cout<<osf<<endl;
		return;
	}

	//2. when we go out of column or row in grid
	if(i >= n or j>= m)
	{
		return;
	}

	
	gridpath(i+1,j,n,m,osf + "D");
	gridpath(i,j+1,n,m,osf + "R");

	//when we also move diagonally
	gridpath(i+1,j+1,n,m,osf + "X");
}

//Question 2
//There are N cells linearly arranged you are standing 
//at ith cell and want to reach n-1th cell Print all
//the possible paths if you can jumps atmost 6 at a time.
void linearpath(int n ,int i , string osf)
{
	//base
	if(i >= n)
	{
		return;
	}

	if(i == n-1)
	{
		cout<<osf<<endl;
		return;
	}

	//for every j jumps how can we reach at n	
	for(int j = 1;j<=6;j++)
	linearpath(n , i+j , osf + to_string(j) + " ");

}

//Questions 3.
//Given N print the first (n+1) whole number
//in lexiographically order.
void lexico(int n ,int i)
{
	//base case
	if(i > n)
	{
		return;
	}

	cout<<i<<endl;

	// **very important part**
	//at first call for 0 we have 9 calls only 
	//from 1 to 9 otherwise there will  be 10 calls.

	for(int j = (i==0) ? 1 : 0 ;j<=9 ;j++)
	{
		lexico(n,10*i+j);
	}	
}



//Question 5.
//Print all the permutation of a string.
//1.When repetition Allowed.
//2.When repetition not Allowed.

void permutation(string str , string permu)
{
	//base case
	if(str.size() == 0)
	{
		cout<<permu<<endl;
		return;
	}

	unordered_set<char> s;

	for(int i = 0 ;i<str.size();i++)
	{
		char ch = str[i];
		if(s.count(ch) == 0){
			s.insert(ch);
			string ros = str.substr(0,i) + str.substr(i+1);
			permutation(ros,permu+ch);
		}
	}

}

//---------------------Backtracking-----------------------
//Lecture 1.
//Question 1.
//When we generating permutation of string then we generate new string
//every time and the substr function is costly.

void permute(string str , int j)
{	
	//base
	if(str.size() == j + 1)
	{
		cout<<str<<endl;
		return;
	}

	for(int i = j ;i<str.size();i++)
	{	
		//swap so that our original string does not get changed
		swap(str[i] , str[j]);
		permute(str,j+1);
		swap(str[i] , str[j]);
		//swap so that our original string does not get changed
	}

}

//Question 2.
//Rate in a maze of nXn and some cells are blocked
//rate is at (0,0) and want to reach (n,n)
//find the total paths to get there

int totalpath = 0;
bool  issafe(int i,int j,int n,vector<vector<bool>> &visited)
{
	return i>=0 and j>=0 and i < n and j < n and visited[i][j]==false;
}

void helper(int i,int j,int n,vector<vector<int> > &grid , vector<vector<bool>> visited)
{
	if(i == n-1 and j == n-1)
	{
		totalpath++;
		return;
	}

	if(!issafe(i,j,n,visited))
	{
		return;
	}

	visited[i][j] = true;

	if(i+1 < n and grid[i+1][j]==0)
	{
		helper(i+1,j,n,grid,visited);
	}
	if( i-1 >= 0 and grid[i-1][j]==0)
	{
		helper(i-1,j,n,grid,visited);
	}
	if(j+1 < n and grid[i][j+1]==0)
	{
		helper(i,j+1,n,grid,visited);
	}
	if(j-1 >= 0 and grid[i][j-1]==0)
	{
		helper(i,j-1,n,grid,visited);
	}

	visited[i][j] = false;

	return;
}

int countRatmazepaths(vector<vector<int>>&grid)
{
	int n=grid.size();
	vector<vector<bool>> visited(n,vector<bool> ( n , false));
	helper(0,0,n,grid,visited);
	return totalpath;
}

//Question 4.
//Generating subsets from backtracking.

void subsetBacktrack(int *arr , vector<int> &temp,int i,int n)
{
	if(i==n)
	{
		for(int i = 0;i<temp.size();i++)
		{
			cout<<temp[i]<<" ";
		}
		cout<<endl;
		return;
	}

	temp.push_back(arr[i]);
	subsetBacktrack(arr,temp,i+1,n);
	temp.pop_back();
	subsetBacktrack(arr,temp,i+1,n);
}

//-----------------Lecture 2--------------------
//Question 1. 
//Given N Queens and nXn chess board find the total no of ways
//to place all n queens suh that no one queen attack each other.

int totalQueenPaths = 0;
bool isItSafe(vector<vector<bool>> &grid ,int row , int col,int n)
{
	//column check
	for(int i = row-1;i>=0;i--)
	{
		if(grid[i][col] == true) return false;
		
	}

	//Left upper diagonal
	for(int i = row-1,j=col-1;i>=0 and j>=0;i--,j--)
	{
		if(grid[i][j]) return false;
	
	}

	//right upper diagonal
	for(int i=row-1, j=col+1;i>=0 and j < n; i--,j++)
	{
		if(grid[i][j]) return false;
	}

	return true;
}	

void display(vector <vector<bool> > &grid , int n)
{
	for(int i = 0 ;i < n ;i++)
	{
		for(int j = 0 ;j < n ;j++)
		{
			if(grid[i][j])
			{
				cout<<"Q ";
			}
			else
			{
				cout<<". ";
			}
		}
		cout<<endl;
	}
}
void countQueens(vector<vector<bool>> &grid ,int cur_row ,int n)
{	
	//base case when we get a valid path
	if(cur_row == n)
	{
		totalQueenPaths++;
		display(grid,n);
		cout<<endl<<endl;
		return;
	}

	//backtracking
	for(int i = 0 ; i < n; i++)
	{
		if(isItSafe(grid,cur_row,i,n))
		{
			grid[cur_row][i] = true;//initialisation
			countQueens(grid,cur_row+1,n);
			grid[cur_row][i] = false;//reinitialisation
		}
	}
}
//Question 2.
// Given NxN board with a knight placed at (0,0).Check
//if the knight can cover all the cells of the board
//using  it's moves without visiting any cell twice.

int totalknightToursPaths = 0;

bool isItSafe2(vector<vector<int>>&grid,int n,int i,int j,vector<vector<bool>>&visited)
{
	return i>=0 and j>=0 and i < n and j < n and visited[i][j] == false;
}

void display(vector<vector<int>> &grid,int n)
{
	for(int i = 0 ;i < n ;i++)
	{
		for(int j = 0 ;j < n ;j++)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}

void knightsTour(vector<vector<int>>&grid,int n,int i,int j,int count,vector<vector<bool>> visited)
{
	//base case
	if(count == (n*n - 1))
	{	
		totalknightToursPaths++;
		grid[i][j] = count;
		display(grid,n);
		cout<<endl<<endl;
		return;
	}

	//when out of grid.
	if(count >= n*n)
	{
		return;
	}

	int xdir[8] = {-2,-2,-1,-1,2,2,1,1};
	int ydir[8] = {1,-1,2,-2,1,-1,2,-2};

	visited[i][j] = true;
	grid[i][j] = count;

	for(int k = 0;k<8;k++)
	{
		if(isItSafe2(grid,n,i+xdir[k],j+ydir[k],visited)){
			
			knightsTour(grid,n,i+xdir[k],j+ydir[k],count+1,visited); 
		}
	}
	grid[i][j] = -1;
	visited[i][j] = false;
}

//--------------------------Lecture 3.--------------------
//N Queen Problem ko space and time optimised banaya hai.

//T.C  = O(n) and S.C = O(n).
void displayIt(vector <vector<bool> > &grid , int n)
{
	for(int i = 0 ;i < n ;i++)
	{
		for(int j = 0 ;j < n ;j++)
		{
			if(grid[i][j])
			{
				cout<<"Q ";
			}
			else
			{
				cout<<". ";
			}
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}	

bitset<100> col , ld , rd; /* ld -> left diagonal rd -> right diagonal */
int total = 0;
void nqueen(vector<vector<bool>> &grid,int n , int cr)
{
	if(cr == n){
		displayIt(grid,n);
		total++;
		return;
	}

	for(int c = 0 ;c < n ;c++){
		if(!col[c] and !ld[cr-c+n-1] and !rd[cr+c]){

			col[c] = ld[cr-c+n-1] = rd[cr+c] = grid[cr][c] = 1;
			nqueen(grid,n,cr+1);
			col[c] = ld[cr-c+n-1] = rd[cr+c] = grid[cr][c] = 0;

		}
	}
}

//Question 2.
//Given nXn board place n knights such that no one attack each other
void displaynKnights(vector<vector<bool>>&grid,int n){
	for(int i =0;i<n;i++){
		for(int j = 0;j<n;j++)
		{
			if(grid[i][j])
			{
				cout<<"K ";
			}
			else
			{
				cout<<". ";
			}
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

bool isKnightSafe(int r,int c,vector<vector<bool>>&grid,int n)
{
	if(r-2>=0 and c-1>=0 and grid[r-2][c-1])
		return false;
	if(r-1>=0 and c-2>=0 and grid[r-1][c-2])
		return false;
	if(r-2>=0 and c+1>=0 and grid[r-2][c+1])
		return false;
	if(r-1>=0 and c+2>=0 and grid[r-1][c+2])
		return false;

return true;	
}

int totalKnights = 0;
void nKnights(int n,vector<vector<bool>>&grid,int cr,int cc,int count)
{
	if(count == n)//count lena padega base case mei 
	{			 //bcz all n knights can be placed in a row. 
		totalKnights++;
		displaynKnights(grid,n);
		return;
	}
	for(int i=cr;i<n;i++)
	{	//ye condition ager current row mei hai to column + 1
		//cross chale gaye to 0 agli row ke liye.
		for(int j=(i==cr)?cc:0;j<n;j++)
		{	
			//backtrack
			if(isKnightSafe(i,j,grid,n)){
				grid[i][j] = true;	//initialize
				nKnights(n,grid,i,j+1,count+1);
				grid[i][j] = false;	//reinitialize.

			}
		}
	}

}

//Question 4.
//Given mXn or nXn grid of characters find whether a word can be made from 
//the characters present in the grid if
//1. moving in all 8 direction is allowed
//2.moving only left,right,up down allowed
bool findmatch(vector<vector<char>> &mat, string pat, int x, int y,int nrow, int ncol, int level)
{
    // Pattern matched
    if (level == pat.length())
        return true;
 
    // Out of Boundary
    if (x < 0 || y < 0 || x >= nrow || y >= ncol)
        return false;
 
    if (mat[x][y] == pat[level]) {
 
        // Marking this cell as visited
        char temp = mat[x][y];
        mat[x][y] = '#';
 
        // finding subpattern in 8 directions
        bool res = findmatch(mat, pat, x - 1, y, nrow, ncol, level + 1) |
                   findmatch(mat, pat, x + 1, y, nrow, ncol, level + 1) |
                   findmatch(mat, pat, x, y - 1, nrow, ncol, level + 1) |
                   findmatch(mat, pat, x, y + 1, nrow, ncol, level + 1) |
                   findmatch(mat, pat, x-1, y - 1, nrow, ncol, level + 1)|
                   findmatch(mat, pat, x+1, y - 1, nrow, ncol, level + 1)|
                   findmatch(mat, pat, x-1, y + 1, nrow, ncol, level + 1)|
                   findmatch(mat, pat, x+1, y + 1, nrow, ncol, level + 1);
 
        // marking this cell as unvisited again
        mat[x][y] = temp;
        return res;
    }

    else 				// Not matching then false
        return false;
}

// Function to check if the word exists in the grid or not
bool checkMatch(vector<vector<char>> &mat, string pat, int nrow, int ncol)
{
 
    int l = pat.length();
 
    
    if (l > nrow * ncol) //ager pattern grid se bada hua to 
        return false;
 
    // Traverse in the grid
    for (int i = 0; i < nrow; i++) {
        for (int j = 0; j < ncol; j++) {
 
            // If first letter matches, then recur and check
            if (mat[i][j] == pat[0])
                if (findmatch(mat, pat, i, j, nrow, ncol, 0))
                    return true;
        }
    }
    return false;
}

int main()
{	
	int n,m;
	cin>>m>>n;
	
	vector<vector<char>> grid(m,vector<char>(n));

	for(int i = 0;i<m;i++){
		for(int j = 0 ;j<n;j++){
			cin>>grid[i][j];
		}
	}
	//cout<<checkMatch(grid,"ABCESD",m,n);

	//lexico(13,0);
	// int n;
	// cin>>n;
	// vector<vector<bool>> grid(n , vector<bool> (n,false));
	// nKnights(n,grid,0,0,0);
	// cout<<totalKnights;
	// int n;
	// cin>>n;
	// vector<vector<bool>> grid(n , vector<bool> (n,false));
	// nqueen(grid,n,0);
	// cout<<total;
	// vector<vector<int>> grid(n,vector<int>(n,-1));
	// vector<vector<bool>> visited(n,vector<bool>(n,false));
	// knightsTour(grid,n,0,0,0,visited);
	// cout<<totalknightToursPaths<<endl;

	// vector<vector<bool>> grid(n,vector<bool>(n,false));
	// countQueens(grid,0,n);
	// cout<<totalQueenPaths;
	
	// for(int i = 0;i<n;i++)
	// {
	// 	for(int j = 0;j<n;j++)
	// 	{
	// 		cin>>grid[i][j];
	// 	}
	// }
	//cout<<countRatmazepaths(grid);

	// // int n;cin>>n;
	// int *arr = new int[n];

	// for(int i = 0;i<n;i++)
	// {
	// 	cin>>arr[i];
	// }
	// vector <int> temp;
	// subsetBacktrack(arr, temp,0,n);
	return 0;
}






 