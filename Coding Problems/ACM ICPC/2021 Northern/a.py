s = input().lower()
s = s.split('.')
if len(s) > 1 and s[-1] == 'py':
    print("yes")
else:
    print("no")