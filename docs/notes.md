

---

**enum**

- An enum (short for enumeration) in C is a user-defined data type that consists of a set of named integer constants. 
- It allows you to assign descriptive names to numbers, making your code significantly more readable and easier to maintain.
- Core CharacteristicsInteger Representation: 
    - Internally, enum members are treated as integers.
    - Automatic Value Assignment: By default, the first member is assigned 0, the second is 1, and so on.
    - Custom Values: You can manually override these default values during declaration.
    - Scope: Unlike macros (#define), enums follow C's standard scoping rules, which helps prevent name conflicts.

    Syntax Example:
    
        You define an enum using the enum keyword followed by its name and a list of constants:

        enum Level {
            LOW,    // defaults to 0
            MEDIUM, // defaults to 1
            HIGH    // defaults to 2
        };

        // Creating a variable of the enum type
        enum Level myStatus = MEDIUM; 
