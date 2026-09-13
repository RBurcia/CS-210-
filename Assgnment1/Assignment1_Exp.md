#Technical Explanation:

IMPLEMENTATION OF HASHMAP:
  The program uses a HashMap with a time complexity of O(n); this means it takes "n" steps to find the target, based on the length of the array/hashmap.
  This is done in the program by using a single for loop that checks whether the target is at the current index; if not, it is mapped onto the hashmap, and we move on to the next
  iteration of the loop. We keep mapping and checking until the target is the same as the number at the index. When found, we return both the two indices that add up to our target

  Testing:
  1.) First test case verifies whether the algorithm can find the closest indices, same as our initial given example. Here we see that by using a double for loop it takes a "short
      path" and assumes indices 0 and 1 can make up the target, which is 10.
  
  2.) The second test case was simple, and it was just to verify if it acknowledged there was "No Solution".

  3.) The third test case was just to prove that both will produce the same indices if the sum of the targets was only possible given at the end of the array/ hashmap.

  4.) The fourth test case is to test for efficiency when finding the needed sum of the target. During the hashmap method, it finds the indices at "[0, 5]"; this is the fastest method in finding our
      initial two sum question. How we accomplish this is by utilizing one for loop to linearly search, instantiate our needed value, and if the needed value is NOT found in the hashmap, to append it.
      This is the fastest way since we only require one for loop and the appending and search functions are instantaneous, making our time searching just O(n).

  
IMPLEMENTATION OF BRUTE FORCE:
  The Program uses a "Brute Force" method that produces a time complexity of O(n^2). What that means is that it uses one for loop to subtract from the target on the index, and uses the second
  for loop to find a number and compares the needed result of the for loop. The reason why it's a brute force method is because we are going through the array n^2 to search and compare.

  Testing:
  1.) First test case verifies whether the algorithm can find the closest indices, same as our initial given example. Here we see that by utilizing the hashmap, it saves time searching linearly
      by using index 0 "number 5" and adding it to itself.

  2.) The second test case was simple, and it was just to verify if it acknowledged there was "No Solution".

  3.) The third test case was just to prove that both will produce the same indices if the sum of the targets were only possible given at the end of the array/ hashmap.

  4.) The fourth test case is to test for efficiency when finding the needed sum of the target. During the brute force method, we see that it finds the indices relatively close "[2, 3]". Although mathematically
      it took the longest route possible, considering it found the appropriate "needed" in 2 loops around the length of the array and 3 additional loops around the length of the array to confirm that the number
      in the index was the needed. Essentially making our time searching for the answere O((2*n)*(3*n)) == O(6n^2) == O(n^2).

