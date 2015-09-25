//ITERATIVE EXTRA CREDIT
/*
Name: Joseph Waite
MacID: waitejg
Student Number: 1403712
Description: naive matrix multiplication in java.  O(n^3)
*/

import java.util.Arrays;


class HWK2_waitejg {

	public static void main(String[] args){ //main method
		//TODO
		//Take args and make them into matricies
		//TEST CASES?? 


		double matrixA[][] = {{50,60,55}
							,{62,65,70}
						    ,{72,66,77}};

		double matrixB[][] = {{50,60,55}
							,{62,65,70}
							,{72,66,77}};
		double ans[][]=  multi(matrixA, matrixB);
		System.out.println(Arrays.deepToString(ans));



	}

	public static double[][] multi(double matrixA[][], double matrixB[][]) { //multiplication method
		/* 
		//Naive matrix multiplication algorithm (from wikipedia)

    	Input: matrices A[n][m] and B[m][p]
   		Let C be a new matrix of [n][p] size
    	For i from 1 to n:
        	For j from 1 to p:
            	For k from 1 to m:
                	Set sum ← sum + A[i][k] × B[k][j]
            Set C[i][j] ← sum
    	Return C
		*/ 
    	System.out.println(Arrays.deepToString(matrixA));
    	System.out.println(Arrays.deepToString(matrixB));
    	int n = matrixA[0].length; //length of first nested element, basically the width
    	int m = matrixB.length; //
    	int p = matrixB[0].length; //
    	System.out.println(n + " " + m + " " + p);
    	if (m != matrixA.length) { //If dimensionons are invalid.
    		throw new Error("Multiplication Error"); 
    	}

		double[][] matrixC = new double[m][p];
		for(int i =0; i < m; i++){
			for (int j=0; j < p; j++){
				for(int k=0; k < n; k++){
					System.out.println("i: " + i + " j: " + j + " k: " + k);
					matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
				}
			}
		}
		return matrixC;
	}

	public static boolean isInvertible(double matrix[][]){
		// is is square? 
		// non square matricies do not have an inverse
		// 
		return true ;
	}

	public static double[][] inverse(double matrix[][]){ 
		// fuck this is hard
		// LU Decomposition
		// http://www.econ.umn.edu/undergrad/math/An%20Algorithm%20for%20Finding%20the%20Inverse.pdf
		// fuck
		return matrix;
	}

}
