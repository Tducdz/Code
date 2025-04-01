import java.util.Scanner;

public class J01026 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int a = sc.nextInt();
            if ((int)(Math.sqrt(a)) * (int)(Math.sqrt(a)) != a) {
                System.out.println("NO");
            }
            else {
                System.out.println("YES");
            }
        }
    }
}
