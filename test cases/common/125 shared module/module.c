#if defined _WIN32 || defined __CYGWIN__
  #define DLL_PUBLIC __declspec(dllexport)
#else
  #if defined __GNUC__
    #define DLL_PUBLIC __attribute__ ((visibility("default")))
  #else
    #pragma message ("Compiler does not support symbol visibility.")
    #define DLL_PUBLIC
  #endif
#endif

/*
 * Shared modules often have references to symbols that are not defined
 * at link time, but which will be provided by the executable that
 * dlopens it. We need to make sure that this works, i.e. that we do
 * not pass -Wl,--no-undefined when linking modules.
 */
int nonexisting_function();

int DLL_PUBLIC func() {
    return nonexisting_function();
}
