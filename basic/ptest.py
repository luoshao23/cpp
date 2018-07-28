import platform
from ctypes import *


mylib = CDLL('/Users/shouzeluo/Desktop/cpp/nfs.dylib')
print('1 + 2 =', mylib.add(1, 2))
# mylib.add(7, 9)

# inta = c_int * 5

# libc = CDLL('libc.dylib')
# qsort = libc.qsort
# qsort.restype = None

# CMPFUNC = CFUNCTYPE(c_int, POINTER(c_int), POINTER(c_int))


# def py_cmp_func(a, b):
#     print("py_cmp_func", a[0], b[0])
#     return a[0] - b[0]

# ia = inta(5, 3, 2, 1, 7)
# qsort(ia, len(ia), sizeof(c_int), CMPFUNC(py_cmp_func))

# for i in ia:
#     print(i)
