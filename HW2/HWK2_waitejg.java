//ITERATIVE EXTRA CREDIT
/*
Name: Joseph Waite
MacID: waitejg
Student Number: 1403712
Description: naive matrix multiplication in java.  O(n^3)
*/

class HWK2_waitejg {

	public static void main(String[] args){ //main method
		//TODO
		//Take args and make them into matricies

		int matrixA[][]={{50,60,55}
						,{62,65,70}
						,{72,66,77}};

		int matrixB[][]={{50,60,55}
						,{62,65,70}
						,{72,66,77}};

	}

	public static double[][] multi(double matrixA[][], double matrixB[][]) { //multiplication method
		/* 
		//Naive algorithm (from wikipedia)

    	Input: matrices A[n][m] and B[m][p]
   		Let C be a new matrix of [n][p] size
    	For i from 1 to n:
        	For j from 1 to p:
            	For k from 1 to m:
                	Set sum ← sum + A[i][k] × B[k][j]
            Set C[i][j] ← sum
    	Return C
		*/ 

    	int n = matrixA[0].length; //length of first nested element, basically the width
    	int m = matrixB.length; //
    	int p = matrixB[0].length; 

    	if (m != matrixA.length) { //If dimensionons are invalid.
    		throw new Error("Multiplication Error"); 
    	}

		double[][] matrixC = new int[m][p];
		for(int i =0; i < n ; i++){
			for (int j=0; i<n ; j++){
				for(int k=0;k<n;k++){
					matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
				}
			}
		}
		return matrixC
	}

	public static boolean isInvertible(double matrix[][]){

	}

}
