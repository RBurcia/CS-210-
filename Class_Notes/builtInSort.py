#Method A

x = [7, 23, 9, 7, 6, 22, 41, 8, 0]

x.sort()
print(x)

#Space time complexity is o(n) since it needs to copy the array and then sort it again
#Method B
x = [7, 23, 9, 7, 6, 22, 41, 8, 0]

print(sorted(x))


