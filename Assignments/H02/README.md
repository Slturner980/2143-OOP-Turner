## H02

- Name: Sarah Turner
- Date: 22 Sep 2020
- Class: 2143 OOP

## Definitions

#### Abstraction
> Knowing how use or work with items but not needing to know 
> how it truly works.
>
> Ex.) Most machines, Programming libraries / functions 

#### Attributes / Properties
> Relates to characteristics of a class.
>
> Ex.) Class methods, varibles, functions.


#### Class
> Group of functions with common properties, varibles, and operations
> to do more complex problems.
>
>   -Defaults methods and varibles to private
>
> Ex.) Class ClassName{
>       private: ...
>       pubilc: ...
>   }

#### Class Variable
> Static variables are declared with the static keyword in a class, but outside a method,
> constructor or a block. No matter how many objects are made, there's only one. 
>
> Ex.)
> class Variable{
>   int num;
>  static int data = ...;}

#### Composition
> Classes that reference one or more objects of other classes in instance variables.
> Makes simple types to make more complex ones.
>
> Ex.) 
> Animal:
>    Skin animalSkin
>    Organs animalOrgans
>
> Mammal:
>    private Animal _animalRef
>    Hair/fur mammalFur
>    warm-blooded-based_cirulation_system heartAndStuff
>

#### Encapsulation
> Binds together the data and functions that manipulate the data, 
> and that keeps both safe from outside interference.
>
> Ex.) Classes

#### Friends
> Classes can access private and protected members of other class.
>
> Ex.) friend friendName(){}

#### Inheritance
> Capability of a class to derive properties and characteristics from another class.
>
> Ex.)
> ![Inheritance Ex](https://github.com/Slturner980/Images/blob/master/inheritance2.png)

#### Instance Variable
> Tied to the particular object instance of the class,
> making them independent from one another.
>
> Ex.) Class className{
>       int Class var 
>       function(){
>           -- int Instance var
>       }
> }

#### Member Variable
>  Function and Variable that is part of a class.
>
> Ex.) Class className{
>       int Class var 
>      -- function(){
>            int Instance var
>           }
>       }

#### Method
> Different way of saying function in classes.
>
>Ex.) Class className{
>      -- function(){
>            int Instance var
>           }
>       }

#### Multiple Inheritance
> Classes can inherit from more than one other classes.


#### Object
> Abstract data type created by a developer. 
> It can include multiple properties
>
> Ex.) Struts, Classes.

#### Overloading
> The reuse of the same symbol or function name for 
> two or more distinct operations or functions.
>
>Ex.) Adding Matrixes together, custom cout statements

#### Polymorphism
> Ability of any data to be processed in more than one form.\
>
> Ex.) Overloaded Functions;
>

#### Public / Private / Protected
> Public - Anyone can use the variables/Functions
>
> Private - No one but the author can use variables/Functions
>
> Protected - Same as Private but child classes can use variables/Functions

#### Virtual
> A member function which is declared within a base class and is re-defined
> (Overriden) by a derived class. 
