def merge(a, l, m, r):
  L = [a[i] for i in range(l, m + 1)]
  R = [a[i] for i in range(m + 1, r + 1)]
  i = 0
  j = 0
  while i < m or j < r:
    if a[i] < a[j]:
      
def merge_sort(a, l, r):
  if l < r:
    m = (l + r) >> 1
    merge_sort(a, l, m)
    merge_sort(a, m + 1, r)
    merge(a, l, m, r)

a = [2, 5, 4, 3, 1]
