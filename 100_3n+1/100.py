import sys 

def cycle(n):
    length = 1
    while n != 1:
        if n%2 == 1:# odd
            n = 3*n + 1
        else:# even
            n = n // 2
        length += 1
    
    return length

def main():
    #if we need to read the first number
    #n = int(sys.stdin.readline())
    
    while 1:
        try:
            line = input()
        except EOFError:
            break
        
        line = line.rstrip()
        x, y = map(int, line.split()[:2])
        x, y = min(x, y), max(x, y)
        maximal = max([cycle(i) for i in range(x, y + 1)])

        print('{} {} {}'.format(x, y, maximal))


if __name__ == "__main__":
    main()
    exit(0)
