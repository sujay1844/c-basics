def selection_sort_py(array: [int], ascending=True) -> [int]:
	select = min if ascending else max
	sorted: [int] = []
	while len(array) > 0:
		minimum: int = select(array)
		array.remove(minimum)
		sorted.append(minimum)
	return sorted
	
# Random 100 integers in a list
import random
sample_array = random.sample(range(2147483647), 100)

number_of_trials = 10000

import timeit
selection_sort_time = timeit.timeit(lambda: selection_sort_py(sample_array.copy()), number=number_of_trials) / number_of_trials
built_in_sort_time = timeit.timeit(lambda: sorted(sample_array.copy()), number=number_of_trials) / number_of_trials


print(f"Python selection sort time: {selection_sort_time*1000} ms")
print(f"Python built-in sort time: {built_in_sort_time*1000} ms")