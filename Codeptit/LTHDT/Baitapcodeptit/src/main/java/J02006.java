
import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author Tducdz
 */
public class J02006 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[m];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < m; i++) {
            b[i] = sc.nextInt();
        }
        int[] c = new int[1000];
        for (int i = 0; i < 1000; i++) {
            c[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (c[a[i]] == 0) {
                c[a[i]] = 1;
            }
        }
        for (int i = 0; i < m; i++) {
            if (c[b[i]] == 0) {
                c[b[i]] = 1;
            }
        }
        for (int i = 0; i < 1000; i++) {
            if (c[i] == 1) {
                System.out.print(i + " ");
            }
        }
    }
}
