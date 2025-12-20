Problem Link: https://www.codingninjas.com/studio/problems/valid-sudoku_8230704?challengeSlug=striver-sde-challenge&leftPanelTab=0 

bool isPossible(int mat[9][9], int val, int row, int col) {
    for (int i=0; i<9; i++) {
        if (mat[i][col] == val) return false;

        if (mat[row][i] == val) return false;

        if (mat[3*(row/3)+i/3][3*(col/3)+i%3] == val) return false;
    }
    return true;
    
}



bool isItSudoku(int matrix[9][9]) {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (matrix[i][j] == 0) {
                for (int val=1; val<10; val++) {
                    if (isPossible(matrix, val, i, j)) {
                        matrix[i][j] = val;
                        if (isItSudoku(matrix)) return true;
                        matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    } 
    return true;
}
