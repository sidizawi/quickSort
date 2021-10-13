import sys

def swap(arr, i, j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp

def partition(arr, start, end):
    index = start
    pivot = arr[end]
    while start < end:
        if arr[start] < pivot:
            swap(arr, index, start)
            index += 1
        start += 1
    swap(arr, index, start)
    return index

def quickSort(arr, start=0, end=None):
    if end == None:
        end = len(arr) - 1
    if start >= end:
        return arr
    index = partition(arr, start, end)
    quickSort(arr, start, index-1)
    quickSort(arr, index+1, end)
    return arr

if __name__ == '__main__':
    arr = list(map(int, sys.argv[1:]))
    quickSort(arr)
    print(arr)
    
