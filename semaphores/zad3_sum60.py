from threading import Semaphore, Thread

# Constants
OPEN = 1
CLOSE = 0

# Global variables
A = 0; B = 0; C = 3

# Semaphores
semP1 = Semaphore(OPEN)
semP2 = Semaphore(CLOSE)
semP3 = Semaphore(CLOSE)
semP4 = Semaphore(CLOSE)

def threadP1():
    global A; global B; global C
    
    # Perform calculations
    semP1.acquire()
    A = 10
    B = B + 5
    C = C + A

    # Go to thrid operation
    print("Thread P1 is done...")
    semP3.release() 

def threadP2():
    global A; global B; global C
    
    # Perform calculations
    semP2.acquire()
    B = B + C
    A = A + B

    print("Thread P2 is done...")

def threadP3():
    global A; global B; global C

    # Perform calculations
    semP3.acquire()
    C = B + 10
    A = 2 * A
    B = B + A

    # Go to second fourth
    print("Thread P3 is done...")
    semP4.release()

def threadP4():
    global A; global B; global C

    # Print total sum
    semP4.acquire()
    print("Sum result: ",A," + ",B," + ",C," = ",(A + B + C))
    
    # Go to second operation
    print("Thread P4 is done...")
    semP2.release()

threads = [
    Thread(target=threadP1),
    Thread(target=threadP2),
    Thread(target=threadP3),
    Thread(target=threadP4),
]

for thread in threads:
    thread.start()
for thread in threads:
    thread.join()
print("All done")