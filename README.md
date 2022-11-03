# TEMPERATURE CONVERSION

[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

# Table Of Contents
<p align="center">
  <a href="#Setup">Setup</a> •
  <a href="#Description">Description</a> •
  <a href="#Objectifs">Objectifs</a> •
  <a href="#Key-learnings">Key learnings</a> •
  <a href="#Installation">Installation</a> •
  <a href="#how-to-use">How To Use</a> 
</p>

# Setup
[(Back to top)](#table-of-contents)

* __Prerequisites__
    * The library is supported on Linux, macOS, FreeBSD, and Windows.
    * The following compilers are supported to compile both the library and the tests:
        * GCC 4.9+ (Can be relaxed to GCC 4.6+ when not using C++)
        * Clang 3.4+
        * MSVC 14+ (Included in Visual Studio 2015 or later)
* __Building from source__
    * First, install dependencies:
        * C/C++ compiler
        * Meson, Ninja
        * CMake (for subprojects)
        * pkg-config
        * libffi (libffi-dev)
        * libgit2 (libgit2-dev)
        * Other runtime dependencies will be bundled if they are not available on the system (BoxFort, debugbreak, klib, nanomsg, nanopb).
    * Clone this repository:
        * ```bash
            $ git clone --recursive https://github.com/Snaipe/Criterion
    * Then, run the following commands to build Criterion:
        * ```bash
            $ meson build
            $ ninja -C build
    * Installing the library and language files (Linux, macOS, FreeBSD)
Run with an elevated shell:
        * ```bash
            $ ninja -C build install
    * On Linux systems, update the dynamic linker runtime bindings:
        * ```bash
            $ ldconfig
    * Usage
        * To compile your tests with Criterion, you need to make sure to:
            * Add the include directory to the header search path
            * Install the library to your library search path
            * Link Criterion to your executable.

This should be all you need.
# Description
[(Back to top)](#table-of-contents)

* The purpose of this exercise is to write a program that converts temperatures from the Celsius scale to the
Fahrenheit scale, and vice-versa.
# Objectifs
[(Back to top)](#table-of-contents)

* write a program that converts temperatures from the Celsius scale to the
Fahrenheit scale, and vice-versa.
* Your program must read from its standard input (separated by one or more spaces):
    * a temperature
    * a scale
    * Any additional input must be ignored
* Results must be displayed within two columns, right-aligned with a padding of 16 com-
posed of spaces and a precision to the 1000th.
* exemple :
    ```
        $> ./my_convert_temp << EOF
        -10 Celsius
        EOF
                  14.000      Fahrenheit
        $> ./my_convert_temp << EOF
        46.400 Fahrenheit
                   8.000         Celsius
        EOF
    ```

# Key learnings
[(Back to top)](#table-of-contents)
## Convert from Celsius to Fahrenheit

* Temperature, whether of a body or an element, is calculated in Celsius or Fahrenheit units. Celsius is widely used in Europe while Fahrenheit is mostly used in countries across the Atlantic. The formula for converting from Celsius to Fahrenheit is a relatively complex calculation. Let's see how to apply it.

## The history of Celsius
* The thermodynamic temperature scale Fahrenheit was essentially used in all countries in the 18th and 19th centuries. It was created by the physicist of the same name in 1724. Gradually, the Celsius was imposed in front of the Fahrenheit, except in the American states. North America uses both scales equally.

## Converting from Celsius to Fahrenheit
* To convert a Celsius temperature to Fahrenheit, a formula is used that takes into account the melting point of ice. This point is evaluated at 0° Celsius and 32° Fahrenheit. This melting point of ice is therefore essential for the correspondence of these two thermodynamic scales. But that's not all, because to this formula it is necessary to include a fractional data of 9/5, that is to say the lump sum figure of 1.8. If we apply these data correctly we get the formula:

* __temperature Celsius = (temperature Fahrenheit - 32) / 1.8__
Let's try with a real temperature, like the temperature of the body for example, evaluated at 100° Fahrenheit. This gives us :
    *   __Celsius temperature = (100 - 32) / 1.8
    Celsius temperature = 68 / 1.8
    Celsius temperature = 37.7° C__

* Conversely, if we have a temperature in Celsius that we want to convert into a temperature in Fahrenheit, we must proceed with the __reverse formula__. Let's take for example a hot temperature of 45° Celsius:
    * __Fahrenheit temperature = (Celsius temperature x 1.8) + 32
    Fahrenheit temperature = (45 x 1.8) + 32
    Fahrenheit temperature = 81 + 32
    Fahrenheit temperature = 113° F__

## The remarkable points of temperatures
There is a temperature where Fahrenheit and Celsius have the same value, it is -40°. Indeed, __-40° Celsius is equivalent to -40° Fahrenheit__. As we have seen before, __the melting point of ice is also an important benchmark with 0° C and 32° F__. Finally, another benchmark, __the boiling point of water at pressure is equivalent to 100° C for 212° F__.

## Read from standard input
[(Back to top)](#table-of-contents)

* __Basic Input/Output__
    * C++ uses a convenient abstraction called streams to perform input and output operations in sequential media such as the screen, the keyboard or a file. A stream is an entity where a program can either insert or extract characters to/from. There is no need to know details about the media associated to the stream or any of its internal specifications. All we need to know is that streams are a source/destination of characters, and that these characters are provided/accepted sequentially (i.e., one after another).
    * The standard library defines a handful of stream objects that can be used to access what are considered the standard sources and destinations of characters by the environment where the program runs:

        stream | descrinption |
        ------ | ------------ |
        cin | standard intput stream |
        cout | standard output stream |
        cerr | standard error (output) stream |
        clog | standard logging (output) stream |

    * We are going to see in more detail only cout and cin (the standard output and input streams).


* __Standard output (cout)__
[(Back to top)](#table-of-contents)

    * On most program environments, the standard output by default is the screen, and the C++ stream object defined to access it is cout.
    For formatted output operations, __cout__ is used together with the __insertion operator__, which is written as __<<__ (i.e., two "less than" signs).
        * ```
            std::cout << "Output sentence"; // prints Output sentence on screen
            std::cout << 120;               // prints number 120 on screen
            std::cout << x;                 // prints the value of x on screen
            ```
    * The __<< operator__ inserts the data that follows it into the stream that precedes it. In the examples above, it inserted the literal string Output sentence, the number 120, and the value of variable x into the standard output stream cout. Notice that the sentence in the first statement is enclosed in double quotes (") because it is a string literal, while in the last one, x is not. The double quoting is what makes the difference; when the text is enclosed between them, the text is printed literally; when they are not, the text is interpreted as the identifier of a variable, and its value is printed instead. For example, these two sentences have very different results:
        * ```
            cout << "Hello";  // prints Hello
            cout << Hello;    // prints the content of variable Hello
            ```
    
    *   __Multiple insertion operations (<<) may be chained in a single statement__:
        * ```
            cout << "This " << " is a " << "single C++ statement";
            ```
    * This last statement would print the text This is a single C++ statement. __Chaining insertions__ is especially useful to mix literals and variables in a single statement:
        * ```
            cout << "I am " << age << " years old and my zipcode is " << zipcode;
            ```
* __Standard input (cin)__
[(Back to top)](#table-of-contents)

    * In most program environments, the standard input by default is the keyboard, and the C++ stream object defined to access it is __cin__.
    For formatted __input operations__, __cin__ is used together with the __extraction operator__, which is written as __>>__ (i.e., two "greater than" signs). This __operator__ is then followed by the variable where the extracted data is stored. For example:
        * ```
            int age;
            cin >> age;
            ```
        * The first statement declares a variable of type int called age, and the second __extracts from cin__ a value to be stored in it. This operation makes the program wait for input from __cin__; __generally, this means that the program will wait for the user to enter some sequence with the keyboard.__ In this case, note that the characters introduced using the __keyboard are only transmitted to the program when the ENTER (or RETURN) key is pressed__. Once the statement with the extraction operation on __cin is reached__, the program will __wait for as long as needed until some input is introduced__.

    * __The extraction operation__ on __cin__ uses the type of the variable after the __>> operator__ to determine how it interprets the characters read from the input; if it is an integer, the format expected is a series of digits, if a string a sequence of characters, etc.
        * example : 
            ```
            // i/o example

            #include <iostream>
            using namespace std;

            int main ()
            {
                int i;
                cout << "Please enter an integer value: ";
                cin >> i;
                cout << "The value you entered is " << i;
                cout << " and its double is " << i*2 << ".\n";
                return 0;
            }
            ```
        * Output :
            ```
            Please enter an integer value: 702
            The value you entered is 702 and its double is 1404.
            ```
        * As you can see, extracting from __cin__ seems to make the task of getting input from the standard input pretty simple and straightforward. But this method also has a big drawback. What happens in the example above if the user enters something else that cannot be interpreted as an integer? Well, in this case, the extraction operation fails. And this, by default, lets the program continue without setting a value for variable i, producing undetermined results if the value of i is used later.

        
        
    

## Padding
[(Back to top)](#table-of-contents)

* for set a paading we use : __std::setw(int n)__.
    * Set field width
    * Sets the field width to be used on output operations.
    * Behaves as if member width were called with n as argument on the stream on which it is inserted/extracted as a manipulator (it can be inserted/extracted on input streams or output streams).
    * This manipulator is declared in header __\<iomanip>__.
* code :
    ```
    // setw example
    #include <iostream>     // std::cout, std::endl
    #include <iomanip>      // std::setw

    int main () {
    std::cout << std::setw(10);
    std::cout << 77 << std::endl;
    return 0;
    }
    ```
    Output :
    ```
            77
    ```

## Precision to the 1000th.
[(Back to top)](#table-of-contents)

* For manage precision we can use __std::cout.precision(int n)__, but there are other alternatives).
    * std::ios_base::precision
        * streamsize precision() const; (1)
        streamsize precision( streamsize new_precision ); (2)
    * Manages the precision (i.e. how many digits are generated) of floating point output performed by std::num_put::do_put.
        1) Returns the current precision.
        2) Sets the precision to the given one. Returns the previous precision.
        The default precision, as established by std::basic_ios::init, is 6.
    * example : 
        ```
        #include <iostream>
        int main()
        {
            const double d = 1.2345678901234;
            std::cout << "The  default precision is " << std::cout.precision() << "\n\n";
            std::cout << "With default precision d is " << d << '\n';
            std::cout.precision(12);
            std::cout << "With high    precision d is " << d << '\n';
        }
        ```
        output :
        ```
        The  default precision is 6
        With default precision d is 1.23457
        With high    precision d is 1.23456789012
        ```

# Installation
[(Back to top)](#table-of-contents)

* After downloaded the project and gone to the root path SimpleCatCommand repository you can use the __Makefile__ for compile the program or the units tests and generate a bynary:
    * ```
        make
        ```
    or for the unit_tests :
    * ```
        make tests_run
        ```
## How To Use
[(Back to top)](#table-of-contents)

* To clone and run this application from your command line : 

```bash
# Clone this repository
$ git clone https://github.com/P4r4dis/Temperature_Conversion.git

# Go into the repository
$ cd Temperature_Conversion

# start Makefile for compilation and generate binary
$ make
# Or start Makefile for unit_tests
$ make tests_run


# Use binary
$ ./my_convert_temp
# Example
    $> ./my_convert_temp
    -10 Celsius
    EOF
                14.000      Fahrenheit
    $> ./my_convert_temp
    46.400 Fahrenheit
                8.000         Celsius
    EOF

```
