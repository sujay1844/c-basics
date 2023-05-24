import ctypes

lib = ctypes.CDLL(name='./linked_list.so')

while True:
	lib.dispMenu()