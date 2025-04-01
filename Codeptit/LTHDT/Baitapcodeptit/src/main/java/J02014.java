
import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author Tducdz
 */
public class J02014 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            int tong = 0;
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                tong += a[i];
            }
            boolean check = true;
            for (int i = 0; i < n - 2; i++) {
                int s = i;
                int tongxet = 0;
                while (s >= 0) {
                    tongxet += a[s];
                    s--;
                }
                if (tongxet * 2 + a[i + 1] == tong) {
                    System.out.println(i + 2);
                    check = false;
                }
            }       
            if (check == true) {
                System.out.println("-1");
            }
        }
    }
}
