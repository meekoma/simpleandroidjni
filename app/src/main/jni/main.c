//
// Created by Meeko Ma on 2019/3/14.
//
#include "com_example_testjni_MainActivity.h"
JNIEXPORT jstring JNICALL  Java_com_example_testjni_MainActivity_getStringFromC(JNIEnv * env, jobject obj){
 return (*env)->NewStringUTF(env,"终于可以了");
}


static int get_val(char c) {
	int ret=-1;

	printf("char is %c ... \n", c);

	if (48<=c && c<=57) {
		ret = c-48;
		return ret;
	}

	if (65<=c && c<=70) {
		ret = c-55;
		return ret;
	}

	if (97<=c && c<=102) {
		ret = c-87;
		return ret;
	}

	return ret;
}

static int str_to_dou (const char *str, double *ret) {

	int i;

	unsigned char *p = (unsigned char*)ret;

	for (i=0;i<strlen(str)-1;) {
		*p = 16*get_val(str[i])+get_val(str[i+1]);
		printf("p val %d ... \n", *p);
		i = i+2;
		p++;
	}

	return 0;
}


JNIEXPORT jdouble JNICALL  Java_com_example_testjni_MainActivity_getString2FromC(JNIEnv * env, jobject obj,jstring str){
    jdouble ret=0.123;
    char* pp = (char*)(*env)->GetStringUTFChars(env,str, 0);
    str_to_dou(pp, &ret);
    return ret;
}
