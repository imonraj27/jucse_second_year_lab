# deposit, withdraw, get_balance, change_pin.

class BankAccount:
    def __init__(self, name, id, balance, pin):
        self._name = name
        self._id = id
        self._balance = balance
        self._pin = pin

    def deposit(self, money):
        self._balance += money

    def withdraw(self, money):
        self._balance -= money

    def get_balance(self):
        return self._balance

    def change_pin(self, pin):
        self._pin = pin


class SavingsAccount(BankAccount):
    def __init__(self, name, id, balance, pin, interest_rate):
        super().__init__(name, id, balance, pin)
        self._interest_rate = interest_rate

    def add_interest(self, time_t):
        self._balance += self._balance*time_t*self._interest_rate/(12*100)


class FeeSavingsAccount(SavingsAccount):
    def __init__(self, name, id, balance, pin, interest_rate, fee):
        super().__init__(name, id, balance, pin, interest_rate)
        self._fee = fee

    def withdraw(self, money):
        self._balance -= money+self._fee


ba = BankAccount("Forouzan", "123456789", 1000, 1234)
ba.deposit(100)
print(ba.get_balance())
ba.withdraw(50)
print(ba.get_balance())
ba.change_pin(4321)

sa = SavingsAccount("Narsimha", "123456789", 1000, 1234, 0.1)
sa.deposit(100)
print(sa.get_balance())
sa.add_interest(1)
print(sa.get_balance())

fsa = FeeSavingsAccount("Clerkix", "123456789", 1000, 1234, 0.1, 10)
fsa.deposit(100)
print(fsa.get_balance())
fsa.withdraw(50)
print(fsa.get_balance())
fsa.add_interest(1)
print(fsa.get_balance())
fsa.withdraw(50)
print(fsa.get_balance())
