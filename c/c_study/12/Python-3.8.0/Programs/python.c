/* Minimal main program -- everything is loaded from the library */

#include "Python.h"
#include "pycore_pylifecycle.h"

#ifdef MS_WINDOWS
int
wmain(int argc, wchar_t **argv)
{
    printf("\n在调用堆栈中这个在最下面这里是程序的入口 在 longobject 311 行 打上断点  \n");
    return Py_Main(argc, argv);
}
#else
int
main(int argc, char **argv)
{
    //printf("\n 这里是main  ---》\n ");
    return Py_BytesMain(argc, argv);
}
#endif
