import java.util.*;
public class substring {

    public static void main(String[] args) {
        String word = "123";
        ArrayList<String> subyolo = new ArrayList<String>();  
        generate(0, word.length(), word, subyolo);
    }

    public static void generate(int start, int end, String word,ArrayList<String> subyolo) {
        if (end ==0) {
            System.out.println(subyolo);
        }else if (start == end){ 
            generate(start - end, end - 1,word, subyolo);//reset
        }else{
            subyolo.add(word.substring(start, end));
            generate(start +1, end, word, subyolo);
        }
    }

}