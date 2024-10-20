#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int rows = 3;
    int cols = 3;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for(int i = 0; i<3; i++){
        for(int j =0 ;j < 3;j++){
                std::cin >> matrix[i][j];
        }
    }

    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
