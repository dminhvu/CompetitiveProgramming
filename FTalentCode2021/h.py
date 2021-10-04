def calc(s):
    s = s.replace("(","")
    s = s.replace(")","")
    s = s.replace(" ","")
    def div(num1, num2):
        result = num1//num2
        return result

    operators = "+-*/"
    currentNum = ''
    currentOp = '+'
    stack = []
    len_s = len(s)
    for i in range(len_s):
        char = s[i]
        if char.isspace() and (i < len(s)-1):
            continue

        if char.isdigit():
            currentNum += char

        if char in operators or (i == len(s)-1):
            if currentOp == "+":
                stack.append(int(currentNum))
            elif currentOp == "-":
                stack.append(-int(currentNum))
            elif currentOp == "*":
                stack[-1] = stack[-1]*int(currentNum)
            elif currentOp == "/":
                stack[-1] = div(stack[-1], int(currentNum))
            currentNum = ''
            currentOp = char
    return sum(stack)

expr = input()
op = 0
fi = ""
se = ""

if "<" in expr:
    if "=" in expr:
        op = 1
    else:
        op = 2
elif ">" in expr:
    if "=" in expr:
        op = 3
    else:
        op = 4
else:
    op = 5

if op == 1 or op == 2:
    for i in range(len(expr)):
        if expr[i] == "<":
            fi = expr[:i]
            if op == 1:
                se = expr[i+2:]
            else:
                se = expr[i+1:]
            break
elif op == 3 or op == 4:
    for i in range(len(expr)):
        if expr[i] == ">":
            fi = expr[:i]
            if op == 3:
                se = expr[i+2:]
            else:
                se = expr[i+1:]
            break
else:
    for i in range(len(expr)):
        if expr[i] == "=":
            fi = expr[:i]
            se = expr[i+1:]
            break

if __name__ == "__main__":
    fii = calc(fi)
    see = calc(se)

    f = False
    if op == 1:
        if fii <= see:
            f = True
    elif op == 2:
        if fii < see:
            f = True
    elif op == 3:
        if fii >= see:
            f = True
    elif op == 4:
        if fii > see:
            f = True
    else:
        if fii == see:
            f = True

    print("FALSE") if f == True else print("TRUE")