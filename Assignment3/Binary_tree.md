### Pre order trasversal
 - Process the node
 - left child(smaller)
 - right child(greater)

### In order trasversal
 - left child(smaller)
 - process the node
 - right child (greater)

 ### Post order Traversal
 - left
 - right
 - process

### Prepare Tree
 - smaller child
    - `2(i) + 1` th element in array
 - greater child
    - `2(i) + 2` th element in array
 - 0 based indexing
 
 ### Questions
  - Left, Right, Top, Bottom views of Binary Trees
  - Perimeter view
  - zig-zag traversal
         2
1               3
            4       5

starting at 2
 - we will explore the smaller child 1
    - since 1 hase know left child we will process 1 and since 1 has no right child we will return and go to node 2
 - in node 2 left child has bee explored , so we process node 2 and then go to its greater child
 - in node 3 we go to its smaller child (4)
    - in node 4 has no smaller child so 4 is processed and then it has no right node so it is returned
    - then node 3 is processed and then goes to node 5 
    - since node 5 has no smaller child it gets processed and returned
 - `1 2 4 3 5`
