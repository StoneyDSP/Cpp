# Cpp
C++ Tools

# ConsoleApplication
A generic console application (ConsoleApplication.cpp) with some "imitation" classes of otherwise typical C++ objects, which print all of their functions to the terminal window, reporting such details as their memory address, size in bytes, which constructor they are created from (default, initialized, copy or move constructed, etc) and other useful information. Ideal for testing algorithms at a rudimentary/fundamental level, for example to check if (and where) new memory allocations are happening within your test code - very interesting when constructing or even when simply adding one value to another... - and keeping track of the size and line-for-line performance of your test code.

The initial idea was to make a class in it's own header file which simply wraps an in-built type (floats, doubles, etc) with all of it's possible operators being overloaded to report all operations to the console. Being predominantly a self-learner of C++ myself, this turned out to be incredibly eye-opening beyond my expectations. I decided to share alike in the spirit of helping other self-learners to enable themeselves to level up a bit - let's face it, C++ is an advanced and deep language; it can be extremely frustrating trying to find answers to some basic, fundamental questions about how C++ works, even regarding the basic bread-and-butter operators such as "+="...

How to use it?

Grab the ConsoleApplication directory, and open "ConsoleApplication.cpp" in your favourite IDE. Hit "run and debug", or similar. Whichever algorithms I've been testing most lately should run in the console (hit "enter" when prompted, to advance to the next step). The console will report exactly what is being constructed, how, and where to/where from (if copying/moving a value, for example) and all basic operators shall do likewise. You can do things like initialize a new value, add it to an existing value, and observe whether you are simply adding two values together, or actually constructing a whole new one, using it's value, then destroying it... not to mention, to check the size on disk for each object along the way, or the memory location you are calling to/from. Many ways to catch what the compiler is really doing with your instructions.

Did you know that an empty class with only a constructor takes one byte in memory? Or that if you give that class a data member (like a float), it has the exact same size on disk as that member? How about constructing a float with an initial value of Pi... that Pi value actually has it's own memory address and size, as reported to the console. Construct a second float with an initial value of Pi... it will call Pi from the exact same memory address as the first float did! Then construct a third float with an initial value of, say, 2.0F... which is now stored in the same memory address where Pi previously was!

How about we try adding two of our floats together... Just how much difference is there in using the "+=" operator, compared to the "+" operator? This testbed won't report the exact machine instructions (your IDE should be capable of going that deep), but it WILL print all assignments, allocations, constructions, destructions and other very interesting info to the console.

At time of writing, there are a few parts currently in flux while I finalize them. For the moment, take a look at "Float.h" which overloads almost every possible operator to report itself to the console. In the ConsoleApp.cpp, try calling a new float value named "a". Where usually we would write:

    {
        float a;
    }

To use the test version of floats which reports it's activity to the console, just capitalize the first value - this will call the class I've built in "Float.h" - just a simple wrapper around a standard float.

    {
        Float a;
    }

Terminal output of the above (may change with future revisions):

00BCF760 - class Float - Called Default Constructor!  
00BCF760 - class Float - Passed assertion check!  
00BCF760 - class Float - Default Constructed!  
00BCF760 - class Float - Value = 0  
  
00BCF760 - class Float - info:  

00BCF760 - name - class Float  
00BCF760 - raw name - .?AVFloat@@  
00BCF760 - hash code - 2243300081  
00BCF760 - value = 0  
00BCF760 - &value = 00BCF760  
00BCF760 - size in bytes = 4  

00BCF760 - member type - float  
00BCF760 - member raw name - .M  
00BCF760 - member hash code - 3356228888  
00BCF760 - member value = 0  
00BCF760 - member &value = 00BCF760  
00BCF760 - member size in bytes = 4  


As we can see, we constructed a Float using it's default constructor (since no values were passed in during creation). The class has a member of size <float>, at the same address as the class itself. Single responsibility principle.

Let's build another Float, this time with an initial value of Pi:

    {
        Float a = 3.14159;
    };

Terminal out:

012FF95C - class Float - Called Initialized Constructor from address 012FF950 = 3.14159!;
012FF95C - class Float - Passed assertion check!;
012FF95C - class Float - Initialized Constructed!;
012FF95C - class Float - initialValue = 3.14159;

012FF95C - class Float - info:;

012FF95C - name - class Float;
012FF95C - raw name - .?AVFloat@@;
012FF95C - hash code - 2243300081;
012FF95C - value = 3.14159;
012FF95C - &value = 012FF95C;
012FF95C - size in bytes = 4;

012FF95C - member type - float
012FF95C - member raw name - .M
012FF95C - member hash code - 3356228888
012FF95C - member value = 3.14159
012FF95C - member &value = 012FF95C
012FF95C - member size in bytes = 4

Our next Float shall be initialized to the value of a pre-existing Float (which we named "a" in our previous example:

{
    Float b = a;
}

Terminal output:

00FDF7F8 - class Float - Called Copy Constructor from address 012FF95C = 3.14159!
00FDF7F8 - class Float - Called Copy Assignment Operator [=] from address 012FF95C = 3.14159
00FDF7F8 - class Float - Passed assertion check!
00FDF7F8 - class Float - Copy Constructed!
00FDF7F8 - class Float - newValue = 3.14159

00FDF7F8 - class Float - info:

00FDF7F8 - name - class Float
00FDF7F8 - raw name - .?AVFloat@@
00FDF7F8 - hash code - 2243300081
00FDF7F8 - value = 3.14159
00FDF7F8 - &value = 00FDF7F8
00FDF7F8 - size in bytes = 4

00FDF7F8 - member type - float
00FDF7F8 - member raw name - .M
00FDF7F8 - member hash code - 3356228888
00FDF7F8 - member value = 3.14159
00FDF7F8 - member &value = 00FDF7F8
00FDF7F8 - member size in bytes = 4

Time for some basic maths...

{
    Float c = a + b;
}

Output:

0097F81C - class Float - Called Copy Constructor from address 0097F840 = 3.14159!
0097F81C - class Float - Called Copy Assignment Operator [=] from address 0097F840 = 3.14159
0097F81C - class Float - Passed assertion check!
0097F81C - class Float - Copy Constructed!
0097F81C - class Float - newValue = 3.14159

0097F81C - class Float - info:

0097F81C - name - class Float
0097F81C - raw name - .?AVFloat@@
0097F81C - hash code - 2243300081
0097F81C - value = 3.14159
0097F81C - &value = 0097F81C
0097F81C - size in bytes = 4

0097F81C - member type - float
0097F81C - member raw name - .M
0097F81C - member hash code - 3356228888
0097F81C - member value = 3.14159
0097F81C - member &value = 0097F81C
0097F81C - member size in bytes = 4


0097F81C - class Float * - Called Addition Allocation Operator [+] with address 0097F83C
0097F81C - class Float - Called Addition Assignment Operator [+=] with address 0097F83C = 3.14159
0097F81C - class Float - 3.14159 += 3.14159 = 6.28318

0097F834 - class Float - Called Move Constructor from address 0097F81C = 6.28318!
0097F834 - class Float - Passed assertion check!
0097F834 - class Float - Move Constructed!
0097F834 - class Float = 6.28318

0097F834 - class Float - info:

0097F834 - name - class Float
0097F834 - raw name - .?AVFloat@@
0097F834 - hash code - 2243300081
0097F834 - value = 6.28318
0097F834 - &value = 0097F834
0097F834 - size in bytes = 4

0097F834 - member type - float
0097F834 - member raw name - .M
0097F834 - member hash code - 3356228888
0097F834 - member value = 6.28318
0097F834 - member &value = 0097F834
0097F834 - member size in bytes = 4


0097F81C - class Float - Called Destructor!
0097F81C - class Float - Destroyed!
0097F81C - class Float = 0


What if we try the same thing, with the other operator ("+=")?

{
    Float d = a += b;
}

Terminal output:

0097F840 - class Float - Called Addition Assignment Operator [+=] with address 0097F83C = 3.14159
0097F840 - class Float - 3.14159 += 3.14159 = 6.28318

0097F838 - class Float - Called Copy Constructor from address 0097F840 = 6.28318!
0097F838 - class Float - Called Copy Assignment Operator [=] from address 0097F840 = 6.28318
0097F838 - class Float - Passed assertion check!
0097F838 - class Float - Copy Constructed!
0097F838 - class Float - newValue = 6.28318

0097F838 - class Float - info:

0097F838 - name - class Float
0097F838 - raw name - .?AVFloat@@
0097F838 - hash code - 2243300081
0097F838 - value = 6.28318
0097F838 - &value = 0097F838
0097F838 - size in bytes = 4

0097F838 - member type - float
0097F838 - member raw name - .M
0097F838 - member hash code - 3356228888
0097F838 - member value = 6.28318
0097F838 - member &value = 0097F838
0097F838 - member size in bytes = 4


Now, as of time of writing, I've been working on a base class called "Value" (in it's own header file, if you want to check it) - this CAN be called directly, but instead, I'm building child classes (check "Double") which derive several of their operator functions from the parent "Value", and implement others of their own.

I was highly frustrated trying to understand why the parent "Value" class would be constructed with an initial size of 4 bytes + it's member(s), instead of 1 byte like an empty class does. Turns out, "virtual" functions cause some kind of allocation at the base class level. Not currently sure if this is only when overriding in the child class, or some other reason...

But these are the kind of tools that will lead to answers for the inquisitve self-learner :)

