# hashtable

A naive implementation of an hashtable.

Features:
	
	-	Create an hastable of a given size.
	-	Insert/Update/Delete key value pair.
	-	Get pointer on value with a key.
	-	Handle collision.
	-	Rehash map and resize (auto call when current size is not enough to put a new pair).
	-	2 hash algorithms
			sdbm (from http://www.cse.yorku.ca/~oz/hash.html)
			fnv1a (found here http://programmers.stackexchange.com/questions/49550/which-hashing-algorithm-is-best-for-uniqueness-and-speed)
	-	A few tests :
			bigtest.txt => 335 K words
			bigtest2.txt => 7 K words reapeted to 5M entry
			test.txt => 23 K words
			test2.txt => 15 words