def update_balance(account, amount):
    account['balance'] += amount

def calculate_interest(account, interest_rate):
    return account['balance'] * interest_rate

bank_account = {'name': 'John Doe', 'balance': 1000}

update_balance(bank_account, 500)

print("Updated Balance:", bank_account['balance'])

interest = calculate_interest(bank_account, 0.05)
print(f"Interest Earned: {interest}")