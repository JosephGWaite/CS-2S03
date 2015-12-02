/*
Name: [Ethan Chan]
MacID: [Chaneh]
Student Number: [1409764]
Description: [This program takes n matrices and then multiplies it together, then getting the inverse,
gives the elements of the inverse as the output.]
*/

/* Get the values from input sorting rows and column values
 * Then obtain element values and put it into an array
 * MULTIPLICATION: WHat do I need?: 2 matrices, elements of the matrices.
 * 				First get use the values to generate the matrices
 */

public class HWK2_Chaneh {

	public static void main(String[] args) {
		
		//To get the number of matrices in to be used in multiplication
		int n = Integer.parseInt(args[0]);
		
		//This acts as a flag to check for restrictions.
		boolean rCheck = true;
		
		//Checks for number of matrices(10)
		if (n>10){
			
			//If the above is true it displays this message.
			System.out.println("Error: More then Max number of matrices.");
			
			//Changes the flag to false for later use and exclusion.
			rCheck = false;
		//This else if checks for zero matrices
		} else if (n < 1){
			//Displays message if no matrix
			System.out.println("No Matrix to invert.");
			//Changes flag to false.
			rCheck = false;
		//Else to do the code if all size matches.
		} else if (n == 1){
			//Checks if the single matrix given is a square matrix.
			if (Integer.parseInt(args[1]) != Integer.parseInt(args[2])){
				//Prints this message if not.
				System.out.println("Matrix not square.");
				//Changes the flag value.
				rCheck = false;
				
			} else {
				//Creates a matrix with the values given.
				int[][] SingMat = new int[Integer.parseInt(args[1])][Integer.parseInt(args[2])];
				//Initializes a counter
				int counter = 0;
				//The for loop is to transfer the input data into the matrix.
				for (int i = 0; i< SingMat.length; i++){
					//Cycles through rows ^, Cycles through columns V
					for (int j = 0; j< SingMat[0].length; j++){
						//Passing the data, values.
						SingMat[i][j] = Integer.parseInt(args[counter]);
						//Moves the counter to keep track of its location.
						counter++;
					}
				}
				//Inverts the matrix.
				invert(SingMat);
			}
			
		}else{
			//Initializes the array holding column and row values
			int size[][] = new int[n][2];
			//Helps keep track of location in args array.
			int counter = 0;

			//For loop to help organize the row and column values obtained through input.
			for (int i = 1; i<n*2; i=i+2){

				//Checks the sizes of the matrices to make sure they are within the size restrictions(20)
				if (Integer.parseInt(args[i])>20 || Integer.parseInt(args[i+1])>20){
					//If a matrix is too large it prints this message.
					System.out.println("Error: Matrix to large.");
					//Changes the restriction check to false
					rCheck = false;
					//Breaks out of loop
					break;
				}

				//holds the row values
				size[counter][0] = Integer.parseInt(args[i]);
				//holds the column values
				size[counter][1] = Integer.parseInt(args[i+1]);
				//increases a counter.
				counter++;
			}
			//initializing a jagged array which stores the matrices with matching index number.
			int ele[][][] = new int[n][][];
			//Keeps track of position going through the arguments/input. The n*2 lets it skip the part with
			//sizes of the matrices and the +1 skips the first input.
			int argsPos = (n*2)+1;
			//For loop which generates each matrix.
			for (int i = 0; i<n; i++){
				//initializes the sub-array
				ele[i] = new int[size[i][0]][size[i][1]];
				//r correspond rows
				for (int r = 0; r<(size[i][0]); r++){
					//c corresponds to columns
					for (int c = 0; c<(size[i][1]); c++){
						//Gives values to matrix.
						ele[i][r][c]= Integer.parseInt(args[argsPos]);
						//Moves the position tracker within the input string.
						argsPos++;
					}
				}
			}
			//Now that we have organized the input we can start working on the multiplication.
			//This variable saves the product matrix of two matrices.
			int[][] pMatrix = null;
			//Temporary array to hold the product matrix. Starting at the first matrix.
			int[][] tempM1 = ele[0];
			int[][] tempM2;
			//for loop to do the multiplication
			for (int i = 0; i<n; i++){
				//This if statement checks if multiplication is possible.
				if (i == n-1){
					//Breaks out of the loop.
					break;
					
					
				}else if (size[i][1] != size[i+1][0]){
					//If multiplication is not possible it prints this error message
					System.out.println("Error: Multiplication Error");
					//Changes the flag to false for later use
					rCheck = false;
					//Breaks out of the loop.
					break;
				}
				//Holds the next matrix to be multiplied.
				tempM2 = ele[i+1];
				//Gets the product of two matrices.
				pMatrix = mult(tempM1, tempM2);
				//holds the product matrix in this array.
				tempM1 = pMatrix;
				//Saves the product matrix's row value.
				size[i+1][0] = tempM1.length;
				//Saves the product matrix's column value.
				size[i+1][1] = tempM1[0].length;
			}
			//System.out.println("rows: " + pMatrix.length + " columns: " + pMatrix[0].length);
			//This if else statement checks the size of the matrix to be inverted.
			if (pMatrix.length != pMatrix[0].length){
				//If the matrix is not square it is not invertible the program will print out the following line.
				System.out.println("Product matrix is not square. Not able to invert");
				//changes the flag to false.
				rCheck = false;
			//This else is for if the product matrix is square.
			} else {
				/*This is where the inversion function comes in.
				 * It will call other functions to help in the process
				 * Will include a determinant function.
				 * Get determinant first, then calculate the inverse through adjoint/det.
				 */
				invert(pMatrix);
				
				
				
				
			}

			
			
			
		}
		//Flag at the end of the program which check whether inversion was possible or not
		//or if any problems were encountered.
		if (rCheck == false){
			//Prints out "Inversion Not Possible" if it did not complete the inversion.
			System.out.println("Inversion Not Possible");
		}
	}
	//This function multiplies two matrices.
	public static int[][] mult(int[][] a, int[][] b){
		
		//Gets the row value of Matrix a.
		int rA = a.length;
		//Gets the Column Value of Matrix a.
		int cA = a[0].length;
		//Gets the column value of Matrix b.
		int cB = b[0].length;
		//Sets the dimensions of the product matrix denoted by c.
		int c[][] = new int[rA][cB];
		
		//For loop to do the calculation.
		//This goes through the row of Matrix A.
		for (int i = 0; i < rA; i++){
			//This goes through the columns of Matrix B.
			for (int j = 0; j < cB; j++){
				//This goes through each corresponding value.
				for (int k = 0; k < cA; k++){
					//This gets a summation of corresponding values.
					c[i][j] += a[i][k] * b[k][j];	
				}       
			}
		}
		//Returns the final product matrix denoted by c.
		return c;
	}
	//The following function is where inverting the final product matrix will take place.
	public static void invert(int[][] mat){
		//Sets the determinant value to 0.
		double det = 0;
		//Sets the size of the inverse matrix.
		double[][] inverse = new double[mat.length][mat[0].length];
		//Creates a matrix which holds the values of mat but is made double.
		double[][] dMat = new double[mat.length][mat[0].length];
		//Matrix to store the cofactors
		double[][] cMat = new double[mat.length][mat[0].length];
		
		//For loop to pass on the values of mat to dMat.
		for (int i = 0; i < mat.length; i++){
			//The above for loop cycles through rows, the one below cycles through the columns.
			for (int j = 0; j < mat[0].length; j++){
				//sets dMat to mat.
				dMat[i][j] = mat[i][j];
			}
		}
		det = getDet(dMat);
		//Use cofactor expansion to get the determinant.
		//Checks if the determinant is 0.
		if (det == 0){
			//Prints This message if the matrix has a determinant of 0.
			System.out.println("Matrix not invertible, determinant = 0");
			//Breaks out of the function
			return;
		//Else do the alternative.
		} else {
			//For loops to go through the product matrix to get the cofactors.
			//This goes though rows.
			for (int i = 0; i < mat.length; i++){
				//This goes through columns.
				for (int j = 0; j < mat[0].length; j++){
					//reversing j and i so that it automatically does the transpose.
					cMat[j][i] = cofact(dMat,i,j);
				}
			}
		}
		//To get the inverse of a matrix you need the adjoint/determinant.
		//This for loop saves the values of the inverse into the matrix saving its values.
		//Goes through rows.
		for (int i = 0; i < inverse.length; i++){
			//Goes through columns
			for (int j = 0; j < inverse[0].length; j++){
				//Sets the element values.
				inverse[i][j] = cMat[i][j]/det;
				//Prints out the inverse's elements row by row in one line.
				System.out.print(inverse[i][j] + " ");
			}
		}
	}
	/*Things needed to invert a matrix:
	 * A square matrix
	 * Determinant function
	 * Since I will be doing adjoint, will need a transpose function
	 * Cofactor expansion method(maybe built into the invert function
	 */
	//This function will invert the product matrix obtained prior to.
	public static double getDet(double[][] m){
		//Initalize the determinant.
		double det = 0;
		//Checks the size the of the matrix to see which method to use.
		//If 2x2 it will use the formula, if not recursion, calling itself.
		if (m.length == 2 && m[0].length == 2){
			//formula for the determinant of a 2x2.
			det = m[0][0]*m[1][1] - m[0][1]*m[1][0];
		//The else means that if not 2x2 do the other method.
		} else if (m.length == 1 && m[0].length ==1){
			det = m[0][0];
			
		} else {
			//For loop to go through a row of elements to get the determinant.
			for (int i = 1; i < m.length+1; i++){
				//Using recursion it will call itself to get the right values.
				//The if statement checks the position of the i, since there is a sign piece in getting the determinant.
				if (i%2 != 0){
					//Since even, subtract.
					det =  det - m[0][i-1]*getDet(subMat(m, 0, i-1));
				//The else is so it can do the alternative.
				} else {
					//Since odd, add.
					det =  det + m[0][i-1]*getDet(subMat(m, 0, i-1));
				}
				
			}
		}
		//Returns the final value of the determinant.
		return det;
	}
	//This will get the minor matrix used for cofactor expansion.
	//The double[][] pri denotes the matrix the sub matrix is coming
	//to get the sub-Matrix you will also need the row and column you are excluding from the parent matrix.
	//r denotes row and c denotes column.
	public static double[][] subMat(double[][] pri, int r, int c){
		
		//Counter to keep track of which row of sub matrix we are at.
		int subR = 0;
		//Counter to keep track of which column of sub matrix we are at.
		//Sets the size of the sub matrix.
		double[][] sub = new double[pri.length - 1][pri[0].length -1];
		//For loop to get the matrix elements for the sub matrix from the parent matrix.
		for (int i = 0; i < pri.length; i++){
			//If statement to check if the row is excluded from sub matrix.
			if (i != r){
				int subC = 0;
				//For loop to get the columns of parent matrix to sub matrix
				for (int j = 0; j <pri[0].length; j++){
					//Checks if the column is excluded from the sub matrix.
					if (j != c){
						//Puts the elements of the parent matrix into the sub matrix.
						sub[subR][subC] = pri[i][j];
						//Increases the counter for subC.
						subC++;	
					}
				}
				//Increases the counter for subR
				subR++;
			}
		}
		//Returns the sub matrix
		return sub;
	}	
	//This function gets the cofactors for the adjoint.
	public static double cofact(double[][] a,int r,int c){
		//Initialize the variable holding the cofactor
		double cFac = 0;
		//Creates an array holding the submatrix
		if (a.length == 1){
			cFac = 1/a[0][0];
			return cFac;
		}
		double[][] sMat = subMat(a, r, c);
		//The cofactor is the determinant of the sub matrix
		cFac = getDet(sMat);
		//Returns the cofactor value.
		return cFac;
	}
}
//End of File.