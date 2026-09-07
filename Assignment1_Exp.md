#Technical Explanation:

IMPLEMENTATION OF HASHMAP:
  The program uses a HashMap with a time complexity of O(n); this means it takes "n" steps to find the target, based on the length of the array/hashmap.
  This is done in the program by using a single for loop that checks whether the target is at the current index; if not, it is mapped onto the hashmap, and we move on to the next
  iteration of the loop. We keep mapping and checking until the target is the same as the number at the index. When found, we return both the two indices that add up to our target
  
IMPLEMENTATION OF BRUTE FORCE:
  The Program uses a "Brute Force" method that produces a time complexity of O(n^2), what that means is that it uses one for loop to subtract from the target on the index, and uses the second
  for loop to find a number compares the needed result of the for loop. The reason why its a brute force method is because we are going through the array n^2 to search and compare.
