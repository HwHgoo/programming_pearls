#### Problem 1


#### Problem 2

```c
#define SHIFT 5
#define MASK 0x1F
void set(int i){map[i >> SHIFT] |= (1 << (i & MASK));}
int check(int i){return map[i >> SHIFT] & (1 << (i & MASK));}
```

#### Problem 3

- bitmap faster than quicksort


#### Problem 4

My thinking:

&nbsp;&nbsp; In a while loop, each time get a random number(< n), check it, if it's already in the set,break otherwise, write into file and bitmap.


##### code:

```c

```
