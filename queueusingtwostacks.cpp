front = []
back = []
def push_back():
    if back:
        return
    while front:
        item = front.pop(-1)
        back.append(item)


def enqueue(x):
    front.append(x)

def dequeue():
    push_back()
    back.pop(-1)




q = input()
for i in range(q):
    command_split = map(int, raw_input().split())
    if command_split[0] == 1:
        enqueue(command_split[1])
    elif command_split[0] == 2:
        dequeue()
    else:
        push_back()
        print back[-1]
