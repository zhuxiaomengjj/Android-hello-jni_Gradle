/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <jni.h>
//#include <include/v8.h>
//#include "include/libplatform/libplatform.h"
#include <iostream>
#include <memory>
#include <string>
#include <thread>

using namespace std;
//using namespace v8;

extern "C" {
    
    std::string g_message;
    void testV8()
    {
        std::unique_ptr<string> p(new string("It's fun"));
        printf("%s\n", p->c_str());
        g_message = (*p);
    }
    /*
    int testV8()
    {
// Initialize V8.
        V8::InitializeICU();
        Platform* platform = platform::CreateDefaultPlatform();
        V8::InitializePlatform (platform);
        V8::Initialize();
        // Create a new Isolate and make it the current one.
        Isolate* isolate = Isolate::New();
        {
            Isolate::Scope isolate_scope (isolate);
            // Create a stack-allocated handle scope.
            HandleScope handle_scope (isolate);
            // Create a new context.
            Local<Context> context = Context::New (isolate);
            // Enter the context for compiling and running the hello world script.
            Context::Scope context_scope (context);
            // Create a string containing the JavaScript source code.
            Local<String> source = String::NewFromUtf8 (isolate, "'Hello' + ', World!'");
            // Compile the source code.
            Local<Script> script = Script::Compile (source);
            // Run the script to get the result.
            Local<Value> result = script->Run();
            // Convert the result to an UTF8 string and print it.
            String::Utf8Value utf8 (result);
            printf ("%s\n", *utf8);
        }
        // Dispose the isolate and tear down V8.
        isolate->Dispose();
        V8::Dispose();
        V8::ShutdownPlatform();
        delete platform;
        return 0;
    }
    */
    /* This is a trivial JNI example where we use a native method
     * to return a new VM String. See the corresponding Java source
     * file located at:
     *
     *   apps/samples/hello-jni/project/src/com/example/hellojni/HelloJni.java
     */
    jstring
    Java_com_example_hellojni_HelloJni_stringFromJNI (JNIEnv* env,
            jobject thiz )
    {
#if defined(__arm__)
#if defined(__ARM_ARCH_7A__)
#if defined(__ARM_NEON__)
#if defined(__ARM_PCS_VFP)
#define ABI "armeabi-v7a/NEON (hard-float)"
#else
#define ABI "armeabi-v7a/NEON"
#endif
#else
#if defined(__ARM_PCS_VFP)
#define ABI "armeabi-v7a (hard-float)"
#else
#define ABI "armeabi-v7a"
#endif
#endif
#else
#define ABI "armeabi"
#endif
#elif defined(__i386__)
#define ABI "x86"
#elif defined(__x86_64__)
#define ABI "x86_64"
#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
#define ABI "mips64"
#elif defined(__mips__)
#define ABI "mips"
#elif defined(__aarch64__)
#define ABI "arm64-v8a"
#else
#define ABI "unknown"
#endif
        testV8();
        std::thread t(testV8);
        t.join();
        char buff[1024];
        sprintf(buff, "Hello world !  Compiled with ABI %s. And %s", ABI, g_message.c_str());
        return env->NewStringUTF (buff);
    }
}
