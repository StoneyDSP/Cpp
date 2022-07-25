# Cpp
C++ Tools

*Please note; if this app/code is any interest to you in it's presently very unfinished state, then you may wish to keep an eye on it over time (why not hit "follow" :) ) as this codebase and it's functions is likely to change, possibly quite a bit, as I progress with it*

# ConsoleApplication
A generic console application (ConsoleApplication.cpp) with some "imitation" classes of otherwise typical C++ objects, which print all of their functions to the terminal window, reporting such details as their memory address, size in bytes, which constructor they are created from (default, initialized, copy or move constructed, etc) and other useful information. Ideal for testing algorithms at a rudimentary/fundamental level, for example to check if (and where) new memory allocations are happening within your test code - very interesting when constructing or even when simply adding one value to another... - and keeping track of the size and line-for-line performance of your test code.

# Before we begin...

Coffee! That's how I get things done!! If you'd like to see me get more things done, please kindly consider <a href="https://www.patreon.com/bePatron?u=8549187" data-patreon-widget-type="become-patron-button">buying me a coffee</a> or two ;)

<p align="center">
 <a href= "https://paypal.me/StoneyDSPAudio?country.x=ES&locale.x=en_US"><img src="https://www.paypalobjects.com/en_US/i/btn/btn_donate_SM.gif"/></a>
</p>

<p align="center">
 <a href= "https://twitter.com/Stoney_DSP/"><img src="https://github.com/StoneyDSP/StoneyDSP/blob/a075caeedffe23b2733ee38b12f9800f62aab9c2/Assets/twitter.png"/></a>
 <a href= "https://www.instagram.com/stoney.d.s.p/"><img src="https://github.com/StoneyDSP/StoneyDSP/blob/2253d684ba99e6c072353a94b49315162c381406/Assets/instagram.png"/></a>
 <a href= "https://www.facebook.com/StoneyDSP.Audio/"><img src="https://github.com/StoneyDSP/StoneyDSP/blob/9608562b09ee2708affd0c31117fc25a235672d9/Assets/facebook.png"/></a>
</p>


The initial idea was to make a class in it's own header file which simply wraps an in-built type (floats, doubles, etc) with all of it's possible operators being overloaded to report all operations to the console. Being predominantly a self-learner of C++ myself, this turned out to be incredibly eye-opening beyond my expectations. I decided to share alike in the spirit of helping other self-learners to enable themeselves to level up a bit - let's face it, C++ is an advanced and deep language; it can be extremely frustrating trying to find answers to some basic, fundamental questions about how C++ works, even regarding the basic bread-and-butter operators such as "+="...

# How to use it?

Grab the ConsoleApplication directory, and open "ConsoleApplication.cpp" in your favourite IDE. Hit "run and debug", or similar. Whichever algorithms I've been testing most lately should run in the console (hit "enter" when prompted, to advance to the next step). The console will report exactly what is being constructed, how, and where to/where from (if copying/moving a value, for example) and all basic operators shall do likewise. You can do things like initialize a new value, add it to an existing value, and observe whether you are simply adding two values together, or actually constructing a whole new one, using it's value, then destroying it(demo below)... not to mention, to check the size on disk for each object along the way, or the memory location you are calling to/from. Many ways to catch what the compiler is really doing with your instructions.

Did you know that an empty class with only a constructor takes one byte in memory? Or that if you give that class a data member (like a float), it has the exact same size on disk as that member? How about constructing a float with an initial value of Pi... that Pi value actually has it's own memory address and size, as reported to the console. Construct a second float with an initial value of Pi... it will call Pi from the exact same memory address as the first float did! Then construct a third float with an initial value of, say, 2.0F... which is now stored in the same memory address where Pi previously was!

How about we try adding two of our floats together... Just how much difference is there in using the "+=" operator, compared to the "+" operator? This testbed won't report the exact machine instructions (your IDE should be capable of going that deep), but it WILL print all assignments, allocations, constructions, destructions and other very interesting info to the console.

At time of writing, there are a few parts currently in flux while I finalize them. For the moment, take a look at "Float.h" which overloads almost every possible operator to report itself to the console. In the ConsoleApp.cpp, try calling a new float value named "a". Where usually we would write:

    int main()
    {
        float a;
    }

To use the test version of floats which reports it's activity to the console, just capitalize the first value - this will call the class I've built in "Float.h" - just a simple wrapper around a standard float.

    int main()
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


As we can see, we constructed a Float using it's default constructor (since no values were passed in during creation). The class has a member with size of a float, at the same address as the class itself. Single responsibility principle.

Let's build that Float again, but this time with an initial value of Pi:

    int main()
    {
        Float a = 3.14159;
    };

Terminal out:

    008FF8B8 - class Float - Called Initialized Constructor from address 008FF898 = 3.14159!
    008FF8B8 - class Float - Passed assertion check!
    008FF8B8 - class Float - Initialized Constructed!
    008FF8B8 - class Float - initialValue = 3.14159

    008FF8B8 - class Float - info:

    008FF8B8 - name - class Float
    008FF8B8 - raw name - .?AVFloat@@
    008FF8B8 - hash code - 2243300081
    008FF8B8 - value = 3.14159
    008FF8B8 - &value = 008FF8B8
    008FF8B8 - size in bytes = 4

    008FF8B8 - member type - float
    008FF8B8 - member raw name - .M
    008FF8B8 - member hash code - 3356228888
    008FF8B8 - member value = 3.14159
    008FF8B8 - member &value = 008FF8B8
    008FF8B8 - member size in bytes = 4  

Cool. For our next Float, it shall be initialized to the value of the previous Float (which we named "a" in our previous example):

    int main()
    {
        Float a = 3.14159F; // see previous example for terminal output...
    
        Float b = a;
    }

Terminal output for "Float b = a":

    008FF8B4 - class Float - Called Copy Constructor from address 008FF8B8 = 3.14159!
    008FF8B4 - class Float - Called Copy Assignment Operator [=] from address 008FF8B8 = 3.14159
    008FF8B4 - class Float - Passed assertion check!
    008FF8B4 - class Float - Copy Constructed!
    008FF8B4 - class Float - newValue = 3.14159

    008FF8B4 - class Float - info:

    008FF8B4 - name - class Float
    008FF8B4 - raw name - .?AVFloat@@
    008FF8B4 - hash code - 2243300081
    008FF8B4 - value = 3.14159
    008FF8B4 - &value = 008FF8B4
    008FF8B4 - size in bytes = 4

    008FF8B4 - member type - float
    008FF8B4 - member raw name - .M
    008FF8B4 - member hash code - 3356228888
    008FF8B4 - member value = 3.14159
    008FF8B4 - member &value = 008FF8B4
    008FF8B4 - member size in bytes = 4 

Time for some basic maths...

    int main()
    {
        Float a = 3.14159F; // see previous example
    
        Float B = a; // see previous example
    
        Float c = a + b;
    }

Output for "Float c = a + b":

    008FF894 - class Float - Called Copy Constructor from address 008FF8B8 = 3.14159!
    008FF894 - class Float - Called Copy Assignment Operator [=] from address 008FF8B8 = 3.14159
    008FF894 - class Float - Passed assertion check!
    008FF894 - class Float - Copy Constructed!
    008FF894 - class Float - newValue = 3.14159

    008FF894 - class Float - info:

    008FF894 - name - class Float
    008FF894 - raw name - .?AVFloat@@
    008FF894 - hash code - 2243300081
    008FF894 - value = 3.14159
    008FF894 - &value = 008FF894
    008FF894 - size in bytes = 4

    008FF894 - member type - float
    008FF894 - member raw name - .M
    008FF894 - member hash code - 3356228888
    008FF894 - member value = 3.14159
    008FF894 - member &value = 008FF894
    008FF894 - member size in bytes = 4


    008FF894 - class Float - Called Addition Allocation Operator [+] with address 008FF8B4
    008FF894 - class Float - Called Addition Assignment Operator [+=] with address 008FF8B4 = 3.14159
    008FF894 - class Float - 3.14159 += 3.14159 = 6.28318

    008FF8AC - class Float - Called Move Constructor from address 008FF894 = 6.28318!
    008FF8AC - class Float - Passed assertion check!
    008FF8AC - class Float - Move Constructed!
    008FF8AC - class Float = 6.28318

    008FF8AC - class Float - info:

    008FF8AC - name - class Float
    008FF8AC - raw name - .?AVFloat@@
    008FF8AC - hash code - 2243300081
    008FF8AC - value = 6.28318
    008FF8AC - &value = 008FF8AC
    008FF8AC - size in bytes = 4

    008FF8AC - member type - float
    008FF8AC - member raw name - .M
    008FF8AC - member hash code - 3356228888
    008FF8AC - member value = 6.28318
    008FF8AC - member &value = 008FF8AC
    008FF8AC - member size in bytes = 4


    008FF894 - class Float - Called Destructor!
    008FF894 - class Float - Destroyed!
    008FF894 - class Float = 0
  
  
Wow! So a whole Float got created, used, and then simply destroyed! Hmmm. What if we try the same thing, with the other operator ("+=")?  
  
    {
        Float a = 3.14159F; // see previous example
    
        Float B = a; // see previous example
    
        Float c = a + b; // see previous example
    
        Float d = a += b;
    }

Terminal output for "Float d = a += b":

    008FF8B8 - class Float - Called Addition Assignment Operator [+=] with address 008FF8B4 = 3.14159
    008FF8B8 - class Float - 3.14159 += 3.14159 = 6.28318

    008FF8B0 - class Float - Called Copy Constructor from address 008FF8B8 = 6.28318!
    008FF8B0 - class Float - Called Copy Assignment Operator [=] from address 008FF8B8 = 6.28318
    008FF8B0 - class Float - Passed assertion check!
    008FF8B0 - class Float - Copy Constructed!
    008FF8B0 - class Float - newValue = 6.28318

    008FF8B0 - class Float - info:

    008FF8B0 - name - class Float
    008FF8B0 - raw name - .?AVFloat@@
    008FF8B0 - hash code - 2243300081
    008FF8B0 - value = 6.28318
    008FF8B0 - &value = 008FF8B0
    008FF8B0 - size in bytes = 4

    008FF8B0 - member type - float
    008FF8B0 - member raw name - .M
    008FF8B0 - member hash code - 3356228888
    008FF8B0 - member value = 6.28318
    008FF8B0 - member &value = 008FF8B0
    008FF8B0 - member size in bytes = 4  
  

Much better - no unneccesary nested function calls. No unneccessary allocations :)  

What about when our main() function goes out of scope? Everything gets destroyed (in reverse order), but what are the final values?

    008FF8B8 - class Float - Called Destructor!
    008FF8B8 - class Float - Destroyed!
    008FF8B8 - class Float = 6.28318

    008FF8B4 - class Float - Called Destructor!
    008FF8B4 - class Float - Destroyed!
    008FF8B4 - class Float = 6.28318

    008FF8AC - class Float - Called Destructor!
    008FF8AC - class Float - Destroyed!
    008FF8AC - class Float = 3.14159

    008FF8B0 - class Float - Called Destructor!
    008FF8B0 - class Float - Destroyed!
    008FF8B0 - class Float = 6.28318

Now, as of time of writing, I've been working on a base class called "Value" (in it's own header file, if you want to check it) - this CAN be called directly, but instead, I'm building child classes (check "Double") which derive several of their operator functions from the parent "Value", and implement others of their own. Eventually I'll have all basic types - Int, Float, Double, Bool etc - deriving common operator functions from Value, while implementing their own type-specific operators, like bitshifts and boolean comparisons, at child-class level.

I was highly frustrated trying to understand why the parent "Value" class would be constructed with an initial size of 4 bytes + it's member(s), instead of 1 byte like an empty class does. Turns out, "virtual" functions cause some kind of allocation at the base class level. Not currently sure if this is only when overriding in the child class, or some other reason... (note from future self: the answer is vtables)

But these are the kind of tools that will lead to answers for the inquisitive self-learner :)

# Before you go...

Coffee! That's how I get things done!! If you'd like to see me get more things done, please kindly consider <a href="https://www.patreon.com/bePatron?u=8549187" data-patreon-widget-type="become-patron-button">buying me a coffee</a> or two ;)

<p align="center">
 <a href= "https://paypal.me/StoneyDSPAudio?country.x=ES&locale.x=en_US"><img src="https://www.paypalobjects.com/en_US/i/btn/btn_donate_SM.gif"/></a>
</p>

<p align="center">
 <a href= "https://twitter.com/Stoney_DSP/"><img src="https://github.com/StoneyDSP/StoneyDSP/blob/a075caeedffe23b2733ee38b12f9800f62aab9c2/Assets/twitter.png"/></a>
 <a href= "https://www.instagram.com/stoney.d.s.p/"><img src="https://github.com/StoneyDSP/StoneyDSP/blob/2253d684ba99e6c072353a94b49315162c381406/Assets/instagram.png"/></a>
 <a href= "https://www.facebook.com/StoneyDSP.Audio/"><img src="https://github.com/StoneyDSP/StoneyDSP/blob/9608562b09ee2708affd0c31117fc25a235672d9/Assets/facebook.png"/></a>
</p>
