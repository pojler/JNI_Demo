#include "com_pojler_jni_Main.hpp"
#include <iostream>
#include<math.h>

#define idx(x,y) y * rows + x

extern "C"
JNIEXPORT jint JNICALL Java_com_pojler_jni_Main_add
(JNIEnv* env, jobject thisObject, jint a, jint b) {
    return a+b;
}

JNIEXPORT jint JNICALL Java_com_pojler_jni_Main_count
  (JNIEnv * env, jobject thisObject, jintArray arr, jint size){
      jint suma = 0;
      jsize len = (*env).GetArrayLength(arr);
      jboolean *copy_sign= 0;
      jint * body = (*env).GetIntArrayElements(arr, copy_sign);
      for(int i = 0; i <size; i++){
          suma += body[i];
      }
      return suma;
  }
 
  JNIEXPORT jintArray JNICALL Java_com_pojler_jni_Main_cummulativeSum
    (JNIEnv * env, jobject thisObject, jintArray arr){
        jsize len = (*env).GetArrayLength(arr);
        jboolean *copy_sign= 0;
        jint * body = (*env).GetIntArrayElements(arr, copy_sign);
        jint* cummulative_array = new jint[len];
        cummulative_array[0] = body [0];

        for(int i = 1; i < len; i++){
             cummulative_array[i] = body[i]+ cummulative_array[i-1];
        }
        jintArray jarray_to_return = (*env).NewIntArray(len);

        (*env).SetIntArrayRegion(jarray_to_return, 0, len, cummulative_array);
        (*env).SetIntArrayRegion(arr, 0, len, cummulative_array);


        return jarray_to_return;
    }

int calculateDeterminant(jint * data, jint rows, jint cols){
    int determinant = 0; 
    if(rows!= cols){
        std::cout << "Cannot calculate determinanyt of asymetric matrix";
        return 0;
    }
    else{

        jint *submatrix = new jint[rows * cols];
        if (rows == 2){
            return((data[idx(0,0)] * data[idx(1,1)]) - (data[idx(1,0)] * data[idx(0,1)]));
        }

        else {

            for(int x = 0; x < rows; x++){
                int subi = 0;

                for(int i = 0; i < rows; i++){
                    int subj = 0;
                    
                    for (int j = 0; j<rows; j++ ){
                        if(j == x)
                        continue;
                        submatrix[idx(subi, subj)] = data[idx(i,j)];
                        subj++;
                    }
                    subi++;
                }
                determinant = determinant + (pow(-1,x) * data[idx(0,x)] * calculateDeterminant(submatrix, rows-1, cols-1));
                delete(submatrix);
            }

        }
        
    }
    return determinant;

}

JNIEXPORT void JNICALL Java_com_pojler_jni_Main_sumaryOfMatrix
    (JNIEnv * env, jobject thisObject, jintArray array, jint num_of_row, jint num_of_col,
     jint row, jintArray transposition, jintArray reverse, jint determinant, jint min, jint max, jint rows, jint cols){
         jboolean *copy_sign= 0;
         jint * body  = (*env).GetIntArrayElements(array, copy_sign);
         num_of_row = rows;
         num_of_col = cols;
         determinant = calculateDeterminant(body, rows, cols);
    }
