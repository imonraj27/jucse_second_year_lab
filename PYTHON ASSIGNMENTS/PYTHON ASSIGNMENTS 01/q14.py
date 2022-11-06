from collections import Counter

class TextProcessing:
  def __init__(self,text):
    self.text=str(text)
    self.counter=Counter(self.text.split())
  @classmethod
  def is_palindrome(cls,s):
    return s==s[::-1]
  def is_unique(self,word):
    if word in self.counter.keys():
      if self.counter[word]==1:
        return True
    return False

tp=TextProcessing("This is what it is madam")
print(tp.is_unique("is"))
print(tp.is_unique("what"))
print(tp.is_palindrome("madam"))