import random
listy=[]
n=5
for i in range(20):
  listy.append(random.randint(1,100))
listy.sort()
print(listy[:n])
print(listy[:-(n+1):-1])