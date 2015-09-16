/*
Name: Joseph Waite
MacID: waitejg
Student Number: 1403712
Description: prints the given arguements in reverse
*/


class HWK1_waitejg {
	public static void main(String[] args){
		int len = args.length;
		String output = "";
		for(int i = len -1 ; i >= 0 ; i--){
			output += args[i] + " ";
		}
		System.out.println(output.substring(0, output.length() - 1));
	}
}
