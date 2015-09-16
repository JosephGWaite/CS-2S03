import java.util.Arrays;

public class HelloWorld {
	public static void main(String[] args){
		int len = args.length;
		String output = "";
		for(int i = len -1 ; i >= 0 ; i--){
			output += args[i] + " ";
		}
		System.out.println(output.substring(0, output.length() - 1));
	}
}