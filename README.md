# proof-reading-bot
Developed a system to analyze and check for plagiarism in documents submitted through multiple clients connected over Wi-fi using the concept of socket programming with C language. The core objective of this project is to develop a platform where computer aided text-based assignments or exams submitted by students can be easily accessible on the administrator’s system and afterwards, administrator would be able to observe the plagiarism.

OBJECTIVE
The core objective of this project is to develop a platform where computer aided text-based assignments or exams submitted by students can be easily accessible on the administrator’s (here it will be Professor) system and afterwards, administrator (Professor) would be able to observe the plagiarismamong the assignment submissions and also, would be able to notice the extent of copy-paste with the help of graphs.

GUI AND SOCKET PROGRAMMING
In order to develop Graphical User Interface, Gtk+ library is used, which let client to enter data into the widgets provided on the interface. After which, the following data is being redirected to the administrator’s system via socket programming, where on both client and server end points, socket is created and over the socket data can be transferred in a duplex transmission mode. Multiple clients (students) can able to interact with single server (administrator) over a remote system, which will further stored into file at the administrator’s end point.

RABIN-KARP ALGORITHM
Rabin-Karp algorithm is a search algorithm that searches for a substring pattern in a text using hashing. It is very effective for multi-pattern matching words. This algorithm is good since it has a determination for syllable cuts (K-grams). Rabin-Karp relies on a hash function to determine the percentage of plagiarism. The hash function determines the feature value of a particular syllable fraction.

ALGORITHM FOR TRANSFERRING DOCUMENTS FROM CLIENT’S SIDE TO SERVER’S SIDE
The steps involved in establishing a socket on the client side are as follows:
1. Create a socket 
2. Connect the socket to the address of the server 
3. Send and receive data. There are a number of ways to do this, but the simplest is to use the read() and write() system calls.
The steps involved in establishing a socket on the server side are as follows:
1. Create a socket 
2. Bind the socket to an address using the bind() system call. For a server socket on the Internet, an address consists of a port number on the host machine.
3.Listen for connections 
4. Accept a connection with the accept() system call.
5. Send and receive data


ALGORITHM FOR DOCUMENTS COMPARISON
1. Users submit the assignment.
2. Document fetched and words stored in an array
3. Punctuation marks are removed and words converted to lower case.
4. Stop words (like is, a, the, etc) are removed.
	4.1  For i←0 to nowords
		4.1.1  For k←0 to no of stop words
			4.1.1.1 if(strcmp(words[i],stopword[k])==0)
				4.1.1.1.1 remove words[i]
5. Assign hash values to remaining words using hash function.
	5.1 For i←0 to no of words
		5.1.1 m=strlen(word)
		5.1.2 For k←1 to m
			5.1.2.1 hash[i]=hash[i]+(q*pow(p,m-k))
				where q= Ascii code of the character
				p=large prime number
				m= length of the word
				k= characters
6. Store the values in a file.
7. Repeat 2-6 for every submission.
8. Percentage of similarity between documents is calculated and displayed.
