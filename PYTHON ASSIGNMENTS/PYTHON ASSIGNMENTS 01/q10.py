
import math


def is_square(i):
    return (i == math.floor(math.sqrt(i)) ** 2)


l1 = []

for i in range(15):
    l1.append(i*i)


filtered_list = filter(lambda x: x % 2 != 0 and is_square(x), l1)

print("Unfiltered List: ", end="")
print(l1)

print("Filtered List: ", end="")
print(list(filtered_list))
