import matplotlib.pyplot as plt

x = -3
learning_rate = 0.4
x_list = [x]
y_list = [x**2 + 2 * x + 5]

for i in range(30):
    new_x = x - learning_rate * (2 * x + 2)
    x = new_x
    x_list.append(x)
    y_list.append(x**2 + 2 * x + 5)

print(x_list)
print(y_list)
plt.plot(x_list,y_list)