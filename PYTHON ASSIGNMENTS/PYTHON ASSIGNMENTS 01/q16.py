from collections import Counter 
class MyString(str):
  
  def __len__(self) -> int:
    s=self.__str__()
    counter=Counter(s.split())
    repetitive=sum(map(lambda x:1 if x>1 else 0,counter.values()))
    print("Actual length of the whole string:",super().__len__())
    return repetitive

s=MyString("This is a string which is very good. This is a good example")
print(len(s))