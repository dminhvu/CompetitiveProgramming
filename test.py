def forward_propagate(nums_iteration,learning_rate):
    x = 5
    for _ in range(1,nums_iteration+1):
        dy = 2 * x + 6
        x -= learning_rate * dy
        if _ % 10 == 0:
            print(x)

forward_propagate(100,0.3)

