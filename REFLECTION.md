1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one?
   Name exactly what each one frees, and name the two new calls back in the program responsible
   for putting them on the heap in the first place.
Answer: The reason it takes two separate delete cells is that there were two separate objects
created on the heap, in which you have to call delete on it yourself. Hence, delete doomed→data
frees the object created by new int(...) or new Data(...), and this is located in main.cpp. On the 
other hand, delete doomed frees the node created by newNode<T>(value) inside addFront(). This is shown
in the "Why this matters" of the lab assignment, page 9.

2. ArrayList never had a destructor before today. Explain, in your own words, why switching
   from T data[CAPACITY] to T* data [CAPACITY] is what made a destructor necessary, and what
   would happen if you forgot to write one. Would you get a compiler error? Why or why not?
The array now stores pointers, which are variables that hold memory addresses, instead of 
storing the objects directly. Since the list has ownership, its destructors must free those 
objects. Without the destructor, the program will still compile, but leaks memory because 
raw pointers don't automatically delete the objects they point to.

3. search() and addFront() both take a T*, but they treat that pointer completely differently.
   Explain the difference in terms of ownership: which one is allowed to delete what you hand it,
   and which one is never allowed to?
addFront() takes ownership, so the list becomes responsible for deleting the object. search()
only uses the pointer to compare values and never takes ownership or deletes the object.

4. You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without
   changing a single line there. What two mechanisms, by name, made that possible?
The two mechanisms are inheritance from :public List<T>. In addition, there is runtime polymorphism.
Both classes follow the List<T> ADT. Their virtual methods let the program run the correct execution for 
the actual list type.

5. Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
   thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
   your own words and without copying the guide’s wording, the smallest example you can think
   of where leaving it out would cause a real problem.
I chose virtual, because as explained in question 4, it lets a List<T> pointer calls the actual 
list's version of a method. For example, without a virtual destructor in List<T>, deleting an
ArrayList through a List<T> pointer causes undefined behavior, and its stored objects may not be
freed.