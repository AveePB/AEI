from threading import Semaphore, Thread
import time

# Constants
CLOSE = 0
OPEN = 1

# Semaphores
semA = Semaphore(CLOSE)
semB = Semaphore(CLOSE)
semC = Semaphore(OPEN)

def printA(ntimes):
    """Function printing A"""
    for _ in range(ntimes):
        # Print A
        semA.acquire()
        print('A', end="")

        # Go to B
        semB.release()
        time.sleep(1)


def printB(ntimes):
    """Function printing B"""
    for i in range(ntimes):
        # Print B
        semB.acquire()
        print('B', end="")
        
        # END (last B)
        if (i % 2):
            print(' ', end="")

        # Go to C
        semC.release()
        time.sleep(1)


def printC(ntimes):
    """Function printing C"""
    for i in range(ntimes):
        # Print C
        semC.acquire()
        print('C', end="")

        # First C (go to A)
        if (i % 2 == 0):
            semA.release()
            time.sleep(1)
        
        # Second C (got to B)
        else:
            semB.release()
            time.sleep(1)

how_many = 10
threads = [
    Thread(target=printA, args=(how_many,)), 
    Thread(target=printB, args=(2*how_many,)), 
    Thread(target=printC, args=(2*how_many,)),
]

for thread in threads:
    thread.start()
for thread in threads:
    thread.join()
print("\nAll done")