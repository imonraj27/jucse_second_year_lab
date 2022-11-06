def gp(a, q):
    while True:
        if a > 100000:
            return
        yield a
        a *= q


a = int(input("Enter First term: "))
q = int(input("Enter Common Ratio: "))

print("Geometric Progression with first term",
      a, "and common ratio ", q, " ==>")
for term in gp(a, q):
    print(term, end=" ")
print("")
