//ITERATIVE EXTRA CREDIT WITH LU DECOMPOSITION + BACKSUBTITUTION 
/*
 Name: Joseph Waite
 MacID: waitejg
 Student Number: 1403712
 Description: take matricies in from args, multiply them together, then return the inverse
 */

import java.util.Arrays;

public class HWK2_waitejg {
	public static void main(String[] args) { // main method

		double[] argsInt = Arrays.stream(args).mapToDouble(Double::parseDouble).toArray(); // String[] args --> int[] args 
		double numMatricies = argsInt[0]; //number of matricies given in args;
		double[][][] ourArrays = new double[Integer.parseInt(args[0])][][]; //initalise our list of 2D arrays

		double start = (numMatricies * 2) + 1; //when we do copyOfRange we need to specify where in args[] 
											//does our actualy array values start

		double skipValue = start; //the length of the array we copy 
		for (int i = 0; i < numMatricies; i++) //Here we create our arrays from the args list 
		{
			double m = argsInt[(i * 2) + 1]; //how many rows does the matrix have?
			double n = argsInt[(i * 2) + 2]; //how many columns does the matric have? 
			double[] dlist = Arrays.copyOfRange(argsInt, (int) skipValue, (int) (skipValue + (m*n))); //grab all values of a matrix from args
			ourArrays[i] = Dto2D(dlist, (int) m, (int) n); //transform those 1D values into a 2D array; add that array to our array of arrays
			skipValue = skipValue + (m * n); //get the length of the next array
		}

		double[][] acc = null;  //our accumulator for multiplication 
								// If i didn't leave this till last min
								// then I would try to curry it
		double[][] temp = ourArrays[0]; // temp array to hold product

		for (int i = 1; i < numMatricies; i++){ // multiply our arrays together using a temp value 
			acc = multi(temp, ourArrays[i]); //array[i] * array[i+1]
			temp = acc;
		}
		LUinvert(acc); //return the inverse
	}

	public static double[][] multi(double matrixA[][], double matrixB[][]) { // multiplication																			// method
		/*
		 *
		 * Naive matrix multiplication algorithm
		 * 
		 */

		int n = matrixA[0].length; // get column dimension
		int m = matrixB.length; // get row dimensiom
		int p = matrixB[0].length; // get column dimension

		if (m != matrixA.length) { // If dimensionons are invalid.
			throw new Error("Multiplication Error");
		}

		double[][] matrixC = new double[m][p];
		//We just go through the row and columns
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < p; j++) {
				for (int k = 0; k < n; k++) {
					matrixC[i][j] += matrixA[i][k] * matrixB[k][j]; //and we multiply them together
				}
			}
		}
		return matrixC; //return the answer
	}

	public static double[][] Dto2D(double list[], int m, int n){
		//Takes an 1D int array, # of rows, # of columns, and return a 2D array
		double[][] matrix = new double[m][n]; // initalise our matrix 
		int i = 0; //initialse the counter
		for (int j = 0; j < m; j++){ // rows 
			for(int k = 0; k < n; k++){ //columns 
				matrix[j][k]=list[i]; //
				i++; //increment counter 
			}
		}
		return matrix;
	}

	public static void LUinvert(double matrixA[][]) {
		//This is incomplete, I'm not sure what to do once I have the lower and upper matrix

		int n = matrixA[0].length;
		double[][] lower = new double[n][n];
		double[][] upper = new double[n][n];

		for (int i = 0; i < n; i++) { // Identity matrix
			upper[i][i] = 1; //set the diagonals to 1
		} //end loop 

		lower[0][0] = matrixA[0][0];
		for (int j = 1; j < n; j++){ //sets first column of lower, and first row of upper to match matrixA
			lower[j][0]= matrixA[j][0];
			upper[0][j]= matrixA[0][j] / lower[0][0];

		}
		for (int j = 1; j < n -1; j++) { // for j from 1 -> n-1
			for (int i = j; i < n; i++) { // for i from j -> n //Compute a lower matrix
				lower[i][j] = matrixA[i][j];
				for (int k = 0; k < j; k++) { // for k from 0 -> j-1
					lower[i][j] = lower[i][j] - lower[i][k] * upper[k][j];
				}
			}
			for (int k = j+1; k < n; k++) { //Compute upper
				upper[j][k] = matrixA[j][k];
				for (int i = 0; i < j; i++) {
					upper[j][k] = upper[j][k] - lower[j][i] * upper[i][k];
				}
				upper[j][k] = upper[j][k] / lower[j][j]; //what if this is 0? It won't be?
			}
		}
		lower[n-1][n-1] = matrixA[n-1][n-1];
		for (int k = 0; k < n-1; k++){
			lower[n-1][n-1] = lower[n-1][n-1] - lower[n-1][k]*upper[k][n-1]; //Finally finished the lower matrix
		}
	}
}