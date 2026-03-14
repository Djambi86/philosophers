*This project has been created as part of the 42 curriculum by dabdulka*

## PHILOSOPHERS!!!!

## Description

Yo Yo Yo! First of all, screw Norminette 
Second of all, this is my first time writing a README, kinda nervous, not gonna lie. 
Now let's get to Business. In this project, I got thrown into 2 things -> threads and mutexes.
You may ask what are they? Well, I don't know eiter... joking.
Let's start with threads:
Threads are basically workers that you hire, for your program, that work at the same *time (well, kinda, I will explain later)
I Think we all know how a programm works usually, it goes step by step, line by line, so there is only one worker
	Without threads:
	- Do function A
	- Finish A, Then do function B
	- Finish B, Then do function C
and when it wants to do the same function again, it adds another "then do"

Now this is where threads come in, with them you can run the functions at the same *time (again will explain later)
	With threads:
	- function A
	- function A is still running, activate function B
	- function A and B are still running, activate function C
Now all three functions are running at the same time and you have to *join (will explain in person) the threads at the end, so all 3 return something.
But that can sometimes be bad.
Imagine you have a Bank balance flag, and that balance is 300$
And you have 3 functions, A, B and C
A wants to deposit 200$
B wants to deposit 300$
C wants to deposit 400$
Now because of threads the 3 functions, are looking at the bank balance at the same time.
That means all 3 functions will see the balance 300$, instead of the updated balance that it should have been.
Now depending on which function finishes first, it will have either a balance of 200, 300 or 400 Euros,
instead of the summed up balance of 1200$ that it should have.
How do we solve this? With MUTEXES ofcourse, that is why they are here.

What is a mutex?
FROM GOOGLE: A mutex (short for mutual exclusion) is a synchronization tool used in programming to prevent multiple threads from accessing the same shared resource at the same time. 🔒
Do you now get where I am going with this?
With mutexes, we can implement a lock of the acces of the balance, in each functions start, so that
the other 2 functions, cannot acces the balance yet.
And with mutexes WE choose when we unlock that lock.
That way the balance can stay up to date.
Wohohoho, be honest, did I explain it very well, or did I explain it exceptionally well!

So this is where the Philosophers come in.
Imagine we have 5 philosophers, and these 6 philosophers need to eat, sleep and think
by a round table, in a limited time, or they will DIE,
On that table is 1 spaghetti plate, for each philosopher,
each one of them have 1 fork, but to eat spaghetti they need 2 forks.
So they decide that the philosophers will borrow the second needed fork, from their sit neighbour.
But that means, 2 of the philosophers would need to wait, till the others finish
and only then can they eat, if for example, the other 3 would eat too long
and the limited time is over, the 2 that did not eat, WILL DIE.
Or if the philosophers sleep for too long, THEY WILL DIE
Or if they think for too long, THEY WILL ALSO DIE
So in this project, I have to write a code, that will keep this philosophers alive for ever,
if the given arguments allow it.
Everything else, I will explain in person.

Now to go back to my 2 asterisks above. It really depends if functions will run at the same time with threads. Because threads use the CPU cores.
That means if you have 2 CPU cores then the 2 functions will run at the same time
CORE 1 -> thread A running
CORE 2 -> thread B running
because one function is run by 1 cpu core, so they split it.

But what if the CPU only has 1 core?
Then the threads do NOT truly run at the same time.
Instead, the operating system switches between them very quickly.
	What happens in 1 core CPU with threads:
	- thread A runs for a tiny bit
	- thread B runs
	- Thread A runs again
	- Thread B runs again
This happens SOOOO quick, that it looks like, they are run at the same time.
Huuuuu, now that is all, everything else I will explain in person, if there are questions.
Now lets get to instructions

## Instructions

To run this project, firstly go into the philo/ folder, after that just execute Make my fellow comrade.
Now you can run the program with the following arguments.

./philosophers	◦ number_of_philosophers: The number of philosophers and also the number
		of forks.
		◦ time_to_die (in milliseconds): If a philosopher has not started eating within
		time_to_die milliseconds since the start of their last meal or the start of the
		simulation, they die.
		◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
		During that time, they will need to hold two forks.
		◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
		◦ number_of_times_each_philosopher_must_eat (optional argument): If all
		philosophers have eaten at least number_of_times_each_philosopher_must_eat
		times, the simulation stops. If not specified, the simulation stops when a
		philosopher dies.
## Resources

- > Here I gotta tell you what sources or references I looked up or something.
Here they are:
	- My brain
	- My Redbull
	- My lack of sleep
	- Shower thoughts
To be honest I mostly used Chatgpt so that it explains to me what all these new functions are,
and how they are used, but sometimes it explained it so difficult
that I just googled it, and read some thoughts on stackoverflow.
Other than that, I watched a little bit of the Oceano video,
about the philosophers project.
