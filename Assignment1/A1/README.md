# DSA Assignment 1

# MakeFile
> makeall
 - running this command will give q1.out , q2.out , q3.out
 - Then run the following commands and give appropriate inputs
    - `./q1.out`
    - `./q2.out`
    - `./q3.out`

# Question 1:
This multi-file program is an implementation of a doubly-linked-list.

The command-line input corresponding to the various functionality is as follows:

1. Insert - to insert a node (containing data) at the end of the linked list.
> `insert <data>` 
2. Insert at - to insert a node (containing data) at any given position in the list.
> `insert_at <data> <index>`
3. Delete - to delete the node at the specified index
> `DELETE <index>`
4. Find - to find and display the index of the first occurence of the given element
> `find <elmt>`
5. Prune - deletes all odd-indexed nodes in the list
> `prune`
6. Print - prints all the data in the linked list in order
> `print`
7. Print reverse - prints all the data in the reverse order
> `print_reverse`
8. Get size - prints the no. of elements in the list
> `get_size`

Any other command (the commands are case-sensitive) will result in no action being taken.


# Question 2:
In this program, we implement the ADT of an n-dimensional complex number, i.e., a vector of n floating-point numbers.

The functionality of the ADT can be used as follows:

1. Addition - to add two n-dimensional complex numbers
> `ADD <n>`
 - `<n space-separated floating-point numbers for the first complex number>`
 - `<n space-separated floating-point numbers for the second complex number>`

2. Subtraction - to subtract one n-dimensional complex number from another
> `SUB <n>`
 - `<n space-separated floating-point numbers for the first complex number>`
 - `<n space-separated floating-point numbers for the second complex number>`

3. Magnitude - to find magnitude of the given complex number
> `MOD <n>`
 - `<n space-separated floating-point numbers denoting the complex number>`

4. Dot product - to find dot product of two given complex numbers
> `DOT <n>`
 - `<n space-separated floating-point numbers for the first complex number>`
 - `<n space-separated floating-point numbers for the second complex number>`

5. COS similarity - to find the cosine similarity of two given complex numbers
> `COS <n>`
 - `<n space-separated floating-point numbers for the first complex number>`
 - `<n space-separated floating-point numbers for the second complex number>`

To avoid naming conflicts with the math function cos(), the user-defined function has been named as COS().

All the above commands are case-sensitive.

# Question 3:
This multi-file program is the implementation of an ADT for a music player.

The functionality of the music player is as follows:

1. Add song - adds a song to the end of the playqueue
> `ADD_SONG <name of song> <name of artist> <duration of song>`
2. Remove song - removes song at specified index from the queue of the user
> `REMOVE_SONG <userName> <index>`
3. Play song - plays the first song in the play queue and removes it from the list
> `PLAY_SONG <userName>`
4. Get current song - to find the song that is currently playing
> `GET_SONG <userName>`
5. Add a user with given name
> `ADD_USER <name>`
6. Insert song - adds song to user queue  
> `INSERT_SONG <userName> <songName>`
7. Add song to the liked songs list of the user 
> `LIKE_SONG <userName> <songName>`
8. Remove song from the liked songs list of the user
> `UNLIKE_SONG <userName> <songName>`
9. Gives the number of common liked songs for both users 
> `COMPATIBILITY <userName1> <userName2>`
10. exit the program
> `EXIT`

All above commands are case-sensitive. In case any command other than the above are entered, the program will take no action and the user will again be allowed to enter an input command