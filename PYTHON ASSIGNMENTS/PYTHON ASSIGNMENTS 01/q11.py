import math


print("Pythagorean Triplets with smaller side upto 10 -->")

pythTriplets = [(a, b, int(math.sqrt(b*b+a*a))) for a in range(1, 10)
                for b in range(a, 60) if math.sqrt(b*b+a*a)-math.floor(math.sqrt(b*b+a*a)) == 0]
print(pythTriplets)
