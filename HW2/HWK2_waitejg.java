//ITERATIVE EXTRA CREDIT WITH LU DECOMPOSITION + BACKSUBTITUTION 
/*
 Name: Joseph Waite
 MacID: waitejg
 Student Number: 1403712
 Description: take matricies in from args, multiply them together, then return the inverse
 */

import java.util.Arrays;

class HWK2_waitejg {

	public static void main(String[] args) { // main method
		// TODO
		// Take args and make them into matricies
		// TEST CASES??

		double matrixA[][] = {{1,2},{2,2}};

		double matrixB[][] = {{50,60,55},{62,65,70},{72,66,77}};
		// double ans[][]= multi(matrixA, matrixB);
		LU_Decomp(matrixB);
	}

	public static double[][] multi(double matrixA[][], double matrixB[][]) { // multiplication
																				// method
		/*
		 * //Naive matrix multiplication algorithm
		 * 
		 * Input: matrices A[n][m] and B[m][p] Let C be a new matrix of [n][p]
		 * size For i from 1 to n: For j from 1 to p: For k from 1 to m: Set sum
		 * ← sum + A[i][k] × B[k][j] Set C[i][j] ← sum Return C
		 */
		System.out.println(Arrays.deepToString(matrixA));
		System.out.println(Arrays.deepToString(matrixB));

		int n = matrixA[0].length; // get column dimension
		int m = matrixB.length; // get row dimensiom
		int p = matrixB[0].length; // get column dimension

		System.out.println(n + " " + m + " " + p);

		if (m != matrixA.length) { // If dimensionons are invalid.
			throw new Error("Multiplication Error");
		}

		double[][] matrixC = new double[m][p];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < p; j++) {
				for (int k = 0; k < n; k++) {
					System.out.println("i: " + i + " j: " + j + " k: " + k);
					matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
				}
			}
		}
		return matrixC;
	}

	public static boolean isInvertible(double matrix[][]) {
		// is is square?
		// We could through some other checks in here.
		// non square matricies do not have an inverse
		//
		return true;
	}

	public static void LU_Decomp(double matrixA[][]) {
		// http://www.gamedev.net/page/resources/_/technical/math-and-physics/matrix-inversion-using-lu-decomposition-r3637
		int n = matrixA[0].length;
		double[][] lower = new double[n][n];
		double[][] upper = new double[n][n];

		for (int i = 0; i < n; i++) { // Identity matrix, get money
			upper[i][i] = 1; //set the diagonals to 1
		} //end loop 

		lower[0][0] = matrixA[0][0];
		for (int j = 1; j < n; j++){ //sets first column of lower, and first row of upper to match matrixA
			System.out.println("79 j: " + j);
			lower[j][0]= matrixA[j][0];
			upper[0][j]= matrixA[0][j] / lower[0][0];

		}
		for (int j = 1; j < n -1; j++) { // for j from 1 -> n-1
			for (int i = j; i < n; i++) { // for i from j -> n //Compute a lower matrix, not working correctly. 
				System.out.println("86 j: " + j + " i: " + i);
				lower[i][j] = matrixA[i][j];
				for (int k = 0; k < j; k++) { // for k from 0 -> j-1
					System.out.println("88 j: " + j +" i: " + i + " k: " +k);
					lower[i][j] = lower[i][j] - lower[i][k] * upper[k][j];
				}
			}
			for (int k = j+1; k < n; k++) { //Compute upper, not working. 
				upper[j][k] = matrixA[j][k];
				System.out.println("94 j: " + j + " k: " +k);
				for (int i = 0; i < j; i++) {
					System.out.println("96 j: " + j +" i: " + i + " k: " +k);
					upper[j][k] = upper[j][k] - lower[j][i] * upper[i][k];
				}
				upper[j][k] = upper[j][k] / lower[j][j];
			}
		}
		System.out.println("What The Fuck");
		lower[n-1][n-1] = matrixA[n-1][n-1];
		for (int k = 0; k < n-1; k++){
			System.out.println("103 k: " +k);
			lower[n-1][n-1] = lower[n-1][n-1] - lower[n-1][k]*upper[k][n-1]; 
		}
		System.out.println("LOWER: " + Arrays.deepToString(lower));
		System.out.println("UPPER: " + Arrays.deepToString(upper));
	}
}
