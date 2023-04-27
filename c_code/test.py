def foo(x):
    x[0] = "def"
    x[1] = "bar"
    return id(x)

q=["bar", "def"] 
print(id(q)==foo(q))

