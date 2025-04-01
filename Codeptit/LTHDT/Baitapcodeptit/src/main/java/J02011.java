import java.util.Scanner;
public class J02011 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int dem = 0;
        for (int i = 0; i < n - 1; i++) {
            int min = i;
            boolean check = false;
            for (int j = i + 1; j < n; j++) {
                if (a[min] > a[j]) {
                    check = true;
                    min = j;
                }
            }
            if (check == true) {
                dem++;
                int doi = a[i];
                a[i] = a[min];
                a[min] = doi;
                System.out.printf("Buoc %d: ", dem);
                for (int k = 0; k < n; k++) {
                    System.out.printf("%d ", a[k]);
                }
                System.out.println();
            }
        }
    }
}
