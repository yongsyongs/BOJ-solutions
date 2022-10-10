sentence = input()
print(len(list(filter(''.__ne__, sentence.split(' ')))))