import numpy as np

def gradient_descent(x,y):
    # empty
    m_curr = b_curr = 0
    iterations = 10
    learning_rate = 0.0288888
    n = len(x)
    for i in range(iterations):
        y_predicted = m_curr * x + b_curr
        md = -(2/n) * sum(x * (y - y_predicted))
        bd = -(2/n) * sum(y - y_predicted)
        m_curr -= learning_rate * md
        b_curr -= learning_rate * bd
        print("m = {}, b = {}, iteration {}".format(m_curr,b_curr,i))



x = np.array([1, 3, 5, 7, 9])
y = np.array([7, 11, 15, 19, 23])

gradient_descent(x,y)