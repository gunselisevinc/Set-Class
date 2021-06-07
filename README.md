# Set-Class
Operator Overload Project
Main purpose of this project is to implement a generic Set class. This Set will contain several elements of the same kind. The user of the Set class defines the type of elements when a new set object is instantiated. Therefore, the type of elements will be determined at runtime (such as int, float, char, etc.).

The Set class has three private data members:
1. An array to store the elements of the sets.
2. An integer value to store the capacity of the array which can be determined whencreating a new set object. The default value is 10 if the capacity is not specified.
3. An integer value to store the number of items in the array.

## Constructor, copy constructor and destructor for the Set class are implemented with 2 extra member functions:
### addElement
Add an element to the set object. If the element is already in the set object, then DONOT add it.
### removeElement
Return false only if the element is not in the set object. Otherwise, remove that element from the set object and then return true.

## Following operators are overloaded:
### operator+
Return the union of the left set and the right set.
### operator-
Return the difference of the left set from the right set
### operator==
Compare the two sets and return true if they are the same. Otherwise, return false. Note that two sets are equal if every element of one set is also the element of the other regardless of the internal order of elements in their representation.
### operator!=
Compare the two sets and return true if they are not the same. Otherwise, return false.
### operator=
Middle East Technical University Northern Cyprus CampusCopy the contents of the right set to the left set. After this operation, both sets shouldhave only the elements of the right set.
### operator+=
Perform the union of two sets and store the result in set which is at the left hand side ofthe equality. Also return the union of the two sets.
### operator<
Return true only if the set on the left is a subset of the set on the right. Otherwise, returnfalse.
### operator<<
Output the contents of the set.
### operator>>
Fill in the empty places in the set so that the number of elements in the set is equal to the capacity of the set.
