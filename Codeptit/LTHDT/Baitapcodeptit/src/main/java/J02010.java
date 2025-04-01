
import java.util.Scanner;

public class J02010 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        boolean check = false;
        int dem = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) {
                    check = true;
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
            if (check == true) {
                dem++;
                System.out.printf("Buoc %d: ", dem);
                for (int r = 0; r < n; r++) {
                    System.out.printf("%d ", a[r]);
                }
                System.out.println();
            }
        }
    }
}
