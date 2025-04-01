import java.util.Scanner;
public class J02008 {

    public static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    public static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int[] a = new int[101];
        a[1] = 1;
        a[2] = 2;
        a[3] = 6;
        for (int i = 4; i < 101; i++) {
            a[i] = lcm(a[i - 1], i);
        }
        while (t-- > 0) {
            int n = sc.nextInt();
            System.out.println(a[n]);
        }
    }
}