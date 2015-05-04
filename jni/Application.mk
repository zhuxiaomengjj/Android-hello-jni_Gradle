APP_STL := c++_static 
NDK_TOOLCHAIN_VERSION=clang

APP_CPPFLAGS := -frtti -std=c++11 -fsigned-char -fexceptions
#APP_LDFLAGS := -L/Users/zhuxiaomeng/Desktop/3rdParty/v8/v8/out/arm.release \
 -latomic -lv8_base -lv8_libbase -lv8_libplatform -lv8_nosnapshot -licuuc -licui18n -licudata
APP_ABI := armeabi-v7a

#v8_base v8_libbase v8_libplatform v8_nosnapshot icuuc icui18n icudata
#LOCAL_LDLIBS := -L/Users/zhuxiaomeng/Desktop/3rdParty/v8/v8/out/arm.release -pthread

