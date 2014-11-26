#include <jni.h>
#include <string>

extern "C" {
   int startHTTP(void);

   JNIEXPORT jstring JNICALL
      Java_org_ec8_ec8top_MainActivity_startHTTP(JNIEnv *,
					   jobject); 
					   
   JNIEXPORT jstring JNICALL
      Java_org_ec8_ec8top_MainActivity_startHTTP(JNIEnv *env,
					   jobject obj)	
   {   
       std::string ret = "ok"; 
 
       startHTTP();

       jstring jstr = env->NewStringUTF(ret.c_str());
       return jstr;
   }
}

