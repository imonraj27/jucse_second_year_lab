
class IterateEven:
    def __iter__(self):
        self.num = 2
        return self

    def __next__(self):
        num = self.num
        self.num = num+2
        return num


class IterateOdd:
    def __iter__(self):
        self.num = 1
        return self

    def __next__(self):
        num = self.num
        self.num = num+2
        return num


evens = IterateEven()
iterEvens = iter(evens)

print("\n\nFirst 10 evens using iterators: ", end=" ")

for i in range(10):
    print(next(iterEvens), end=", ")

odds = IterateOdd()
iterOdds = iter(odds)

print("\n\nFirst 10 odds using iterators: ", end=" ")

for i in range(10):
    print(next(iterOdds), end=", ")
