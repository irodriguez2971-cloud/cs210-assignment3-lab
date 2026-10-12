#Reflection

1. Why does concat only need to work between two lists of the same representation? What would
you have to do differently, or what would go wrong, if you tried to make it work between a
LinkedList and an ArrayList?

Answer: The reason it works betweens the same representation is because each class has it data stored differently.
So for example, in this code (in general as well), 'ArrayList' uses an array of pointers, while 'Linked' uses linked 
nodes. So my way uses a dyanamic_cast to reject mismatch types safely.


2. Walk through reverse() on your linked list: name the three pointers you need alive at once,
   and explain why losing track of any one of them mid-loop corrupts the list.

Answer: my reverse() method uses 3 pointers. This includes, previous, next, and current. Current
is the node I am working on, previous is obviously the node behind it (the previous one). Next saves the rest.
If I lose one of the pointers, I could lose part of the list.

3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
   position in each, and what does your implementation do if a caller passes a position outside
   it?

Answer:For addAnywhere(), the position can be from 0 to size_. Position size_ is allowed, because
it adds the item at the end. For deleteAnywhere(), the position can be from 0 to size_ - 1. If the position is
invalid, the code prints an error message and does nothing. 

4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if
   LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
   if you added one back?

Answer:
addFront() and deleteFront() use the 1st node, so no need to search through list.
concat() adds one list to the end, so my code has to go through last until last node is found.
A tail pointer would make this fast, but I'd have to update the tail whenever it changes.

5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.

Answer:
When I add an item in the middle of the array, I move the existing items one space to the right.
I start at the end and move backward, so I wouldn't need to erase values, but rather I would have to just
put them into an open space.


6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
   play, and explain what would visibly break in the game if that call were missing

Answer: 
The direction changes on this line "table->reverse();"
Without this, the player order would stay the same. The program is going to say
a reverse card was played without changing the actual order. 