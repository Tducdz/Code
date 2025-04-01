
import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author Tducdz
 */
public class J02004 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            int check = 1;
            for (int i = 0; i < n / 2; i++) {
                if (a[i] != a[n - 1 - i]) {
                    System.out.println("NO");
                    check = 0;
                    break;
                }
            }
            if (check == 1) {
                System.out.println("YES");
            }
        }
    }
}
