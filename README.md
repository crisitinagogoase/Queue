# Queue
This exercise requires solving a puzzle presented in mysterious notes. The key is locked inside  desk, and WE needs to find the code to unlock it.

According to the message, "Tous les mythes sont les fondements de la réalité. Il suffit de continuer à les compter" (All myths are the foundations of reality. Just keep counting them). We recall a game, where we counted the occurrences of each character and associated them with unique codes based on their frequency of occurrence. These codes are written in binary, starting with a bit for the most frequent letter. All binary codes are unique for each character and increase with decreasing frequency.

The exercise has the following steps:

1. Storing the characters and their frequencies in a priority queue (implemented using an array). 
The priority queue has the following methods:

- enqueue(element): Adds an element to the priority queue.
- dequeueHighestPriority(): Removes the character with the highest number of occurrences.
- getHighestPriority(): Displays the character with the highest number of occurrences and its frequency.

2. Discover the binary code for each of the characters in the given message using the previously created priority queue.

3. Translate the message by summing the digits of the letter codes. For example, if T corresponds to 1, O corresponds to 100, U corresponds to 111, and S corresponds to 10, then "Tous" represents 110011110, and the final code is 6.

In summary, the exercise involves implementing a priority queue to store character frequencies, determining the binary codes for each character based on their frequency, and translating the message using the calculated codes.
