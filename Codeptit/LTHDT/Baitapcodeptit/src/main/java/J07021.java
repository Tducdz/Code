
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class J07021 {

    public static String viethoa(String s) {
        return s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase();
    }
            
    public static void main(String args[]) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("DATA.in"));
        while (sc.hasNext()) {
            String s = sc.nextLine();
            if (s.equals("END")) {
                break;
            }
            String[] words = s.trim().split("\\s+");
            String ans = "";
            for (String i : words) {
                ans += viethoa(i);
            }
            System.out.println(ans);
        }
    }
}