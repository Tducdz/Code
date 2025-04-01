import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author Tducdz
 */
public class J02013 {    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = n - 1; i > 1; i--) {
            boolean check = false;
            for (int j = 0; j < i; j++){
		if(a[j] > a[j + 1]){
                    check = true;
                    int k = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = k;
                }
            }
            if (check == true) {
                System.out.printf("Buoc %d: ", n - i);
                for (int m = 0; m < n; m++) {
                    System.out.printf("%d ", a[m]);
                }
                System.out.println();
            }
        }
    }
}