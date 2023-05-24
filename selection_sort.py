def selection_sort(array: [int], ascending=True) -> [int]:
	select = min if ascending else max
	sorted: [int] = []
	while len(array) > 0:
		minimum: int = select(array)
		array.remove(minimum)
		sorted.append(minimum)
	return sorted
	

print(selection_sort(array=[1, 2, 8, 4, 6, 5, 7, 3, 9, 10], ascending=True))