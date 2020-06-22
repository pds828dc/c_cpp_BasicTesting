## python print test

def func(word, vec=[]):
    vec.append(word)
    return vec

list1 = func(10,[])
list2 = func('a')
list3 = func(100)

print("list1 =",list1)
print("list2 =",list2)
print("list3 =",list3)



