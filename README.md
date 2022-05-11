In our code, a player object is created from each line read. The Player object saves the basic properties of the players. PlayerNodes are made from the Player object, and it keeps the PlayerNode's properties and the Player's connections in the Binary Search Tree. PlayerNodes are stored in the Hash Table (also, the location of each object is stored in the vector for easy access) 

We are checking if there is a teammate relationship with the previously created Players for each newly created Player. Then, the operations of synchronizing the connection Binary search trees of the nodes of the same Player for different years are done in O(|V|^2) time.

Case 0A's is time comlexity O(1), due to it only looking at one if condition.

Case 0B's is time comlexity O(1), due to it only looking at one if condition.

Case 1,PlayerNodes whose pointers are stored inside the vector is suppressed to reflect the input file O(|V|).

Case 2A, The average time constant for the Player node objects of the named player to be found in the hash table, the worst case, is hypothetically O(|V|). The discovered nodes are transferred to the vector and sorted by vector insertion only by looking at the years. We use Insertion Sort because the input file we are working with is short, and the constant factor of the insertion sort is less than algorithms like merge sort. However, the worst case of the sorting algorithm is hypothetically O(|V|^2).

Case 2B, The average time is O(1) when we find a player object in the hash table. However, if this object does not exist, our worst-case scenario happens O (|V|) time. The nodes found are discarded depending on their teams and sorted with the vector via insertion sort. We use Insertion Sort because the input file we study is short, and the insertion sort's constant factor is less than algorithms such as merge sort. However, our worst-case scenario is still O(|V|^2) in the Insertion sort. After we sort our vectors, we print them in a sorted way.

Case 3, The vector with the PlayerNodes' points is checked for the given team. If the team plays, it is added to the newly created vector. While browsing the vector containing the PlayerNodes, it is checked whether the player playing in the specified team exists in the created vector, and if there is, the number of plays is increased by one. In this operation, the worst case happens when every player in the input is in the specified team. In this case, the insertion is O(|V|^2) like the sort algorithm. Then the output vector is sorted by insertion sort. In this case, in the worst case, tight is O(|V|^2) across the upper bound.

Case 4A, For this case, we found the shortest path between the two-player. The algorithm that determines the worst case for this case is BFS. The worst case of the BFS algorithm in the code we wrote is O(|V|+|E|)

Case 4B, This case is very similar to Case 4A. BFS is advanced with each player's connection during the search and with the relationships in the specified team. The algorithm that determines the worst case for this case is BFS, and the worst case is O(|V|+|E|).
