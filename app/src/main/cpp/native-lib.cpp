#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_prisar_chikku_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    const char src[] = "this string is too long";
    char dst[10];
    strcpy(dst, src);

    return env->NewStringUTF(hello.c_str());
}

std::string ConvertJString(JNIEnv* env, jstring str)
{
    if ( !str ) std::string();

    const jsize len = env->GetStringUTFLength(str);
    const char* strChars = env->GetStringUTFChars(str, (jboolean *)0);

    std::string Result(strChars, len);

    env->ReleaseStringUTFChars(str, strChars);

    return Result;
}

extern "C" JNIEXPORT void JNICALL
Java_com_prisar_chikku_MainActivity_brightness(JNIEnv * env, jobject obj, jstring bitmappath, jfloat brightnessValue)
{
    std::string bmpath = ConvertJString( env, bitmappath );
    FILE* f = fopen( bmpath.c_str(), "rb" );

    // do something useful here

    fclose( f );
}