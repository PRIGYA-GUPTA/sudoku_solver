#include <iostream>
using namespace std;
#define N 9
#include <set>


int valid_row(int row, int grid[][9]){
  set<int> s;
  for(int i = 0; i < 9; i++){

    if(grid[row][i] < 0 || grid[row][i] > 9){
      cout<<"Invalid value"<<endl;
      return -1;
    }
    else
    { //Checking for repeated values.
      if(grid[row][i] != 0){
        if(s.insert(grid[row][i]).second == false){
          return 0;
        }
      }
    }
  }
  return 1;
}

int valid_col(int col, int grid[][9]){
  set<int> s;
  for(int i = 0; i < 9; i++){

    if(grid[i][col] < 0 || grid[i][col] > 9){
      cout<<"Invalid value"<<endl;
      return -1;
    }
    else
    { // Checking for repeated values.
      if(grid[i][col] != 0){
        if(s.insert(grid[i][col]).second == false){
          return 0;
        }
      }
    }
  }
  return 1;
}

int valid_subsquares(int grid [][9]){
  for(int row = 0; row < 9; row = row + 3){
    for(int col = 0; col < 9; col = col + 3){
        set<int> s;
        for(int r = row; r < row + 3; r++){
          for(int c = col; c < col + 3; c++){

            if(grid[r][c] < 0 || grid[r][c] > 9){
              cout<<"Invalid value"<<endl;
              return -1;
            }
            else{
              // Checking for repeated values
              if(grid[r][c] != 0){
                if(s.insert(grid[r][c]).second == false){
                  return 0;
                }
              }
            }
          }
        }
    }
  }
  return 1;
}
//Function to check if the board invalid.
void valid_board(int grid [][9]){
  for(int i = 0; i < 9; i++){
    int res1 = valid_row(i, grid);
    int res2 = valid_col(i, grid);
    // If a row or a column is invalid, then the board is invalid.
    if(res1 < 1 || res2 < 1){
      cout<<"The board is invalid"<<endl;

      return ;
    }
  }
  // if any one the subsquares is invalid, then the board is invalid.
  int res3 = valid_subsquares(grid);
  if(res3 < 1){
    cout<<"The board is invalid"<<endl;

    return ;
  }
  else{
    cout<<"The board is valid"<<endl;

  }
}
// Function to print the board.
void print_board(int grid[] [9]){
  for( int row = 0; row < 9; row++){
    cout<<"[";
    for(int col = 0; col < 9; col++){
      cout<<grid[row][col]<<", ";
    }
    cout<<"]"<<endl;
  }
}

bool isSafe(int grid[N][N], int row,
     int col, int num)
{


 for (int x = 0; x <= 8; x++)
  if (grid[row][x] == num)
   return false;


 for (int x = 0; x <= 8; x++)
  if (grid[x][col] == num)
   return false;

 int startRow = row - row % 3,
   startCol = col - col % 3;

 for (int i = 0; i < 3; i++)
  for (int j = 0; j < 3; j++)
   if (grid[i + startRow][j +
       startCol] == num)
    return false;

 return true;
}


bool solveSudoku(int grid[N][N], int row, int col)
{

 if (row == N - 1 && col == N)
  return true;


 if (col == N) {
  row++;
  col = 0;
 }
 if (grid[row][col] > 0)
  return solveSudoku(grid, row, col + 1);

 for (int num = 1; num <= N; num++)
 {

  if (isSafe(grid, row, col, num))
  {


   grid[row][col] = num;


   if (solveSudoku(grid, row, col + 1))
    return true;
  }


  grid[row][col] = 0;
 }
 return false;
}


int main()

{



 cout<<"Welcome to sudoku solver"<<endl;
 cout<<"INSERT YOUR SUDOKU TO GET THE SOLUTION"<<endl;

 int grid[N][N];
 for(int i=0;i<N;i++)
 {
     for(int j=0;j<N;j++)
     {

         cin>>grid[i][j];
     }
 }
 cout<<endl;

 print_board(grid);
 valid_board(grid);
 if (valid_board)
 {


 if (solveSudoku(grid, 0, 0))
 { cout<<"Here's your solution"<<endl;
      print_board(grid);
 }
 }



 return 0;

}

