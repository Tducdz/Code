
import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author Tducdz
 */
public class J02012 {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0 ; i < n; i++) {
            int id = i;
            while (id > 0 && a[id] < a[id - 1]) {
                int doi = a[id];
                a[id] = a[id - 1];
                a[id - 1] = doi;
                id--;
            }
            System.out.printf("Buoc %d: ", i);
            for (int k = 0; k <= i; k++) {
                System.out.printf("%d ", a[k]);
            }
            System.out.println();
        }
    }
}
