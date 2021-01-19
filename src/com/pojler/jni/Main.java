package com.pojler.jni;

public class Main {

    static {
        System.load(System.getProperty("user.dir")+"/src/com/pojler/jni/majca.dll");
    }

    native public static int add (int a, int b);

    native private static int count(int[] array, int size);
    public int count(int[] array){
        return count(array, array.length);
    }
    native private static int[] cummulativeSum (int[] array);
    native private static void summaryOfMatrix (int[] array, int out_number_of_rows, int out_number_of_collumns,
    int out_row, int[] out_transposition, int [] out_reverse, int out_exponent, int out_min, int out_max, int rows, int cols);

    public void summaryOfMatrix (int [][] matrix){
        int number_of_rows=0, number_of_collumns=0, row=0, determinant=0, min=0, max=0;
        int rows = matrix.length;
        int cols = matrix[0].length;
        int array[] = new int[rows*cols];
        int [] reverse = new int[matrix.length*matrix[0].length];
        int [] transposition = new int[matrix[0].length* matrix.length];
        summaryOfMatrix(array, number_of_rows, number_of_collumns, row, transposition, reverse, determinant, min, max,rows ,cols);
    }



    public static void main(String[] args) {
        Main x = new Main();
        //System.out.println(add(10, 7));
        int [] arr = {12,15,50,100,200,300};
       // System.out.println(x.count(arr));
        int dupa[] = cummulativeSum(arr);
        for (int i = 0; i <dupa.length; i++){
            System.out.println(arr[i]);

        }

    }

}
