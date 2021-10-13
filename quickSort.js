function swap(arr, i, j) {
    let temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp
}

function partition(arr, start, end) {
    let index = start
    let pivot = arr[end]
    while (start < end) {
        if (arr[start] < pivot) {
            swap(arr, index, start)
            index++
        }
        start++
    }
    swap(arr, index, start)
    return (index)
}

function quickSort(arr, start=0, end=null) {
    if (end === null)
        end = arr.length - 1
    if (start >= end)
        return []
    let index = partition(arr, start, end)
    quickSort(arr, start, index - 1)
    quickSort(arr, index + 1, end)
}

if (require.main.children.length === 0) {
    let arr = process.argv.slice(2)
    arr = arr.map(num => parseInt(num))
    arr = arr.filter(num => Number.isInteger(num))
    quickSort(arr)
    console.log(arr)
}
