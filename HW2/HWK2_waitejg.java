//ITERATIVE EXTRA CREDIT
/*
Name: Joseph Waite
MacID: waitejg
Student Number: 1403712
Description: naive matrix multiplication in java.  O(n^3)
*/

class HWK2_waitejg {
	public static void main(String[] args){

		int matrixA[][]={{50,60,55}
						,{62,65,70}
						,{72,66,77}};

		int matrixB[][]={{50,60,55}
						,{62,65,70}
						,{72,66,77}};

		int n = matrixA.length;
		int[][] matrixC = new int[3][3];
		System.out.println("FUCK");
		for(int i =0; i < n ; i++){
			for (int j=0; i<n ; j++){
				for(int k=0;k<n;k++){
					matrixC[i][j]+= matrixA[i][k] * matrixB[k][j];
				}
			}
		}
		System.out.println(matrixC);

	}
}
