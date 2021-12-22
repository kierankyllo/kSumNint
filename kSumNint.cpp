#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

//describes a backtracking recursive algorithm that attempts to generate valid solutions and backtracks if they are invalid  
void solve(int n, int k, vector<vector<int>> &solution, vector<int> &back) {

    //check if solution is valid and push backtracking vector into solution if it is
    if(n == 0 && k == 0) {

        solution.push_back(back);
    }

    //ckeck if solution is invalid and return if it is
    else if (n == 0 || k == 0 ){

        return;
    }

   //push attempts into backtracking vector and attempt to solve recursively
    for(int i = 0; i <= n; i++) {
        //push i into backtracking vector
        back.push_back(i);

        //recursive step to see if it it valid
        solve(n-i, k-1, solution, back);
        
        //pop i from backtracking vector
        back.pop_back();
    }
}

//describes a funtion to print the 2d vector solution object to terminal and output file
void print(int k, string file, vector<vector<int>> &solution){

    ofstream output;
    output.open (file);

    for(int i = 0; i < solution.size(); i++) {

        for(int j = 0; j < solution[i].size(); j++) {

            output << solution[i][j] << " ";
            cout << solution[i][j] << " ";

            if (j < solution[i].size() - 1){

                output << "+ ";
                cout << "+ ";
            }
            
            if (j == solution[i].size() - 1){
            
                output << "= " << k;
                cout << "= " << k;
            }
        }
        output << '\n';
        cout << '\n';
    }

    //close the output file
    output.close();

}

//describes the main function of the implementation 
int main()
{
    
    //declare and collect initial int variables from user
    int n, k ;
    string name;
    cout << "Declare n : ";
    cin >> n;
    cout << "Declare k : ";
    cin >> k;
    cout << "Declare filename :";
    cin >> name;

    //check that values are non negative
    if (n < 0 || k < 0){

        cout << "Value out of range";
        
        return 0;

    }

    //declare solution vector
    vector<vector<int>> solution;  
    
    //declare backtracking vector
    vector<int> back;

    //solve recursively
    solve(k, n, solution, back);

    //print the solution to terminal and file
    print(k, name, solution);

    return 0 ;
}
