def calc(a, b, c):
  u = [b[0] - a[0], b[1] - a[1]]
  v = [c[0] - b[0], c[1] - b[1]]
  x = u[0] * v[1] - u[1] * v[0] < 0
  if (x == 0):  return 0
  if x < 0: return -1
  if x > 1: return 1

numTest = int(input())

while numTest > 0:
  numTest -= 1
  cor = list(map(int, input().split(' ')))

  point = []
  point.append([cor[0], cor[1]])
  point.append([cor[2], cor[3]])
  point.append([cor[4], cor[5]])
  point.append([cor[6], cor[7]])


  point.sort()

  a = calc(point[0], point[3], point[1])
  b = calc(point[0], point[3], point[2])

  if (a * b >= 0):
    print("NO")
  else:
    print("YES")